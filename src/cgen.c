#include "stdio.h"
#include "util.h"
#include <assert.h>
#include "globals.h"
#include "constTab.h"
#include "symbol.h"
#include "optimize.h"

#define t0 "$t0"
#define t1 "$t1"
#define t2 "$t2"
#define t3 "$t3"
#define t4 "$t4"
#define t5 "$t5"
#define t6 "$t6"
#define t7 "$t7"

typedef enum{
    I32,
    I8,
    F32
    // STR
} TypeVar;

typedef struct {
    char id[20];
    TypeVar type;
} tacVal;
// TODO: record and array function return

static symbolNode *cur_domain = NULL;
static int labelNum = 0;

static inline tacVal newTac(char *id, TypeVar t)
{
    tacVal r;
    strcpy(r.id, id);
    r.type = t;
    return r;
}
static tacVal bfalse = {{'0','\0'}, I8};
static tacVal btrue = {{'1','\0'}, I8};
static tacVal izero = {{'0','\0'}, I32};

FILE *IR;

static void genStmtList(TreeNode *tree);
static void genFunc(TreeNode *tree, char *fatherFuncLabel);

//static tacVal genTacVal(char *id, TypeVar type)
//{
//    tacVal t;
//    assert(strlen(id) < 20);
//    strcpy(t.id, id);
//    t.type = type;
//    return t;
//}

static inline char *getValTypeStr(TypeVar t)
{
    switch(t)
    {
        case I32: return "i32";
        case I8: return "i8";
        case F32: return "f32";
        // case STR: return "str";
    }
    return NULL;
}

static void emitCode(char*op, tacVal op1, tacVal op2, tacVal op3)
{
    fprintf(IR, "%s %s %s %s %s %s %s\n", op,
        getValTypeStr(op1.type), op1.id,
        getValTypeStr(op2.type), op2.id,
        getValTypeStr(op3.type), op3.id);
}

static char *getNaiveK(TreeNode *tree, TypeVar *varType)
{
    char *varId = NULL;
    if ( isIdK(tree) )
    {
        varId = tree->tokenString;
        if (tree->type == Integer)
            *varType = I32;
        else if (tree->type == Real)
            *varType = F32;
        else if (tree->type == Boolean)
            *varType = I8;
        else if (tree->type == Array)
            *varType = I32;
        else if (tree->type == String)
            *varType = I32;
        else if (tree->type == Char)
            *varType = I8;
        else if (tree->type == Record)
            *varType = I32; // address
    }
    else if ( isConstValK(tree) )
    {
        if (tree->type == Integer) {
            *varType = I32;
            varId = tree->tokenString;
        }
        else if (tree->type == Real) {
            *varType = F32;
            varId = m_ftoa(atof(tree->tokenString));
        }
        else if (tree->type == Boolean) {
            *varType = I8;
            if (strcmp(tree->tokenString, "true")==0)
                varId = "1";
            else
                varId = "0";
        }
    }
    else if ( isCharK(tree) )
    {
        *varType = I8;
        varId = m_itoa((int)(tree->tokenString[1]));
    }
    return varId;
}

static void genExp( TreeNode *tree, TypeVar *varType, char *varId )
{
    TreeNode *p1, *p2;
    // char *varId = t0;
    assert( isExpK(tree) );
    // O0(tree);
    // use function returns to avoid MACRO definition
    // (to avoid design complication/duplication)
    if ( isOpK(tree) )
    {
        TypeVar tp1, tp2;   // type of cur node
        p1 = tree->child;
        p2 = p1->sibling;

        char *id1, *id2;

        id1 = getNaiveK(p1, &tp1);
        id2 = getNaiveK(p2, &tp2);

        if(!id1) {genExp(p1, &tp1, t0); id1 = t0;}
        if(!id2) {genExp(p2, &tp2, t1); id2 = t1;}


        tacVal op1 = newTac(id1, tp1), op2 = newTac(id2, tp2), op3 = newTac(varId, tp1);

        if (tree->type == Boolean)
        {
            tacVal tmp0 = newTac(t0, I8);
            op3.type = I8; *varType = I8;
            switch( tree->nodekind )
            {
                case N_EXP_GE:
                    emitCode("lt", op1, op2, tmp0);
                    emitCode("eq", tmp0, bfalse, op3);
                    break;
                case N_EXP_GT:
                    emitCode("lt", op2, op1, op3);
                    break;
                case N_EXP_LE:
                    emitCode("lt", op2, op1, tmp0);
                    emitCode("eq", tmp0, bfalse, op3);
                    break;
                case N_EXP_LT:
                    emitCode("lt", op1, op2, op3);
                    break;
                case N_EXP_EQUAL:
                    emitCode("eq", op1, op2, op3);
                    break;
                case N_EXP_UNEQUAL:
                    emitCode("eq", op1, op2, tmp0);
                    emitCode("xor", tmp0, btrue, op3);
                    break;
                case N_EXP_OR:
                    emitCode("or", op1, op2, op3);
                    break;
                case N_EXP_AND:
                    emitCode("and", op1, op2, op3);
                    break;
                default:
                    assert(0);
            }
        }
        else if (tree->type == Integer)
        {
            op3.type = I32;
            *varType = I32;
            switch( tree->nodekind )
            {
                case N_EXP_PLUS:
                    emitCode("add", op1, op2, op3);
                    break;
                case N_EXP_MINUS:
                    emitCode("sub", op1, op2, op3);
                    break;
                case N_EXP_OR:
                    emitCode("or", op1, op2, op3);
                    break;
                case N_EXP_AND:
                    emitCode("and", op1, op2, op3);
                    break;
                case N_EXP_MUL:
                    emitCode("mul", op1, op2, op3);
                    break;
                case N_EXP_DIV:
                    emitCode("div", op1, op2, op3);
                    break;
                case N_EXP_MOD:
                    emitCode("mod", op1, op2, op3);
                    break;
                default:
                    assert(0);
            }   // end: switch
        }
        else if ( tree->type == Real )
        {
            op3.type = F32; *varType = F32;
            switch(tree->nodekind)
            {
                case N_EXP_PLUS:
                    emitCode("fadd", op1, op2, op3);
                    break;
                case N_EXP_MINUS:
                    emitCode("fsub", op1, op2, op3);
                    break;
                case N_EXP_MUL:
                    emitCode("fmul", op1, op2, op3);
                    break;
                case N_EXP_DIV:
                    emitCode("fdiv", op1, op2, op3);
                    break;
                default:
                    assert(0);
            }
        }
        else
            assert(0);  // TODO: string add
    }
    else if ( isRecK(tree) )
    {
        tacVal op3 = newTac(varId, I32);
        p1 = tree->child;
        p2 = p1->sibling;

        symbolNode node = st_lookup(cur_domain, p1->tokenString);
        symbolNode field = st_lookup(node->nextBucket, p2->tokenString);

        if (field->type == Integer)
        {
            *varType = I32;
            op3.type = I32;
        }
        else if (field->type == Real)
        {
            *varType = F32;
            op3.type = F32;
        }
        else if (field->type == Boolean)
        {
            *varType = I8;
            op3.type = I8;
        }
        else
            assert(0);  // string or record or array

        // name of a record represents its address
        tacVal addr = newTac(p1->tokenString, I32);
        char _ofs[20];
        sprintf(_ofs, "%d", field->memloc);
        tacVal offs = newTac(_ofs, I32);
        tacVal loc = newTac(t0, I32);
        emitCode("add", addr, offs, loc);
        fprintf(IR, "load %s %s %s\n", loc.id, getValTypeStr(op3.type), t0);
        fprintf(IR, "asn %s %s %s %s\n",
                            getValTypeStr(op3.type), t0,
                            getValTypeStr(op3.type), op3.id );
    }
    else if ( isArrK(tree) )
    {
        TypeVar tp;
        tacVal op3 = newTac(varId, I32);
        p1 = tree->child;
        p2 = p1->sibling;
        tacVal addr = newTac(p1->tokenString, I32);

        char *offsId;
        offsId = getNaiveK(p2, &tp);
        if (!offsId) {genExp(p2, &tp, t0); offsId = t0;}

        tacVal offs = newTac(offsId, I32);

        assert(tp == I32);
        if (tree->type == Boolean)
        {
            *varType = I8;
            op3.type = I8;
        }
        else if (tree->type == Integer)
        {
            *varType = I32;
            op3.type = I32;
        }
        else if (tree->type == Real)
        {
            *varType = F32;
            op3.type = F32;
        }
        else
            assert(0);  // array of array or record

        tacVal loc = newTac(t1, I32);
        emitCode("add", addr, offs, loc);
        fprintf(IR, "load %s %s %s\n", loc.id, getValTypeStr(op3.type), t1);
        fprintf(IR, "asn %s %s %s %s\n",
                            getValTypeStr(op3.type), t1,
                            getValTypeStr(op3.type), op3.id );
    }
    // function call
    else if ( isCallK(tree) )
    {
        if (tree->type == Integer)
            *varType = I32;
        else if(tree->type == Real)
            *varType = F32;
        else if(tree->type == Boolean ||tree->type == Char)
            *varType = I8;
        else if(tree->type == Record)
            *varType = I32;
        else
            assert(0);
        p1 = tree->child;
        p2 = p1->sibling;

        TreeNode *p_arg = p2->child;
        while (p_arg)
        {
            TypeVar tp;
            char *argId;
            if( !(argId = getNaiveK(p_arg->child, &tp) ) )
                {genExp(p_arg->child, &tp, t0); argId = t0;}
            tacVal arg = newTac(argId, tp);
            fprintf(IR, "arg %s %s\n", getValTypeStr(tp), arg.id);
            p_arg = p_arg->sibling;
        }
        fprintf(IR, "call %s %s %s\n", p1->tokenString,
                getValTypeStr(*varType), varId);
    }
    // not factor
    else if ( isNotFacK(tree) )
    {
        assert(tree->type == Boolean);
        *varType = I8;
        tacVal op3 = newTac(varId, I8);

        p1 = tree->child;
        p2 = p1->sibling;

        TypeVar tp;
        char *exprId;
        if(!(exprId = getNaiveK(p2, &tp)))
            { genExp(p2, &tp, t0); exprId = t0;}
        assert(tp == I8);
        tacVal expr = newTac(exprId, tp);
        emitCode("eq", expr, bfalse, op3);
    }
    // minus factor
    else if ( isRevFacK(tree) )
    {
        tacVal op3 = newTac(varId, I32);
        TypeVar tp;
        p1 = tree->child;
        p2 = p1->sibling;
        char *exprId;
        if(!(exprId = getNaiveK(p2, &tp)))
            { genExp(p2, &tp, t0); exprId = t0;}
        tacVal expr = newTac(exprId, tp);
        if (tree->type == Integer)
        {
            op3.type = I32;
            *varType = I32;
            emitCode("sub", izero, expr, op3);
        }
        else if (tree->type == Real)
        {
            op3.type = F32;
            *varType = F32;
            emitCode("fsub", izero, expr, op3);
        }
    }
    else if ( isStringK(tree) )
    {
        // return string address on varId
        // genStmt handle memcpy() for string assignment
        // Strings should be assigned a label and put into the const area
        char label[32];
        *varType = I32;
        sprintf(label, "_$CONST$_L%d\n", ct_count);
        fprintf(IR, "asn i32 %s i32 %s _\n", label, varId);
        ct_insert_str(tree->tokenString, label);
    }
    else
    {
        assert(0);
    }
}

int assignStmtCheck(TreeNode *stmt) {
    TreeNode *id_1 = stmt->child;
    // assign_stmt: ID DOT ID ASSIGN expression
    if (id_1->sibling->nodekind == N_ID)
        return 3;
    TreeNode *exp_1 = id_1->sibling;
    // ID ASSIGN expression
    if (exp_1->sibling == NULL)
        return 1;
    // ID LB expression RB ASSIGN expression
    return 2;
}

int procStmtCheck(TreeNode *stmt) {
    switch (stmt->child->nodekind) {
        case N_ID:
        {
            TreeNode *id = stmt->child;
            // proc_stmt: ID
            if (id->sibling == NULL)
                return 1;
            // proc_stmt: ID LP args_list RP
            return 2;
            break;
        }
        case N_SYS_PROC:
        {
            TreeNode *sys_proc = stmt->child;
            // proc_stmt: SYS_PROC
            if (sys_proc->sibling == NULL)
                return 3;
            // proc_stmt: SYS_PROC LP expression_list RP
            return 4;
            break;
        }
        case N_READ:
            // proc_stmt: READ LP factor RP
            return 5;
            break;
        default:
            assert(0);
    }
}

static void genStmt(TreeNode *tree) {
    NodeKind type = tree->nodekind;
    // TODO trace
    switch (type) {
        case N_ASSIGN_STMT:
            // assign
            switch (assignStmtCheck(tree)) {
                // ID ASSIGN expression
                case 1: {
                    TreeNode *id = tree->child;
                    TreeNode *exp = id->sibling->child;
                    TypeVar tp;
                    char *exprId;
                    if (!(exprId = getNaiveK(exp, &tp)))
                        { genExp(exp, &tp, t0); exprId = t0;}
                    if (id->type == Integer)
                    {
                        assert(tp == I32);
                        fprintf(IR, "asn i32 %s i32 %s\n", exprId, id->tokenString);
                    }
                    else if (id->type == Real)
                    {
                        if (tp == I32)
                            fprintf(IR, "asn i32 %s f32 %s\n", exprId, id->tokenString);
                        else
                            fprintf(IR, "asn f32 %s f32 %s\n", exprId, id->tokenString);
                    }
                    else if (id->type == Boolean)
                    {
                        assert(tp == I8);
                        fprintf(IR, "asn i8 %s i8 %s\n", exprId, id->tokenString);
                    }
                    else if (id->type == Char)
                    {
                        assert(tp == I8);
                        fprintf(IR, "asn i8 %s i8 %s\n", exprId, id->tokenString);
                    }
                    else if (id->type == Array)
                    {
                        // TODO:
                        assert(0);
                    }
                    else if (id->type == String)
                    {
                        assert(tp == I32);
                        fprintf(IR, "asn_str i32 %s str %s\n", exprId, id->tokenString);
                        // assert(0);
                    }
                    else if (id->type == Record)
                    {
                        // TODO:
                        assert(0);
                    }
                    else
                        assert(0);
                    // fprintf(IR, "asn %s %s _\n", res1, id->tokenString);
                    break;
                }
                // ID LB expression RB ASSIGN expression
                case 2: {
                    // assert(tree->type == Array);
                    TreeNode *id = tree->child;
                    TreeNode *exp_1 = id->sibling->child;
                    TreeNode *exp_2 = id->sibling->sibling->child;
                    TypeVar offsTp, exprTp;
                    char *offsId, *exprId;
                    if (!(offsId = getNaiveK(exp_1, &offsTp)))
                        { genExp(exp_1, &offsTp, t0); offsId = t0;}
                    if (!(exprId = getNaiveK(exp_2, &exprTp)))
                        { genExp(exp_2, &exprTp, t1); exprId = t1;}
                    fprintf(IR, "add i32 %s i32 %s i32 %s\n", id->tokenString, offsId, t0);
                    if (tree->type == Integer)
                    {
                        // fprintf(IR, "asn i32 %s i32 $t1\n", exprId);
                        fprintf(IR, "store i32 %s %s\n", exprId, t0);
                    }
                    else if (tree->type == Real)
                    {
                        if (exprTp == I32) {
                            fprintf(IR, "asn i32 %s f32 %s\n", exprId, t1);
                            fprintf(IR, "store f32 %s %s\n", t1, t0);
                        }
                        else if (exprTp == F32) {
                            fprintf(IR, "store f32 %s %s\n", exprId, t0);
                            // fprintf(IR, "asn f32 %s f32 *$t0\n", exprId);
                        }
                    }
                    else if (tree->type == Boolean)
                        fprintf(IR, "store i8 %s $t0\n", exprId);
                    else if (tree->type == Char)
                        fprintf(IR, "store i8 %s $t0\n", exprId);
                    else if (tree->type == Array)
                        assert(0); // TODO
                    else if (tree->type == Record)
                        assert(0); // TODO
                    else if (tree->type == String)
                    {
                        assert(0);
                        // fprintf(IR, "store i32 %s str %s\n", exprId, id->tokenString);
                    }
                    else
                        assert(0);

                    // fprintf(IR, "asn %s %s _\n", id->tokenString, t0);
                    // fprintf(IR, "add %s %s %s\n", t0, res2, t0);
                    // fprintf(IR, "asn %s *%s _\n", res1, t0);
                    break;
                }
                // assign_stmt: ID DOT ID ASSIGN expression
                case 3: {
                    TypeVar exprTp;
                    TreeNode *id_1 = tree->child;
                    TreeNode *id_2 = id_1->sibling;
                    TreeNode *exp = id_2->sibling->child;
                    char *exprId;
                    if (!(exprId = getNaiveK(exp, &exprTp)))
                        { genExp(exp, &exprTp, t1); exprId = t1;}
                    symbolNode node = st_lookup(cur_domain, id_1->tokenString);
                    symbolNode field = st_lookup(node->nextBucket, id_2->tokenString);
                    fprintf(IR, "add i32 %s i32 %d i32 %s\n",
                            id_1->tokenString, field->memloc,t0);
                    if (field->type == Integer)
                        fprintf(IR, "store i32 %s $t0\n", exprId);
                    else if (field->type == Real)
                    {
                        if (exprTp == I32) {
                            fprintf(IR, "asn i32 %s f32 %s\n", exprId, t1);
                            fprintf(IR, "store i32 %s $t0\n", t1);
                        }
                        else if (exprTp == F32)
                            fprintf(IR, "store f32 %s $t0\n", exprId);
                    }
                    else if (field->type == Boolean)
                        fprintf(IR, "store i8 %s $t0\n", exprId);
                    else if (field->type == Char)
                        fprintf(IR, "store i8 %s $t0\n", exprId);
                    else if (field->type == Array)
                        assert(0); // TODO
                    else if (field->type == Record)
                        assert(0); // TODO
                    else if (field->type == String)
                        assert(0);
                    else
                        assert(0);

                    break;
                }
            }
            break;
        case N_PROC_STMT:
            // procedure
            // optimize TODO
            switch (procStmtCheck(tree)) {
                // proc_stmt: ID
                case 1: {
                    TreeNode *id = tree->child;
                    // inline optimize TODO
                    if (!opt_inlineFlag)
                        fprintf(IR, "call %s\n", id->tokenString);
                    break;
                }
                // proc_stmt: ID LP args_list RP
                case 2: {
                    TreeNode *id = tree->child;
                    TreeNode *p = id->sibling->child;
                    while(p)
                    {
                        TypeVar exprTp;
                        char *exprId;
                        if ( !(exprId = getNaiveK(p->child, &exprTp)))
                            { genExp(p->child, &exprTp, t0); exprId = t0;}
                        fprintf(IR, "arg %s %s\n", getValTypeStr(exprTp), exprId);
                        p = p->sibling;
                    }
                    fprintf(IR, "call %s\n", id->tokenString);
                    break;
                }
                // proc_stmt: SYS_PROC
                case 3: {
                    TreeNode *id = tree->child;
                    fprintf(IR, "call %s\n", id->tokenString);
                    break;
                }
                // proc_stmt: SYS_PROC LP expression_list RP
                case 4: {
                    TreeNode *id = tree->child;
                    TreeNode *p = id->sibling->child;
                    while(p)
                    {
                        TypeVar exprTp;
                        char *exprId;
                        if ( !(exprId = getNaiveK(p->child, &exprTp)))
                            { genExp(p->child, &exprTp, t0); exprId = t0;}
                        fprintf(IR, "arg %s %s\n", getValTypeStr(exprTp), exprId);
                        p = p->sibling;
                    }
                    fprintf(IR, "call %s\n", id->tokenString);
                    break;
                }
                // proc_stmt: READ LP factor RP
                case 5: {
                    // TODO
                    // NOTE: read record?
                    TreeNode *id = tree->child;
                    TreeNode *argId = id->sibling;
                    if (argId->type == String)
                        assert(0);
                    else
                        fprintf(IR, "arg i32 &%s\n", argId->tokenString);
                    fprintf(IR, "call read\n");
                    break;
                }
            }
            break;
        case N_COMPOUND_STMT:
            // compound
            genStmtList(tree);
            break;
        case N_IF_STMT: {
            // compound
            TreeNode *exp = tree->child->child;
            TreeNode *stmt = tree->child->sibling;
            TreeNode *else_clause = stmt->sibling;
            TypeVar exprTp;
            char *exprId;
            if ( !(exprId = getNaiveK(exp, &exprTp)))
                { genExp(exp, &exprTp, t0); exprId = t0;}

            int L1 = labelNum++;
            fprintf(IR, "if_f i8 %s _$JMP$_L%d\n", exprId, L1);
            genStmt(stmt->child);
            if (else_clause->child == NULL) {
                fprintf(IR, "_$JMP$_L%d\n", L1);
            }
            else {
                int L2 = labelNum++;
                fprintf(IR, "jmp _$JMP$_L%d\n", L2);
                fprintf(IR, "_$JMP$_L%d\n", L1);
                genStmt(else_clause->child);
                fprintf(IR, "_$JMP$_L%d\n", L2);
            }
            break;
        }
        case N_REPEAT_STMT: {
            // repeat
            TreeNode *stmt_list = tree->child;
            TreeNode *exp = stmt_list->sibling->child;
            int L1 = labelNum++;
            fprintf(IR, "_$JMP$_L%d\n", L1);
            genStmtList(stmt_list);
            TypeVar exprTp;
            char *exprId;
            if ( !(exprId = getNaiveK(exp, &exprTp)))
                { genExp(exp, &exprTp, t0); exprId = t0;}
            fprintf(IR, "if_f i8 %s _$JMP$_L%d\n", exprId, L1);
            break;
        }
        case N_WHILE_STMT: {
            // while
            TreeNode *exp = tree->child->child;
            TreeNode *stmt = tree->child->sibling;
            TypeVar exprTp;
            char *exprId;
            int L1 = labelNum++;
            fprintf(IR, "_$JMP$_L%d\n", L1);
            if ( !(exprId = getNaiveK(exp, &exprTp)))
                { genExp(exp, &exprTp, t0); exprId = t0;}
            int L2 = labelNum++;
            fprintf(IR, "if_f i8 %s _$JMP$_L%d\n", exprId, L2);
            genStmtList(stmt->child);
            fprintf(IR, "jmp _$JMP$_L%d\n", L1);
            fprintf(IR, "_$JMP$_L%d\n", L2);
            break;
        }
        case N_FOR_STMT: {
            // for
            TreeNode *id = tree->child;
            TreeNode *exp1 = id->sibling->child;
            TreeNode *direct = id->sibling->sibling;
            TreeNode *exp2 = direct->sibling->child;
            TreeNode *stmt = direct->sibling->sibling;
            int L1 = labelNum++;
            int L2 = labelNum++;
            TypeVar exprTp1, exprTp2;
            char *exprId1;
            if ( !(exprId1 = getNaiveK(exp1, &exprTp1)))
                { genExp(exp1, &exprTp1, t0); exprId1 = t0;}
            char *exprId2;
            if ( !(exprId2 = getNaiveK(exp2, &exprTp2)))
                { genExp(exp2, &exprTp2, t0); exprId2 = t0;}
            fprintf(IR, "asn i32 %s i32 %s\n", exprId1, id->tokenString);
            fprintf(IR, "_$JMP$_L%d\n", L1);
            if (direct->nodekind == N_TO) {
                fprintf(IR, "lt i32 %s i32 %s i8 %s\n", exprId2, id->tokenString, t0);
                fprintf(IR, "eq i8 %s i8 0 i8 %s\n", t0, t0); // bt -> 1 == 0 = 0 -> jump
                // fprintf(IR, "add i32 %s i32 1 i32 %s\n", id->tokenString, id->tokenString);
            }
            else if (direct->nodekind == N_DOWNTO) {
                fprintf(IR, "lt i32 %s i32 %s i8 %s\n", id->tokenString, exprId2, t0);
                fprintf(IR, "eq i8 %s i8 0 i8 %s\n", t0, t0); // lt -> 1 == 0 = 0 -> jump
                // fprintf(IR, "sub i32 %s i32 1 i32 %s\n", id->tokenString, id->tokenString);
            }
            fprintf(IR, "if_f i8 %s _$JMP$_L%d\n", t0, L2);
            genStmt(stmt->child);
            if (direct->nodekind == N_TO) {
                fprintf(IR, "add i32 %s i32 1 i32 %s\n", id->tokenString, id->tokenString);
            }
            else if (direct->nodekind == N_DOWNTO) {
                fprintf(IR, "sub i32 %s i32 1 i32 %s\n", id->tokenString, id->tokenString);
            }
            fprintf(IR, "jmp _$JMP$_L%d\n", L1);
            fprintf(IR, "_$JMP$_L%d\n", L2);
            break;
        }
        case N_CASE_STMT: {
            // case
            TreeNode *exp = tree->child->child;
            TreeNode *case_list = tree->child->sibling;
            TreeNode *case_expr = case_list->child;
            int L2 = labelNum++;
            int L1;
            TypeVar exprTp;
            char *exprId;
            if ( !(exprId = getNaiveK(exp, &exprTp)))
                { genExp(exp, &exprTp, t0); exprId = t0;}
            while (case_expr != NULL) {
                TreeNode *ch1 = case_expr->child;
                L1 = labelNum++;
                // case_expr: ID COLON stmt SEMI
                if (ch1->nodekind == N_ID) {
                    fprintf(IR, "eq i32 %s i32 %s i8 %s\n", exprId, ch1->tokenString, t0);
                    fprintf(IR, "if_f i8 %s _$JMP$_L%d\n", t0, L1);
                }
                // case_expr: const_value COLON stmt SEMI
                else {
                    TypeVar constTp;
                    char *constId;
                        if ( !(constId = getNaiveK(exp, &constTp)))
                            { genExp(exp, &constTp, t0); constId = t0;}
                    fprintf(IR, "eq i32 %s i32 %s i8 %s\n", constId, ch1->tokenString, t0);
                    fprintf(IR, "if_f i8 %s _$JMP$_L%d\n", t0, L1);
                }
                case_expr = case_expr->sibling;
            }
            L1 = L2;
            case_expr = case_list->child;
            while (case_expr != NULL) {
                TreeNode *ch1 = case_expr->child;
                L1++;
                fprintf(IR, "_$JMP$_L%d\n", L1);
                genStmt(ch1->sibling->child);
                fprintf(IR, "jmp _$JMP$_L%d\n", L2);
                case_expr = case_expr->sibling;
            }
            fprintf(IR, "_$JMP$_L%d\n", L2);
            break;
        }
        case N_GOTO_STMT: {
            // goto
            // TreeNode *inte = tree->child;
            // TODO
            // fprintf(IR, "jmp %s\n", );
            break;
        }
        default:
            assert(0);
    }
}

static void genStmtList(TreeNode *tree) {
    TreeNode *stmt = tree->child;
    while (stmt != NULL) {
        genStmt(stmt->child);
        stmt = stmt->sibling;
    }
}

static void genProc(TreeNode *tree, char *fatherFuncLabel)
{
    assert(tree->nodekind == N_PROCEDURE_DECL);
    TreeNode *id = tree->child->child;
    TreeNode *routine_head = tree->child->sibling->child;
    TreeNode *stmt_list = routine_head->sibling;
    char funcLabel[100];
    sprintf(funcLabel, "%s$%s", fatherFuncLabel, id->tokenString);
    symbolNode proc = st_lookup(cur_domain, id->tokenString);

    cur_domain = proc->nextBucket;

    TreeNode *p = routine_head->child->sibling->sibling->sibling->sibling->child;
    while(p)
    {
        switch(p->nodekind)
        {
            case N_FUNCTION_DECL:
                genFunc(p, funcLabel);
                break;
            case N_PROCEDURE_DECL:
                genProc(p, funcLabel);
                break;
            default:
                assert(0);
        }
        p = p->sibling;
    }
    fprintf(IR, "%s$%s\n", fatherFuncLabel, id->tokenString);
    genStmtList(stmt_list);
    fprintf(IR, "ret\n");
    cur_domain = cur_domain[BUCKET_SIZE]->nextBucket;
}

static void genFunc(TreeNode *tree, char *fatherFuncLabel) {
    assert(tree->nodekind == N_FUNCTION_DECL);
    TreeNode *id = tree->child->child;
    TreeNode *routine_head = tree->child->sibling->child;
    TreeNode *stmt_list = routine_head->sibling;
    char funcLabel[100];
    sprintf(funcLabel, "%s$%s", fatherFuncLabel, id->tokenString);
    symbolNode func = st_lookup(cur_domain, id->tokenString);

    cur_domain = func->nextBucket;

    TreeNode *p = routine_head->child->sibling->sibling->sibling->sibling->child;
    while(p)
    {
        switch(p->nodekind)
        {
            case N_FUNCTION_DECL:
                genFunc(p, funcLabel);
                break;
            case N_PROCEDURE_DECL:
                genProc(p, funcLabel);
                break;
            default:
                assert(0);
        }
        p = p->sibling;
    }

    fprintf(IR, "%s$%s\n", fatherFuncLabel, id->tokenString);
    genStmtList(stmt_list);
    fprintf(IR, "ret\n");
    cur_domain = cur_domain[BUCKET_SIZE]->nextBucket;
}

static void genConst()
{
    fprintf(IR, ".data\n");
    ct_genConst();
}

void codeGen( TreeNode *syntaxTree)
{
    cur_domain = buckets;
    assert(syntaxTree->nodekind == N_PROGRAM);

    TreeNode *routine_part = syntaxTree->child->sibling->child->child->sibling->sibling->sibling->sibling;
    assert(routine_part->nodekind == N_ROUTINE_PART);

    fprintf(IR, "_$MAIN$_: \n");
    genStmtList(syntaxTree->child->sibling->child->sibling);

    TreeNode *p = routine_part->child;
    while(p)
    {
        switch(p->nodekind)
        {
            case N_FUNCTION_DECL:
                genFunc(p, "_$FUNC");
                break;
            case N_PROCEDURE_DECL:
                genProc(p, "_$PROC");
                break;
            default:
                assert(0);
        }
        p = p->sibling;
    }
    genConst();
}
