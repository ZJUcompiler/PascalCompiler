#include "stdio.h"
#include "util.h"
#include <assert.h>
#include "globals.h"

#define res1 "t7"
#define res2 "t6"
#define t0 "t0"
#define t1 "t1"
#define t2 "t2"
#define t3 "t3"
#define t4 "t4"
#define t5 "t5"
#define L1 "L1"
#define L2 "L2" FILE *IR;

inline int isOpK( TreeNode *tree)
{
    return ((tree->nodekind == N_EXP_GE) ||
            (tree->nodekind == N_EXP_GT) ||
            (tree->nodekind == N_EXP_LE) ||
            (tree->nodekind == N_EXP_LT) ||
            (tree->nodekind == N_EXP_EQUAL) ||
            (tree->nodekind == N_EXP_UNEQUAL) ||
            (tree->nodekind == N_EXP_PLUS) ||
            (tree->nodekind == N_EXP_MINUS) ||
            (tree->nodekind == N_EXP_OR) ||
            (tree->nodekind == N_EXP_MUL) ||
            (tree->nodekind == N_EXP_DIV) ||
            (tree->nodekind == N_EXP_MOD) ||
            (tree->nodekind == N_EXP_AND));
}

inline int isRecK( TreeNode *tree )
{
    return (tree->nChild == 2) && 
            (tree->nodekind == N_FACTOR) &&
            (tree->child->nodekind == N_ID) &&
            (tree->child->sibling->nodekind == N_ID);
}

inline int isArrK( TreeNode *tree )
{
    return (tree->nChild == 2) && 
            (tree->nodekind == N_FACTOR) &&
            (tree->child->nodekind == N_ID) &&
            (tree->child->sibling->nodekind == N_EXPRESSION);
}

inline int isCallK( TreeNode *tree )
{
    return (tree->nChild == 2) && 
            (tree->nodekind == N_FACTOR) &&
            (tree->child->nodekind == N_ID) &&
            (tree->child->sibling->nodekind == N_ARGS_LIST);
}

inline int isNotFacK( TreeNode *tree )
{
    return (tree->nChild == 2) && 
            (tree->nodekind == N_FACTOR) &&
            (tree->child->nodekind == N_NOT) &&
            (tree->child->sibling->nodekind == N_FACTOR);
}

inline int isRevFacK( TreeNode *tree )
{
    return (tree->nChild == 2) && 
            (tree->nodekind == N_FACTOR) &&
            (tree->child->nodekind == N_MINUS) &&
            (tree->child->sibling->nodekind == N_FACTOR);
}

inline int isIdK( TreeNode *tree )
{
    return (tree->nodekind == N_ID);
}

inline int isConstValK( TreeNode *tree )
{
    return (tree->nodekind == N_INTEGER ||
            tree->nodekind == N_REAL ||
            // tree->nodekind == N_CHAR ||
            // tree->nodekind == N_STRING ||
            tree->nodekind == N_SYS_CON);
}

inline int isCharK( TreeNode *tree)
{
    return tree->nodekind == N_CHAR;
}

inline int isStringK( TreeNode *tree)
{
    return tree->nodekind == N_STRING;
}

inline int isExpK( TreeNode *tree )
{
    return isOpK(tree) || isExpK(tree) ||
        isRecK(tree) || isArrK(tree) ||
        isCallK(tree) || isRevFacK(tree) ||
        isNotFacK(tree) || isIdK(tree) ||
        isConstValK(tree) || isCharK(tree) ||
        isStringK(tree);
}

static char *IR;
=======
#include "globals.h"
>>>>>>> 2daa66b92990be1f731bb4b2e06b954b3006af40

#define res1 "t7"
#define res2 "t6"
#define t0 "t0"
#define t1 "t1"
#define t2 "t2"
#define t3 "t3"
#define t4 "t4"
#define t5 "t5"
#define L1 "L1"
#define L2 "L2"

static int labelNum = 0;
// static int label
FILE *IR;

static void genExp( TreeNode *tree, const char *varId )
{
    TreeNode *p1, *p2;
    assert( isExpK(tree) );
    
    // use function returns to avoid MACRO definition
    // (to avoid design complication/duplication)
    if ( isOpK(tree) ) 
    {
        p1 = tree->child;
        p2 = p1->sibling;

        genExp(p1, "t0");

        genExp(p2, "t1");

        // fprintf(IR, "(%s, %s, %s, %s)\n", toOpStr(tree->nodekind), "t0", "t1", varId);
        switch( tree->nodekind )
        {
            case N_EXP_GE: 
                fprintf(IR, "(GE, t0, t1, %s)\n", varId);
                break;
            case N_EXP_GT: 
                fprintf(IR, "(GT, t0, t1, %s)\n", varId);
                break;
            case N_EXP_LE: 
                fprintf(IR, "(LE, t0, t1, %s)\n", varId);
                break;
            case N_EXP_LT: 
                fprintf(IR, "(LT, t0, t1, %s)\n", varId);
                break;
            case N_EXP_EQUAL: 
                fprintf(IR, "(EQ, t0, t1, %s)\n", varId);
                break;
            case N_EXP_UNEQUAL: 
                fprintf(IR, "(NEQ, t0, t1, %s)\n", varId);
                break;
            case N_EXP_PLUS: 
                fprintf(IR, "(ADD, t0, t1, %s)\n", varId);
                break;
            case N_EXP_MINUS:
                fprintf(IR, "(SUB, t0, t1, %s)\n", varId);
                break;
            case N_EXP_OR: 
                fprintf(IR, "(OR, t0, t1, %s)\n", varId);
                break;
            case N_EXP_MUL:
                fprintf(IR, "(MUL, t0, t1, %s)\n", varId);
                break;
            case N_EXP_DIV:
                fprintf(IR, "(DIV, t0, t1, %s)\n", varId);
                break;
            case N_EXP_MOD:
                fprintf(IR, "(MOD, t0, t1, %s)\n", varId);
                break;
            case N_EXP_AND:
                fprintf(IR, "(AND, t0, t1, %s)\n", varId);
                break;
            default:
                assert(0);
        }
    }
    else if ( isRecK(tree) ) 
    {
        // TODO: record access
        // p1 = tree->child;

        // genExp(p1);

        // fprintf(IR, "%s\n", );
    }
    else if ( isArrK(tree) )
    {
        p1 = tree->child;
        p2 = p1->sibling;

        genExp(p1, "t0");
        
        genExp(p2, "t1");

        fprintf(IR, "(ADD, t0, t1, t0)\n");
        fprintf(IR, "(ASN, *t0, %s, _)\n", varId);
    }
    // function call
    else if ( isCallK(tree) )
    {   
        p1 = tree->child;
        p2 = p1->sibling;

        TreeNode *p_arg = p2->child;
        while (p_arg)
        {
            genExp(p_arg, "t0");
            fprintf(IR, "(ARG, t0, _, _)\n");
        }
        assert(strcmp(varId, "$v0")==0);
        fprintf(IR, "(CALL, %s, _, _)\n", tree->tokenString);
    }
    // not factor
    else if ( isNotFacK(tree) )
    {
        p1 = tree->child;
        p2 = p1->sibling;

        genExp(p2, "t0");
        fprintf(IR, "(EQ, t0, 0, %s)\n", varId);
    }
    // minus factor
    else if ( isRevFacK(tree) )
    {
        p1 = tree->child;
        p2 = p1->sibling;

        genExp(p2, "t0");
        fprintf(IR, "(SUB, 0, t0, %s)\n", varId);
    }
    // id or const
    else if ( isIdK(tree) ) 
    {   
        fprintf(IR, "(%s, %s, %s, _)\n", "ASN", tree->tokenString, varId);
    }
    else if ( isConstValK(tree) )
    {
        fprintf(IR, "(%s, %s, %s, _)\n", "ASN", toConstVal(tree), varId);
    }
    else if ( isStringK(tree) )
    {   
        // return string address on varID
        // genStmt handle memcpy() for string assignment
        // Strings should be assigned a label and put into the const area
        // fprintf(IR, "(%s, '%s', %s, _)\n", "ASN", tree->tokenString, varId);
    }
    else if ( isCharK(tree) )
    {
        fprintf(IR, "(ASN, 0x%x, %s, _)\n", tree->tokenString[1], varId);
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
    switch (stmt->child) {
        case N_ID:
            TreeNode *id = stmt->child;
            // proc_stmt: ID
            if (id->sibling == NULL)
                return 1;
            // proc_stmt: ID LP args_list RP
            return 2;
            break;
        case N_SYS_PROC:
            TreeNode *sys_proc = stmt->child;
            // proc_stmt: SYS_PROC
            if (sys_proc->sibling == NULL)
                return 3;
            // proc_stmt: SYS_PROC LP expression_list RP
            return 4;
            break;
        case N_READ:
            // proc_stmt: READ LP factor RP
            return 5;
            break;
    }
}

static void genStmtList(TreeNode *tree);
static void genStmt(TreeNode *tree) {
    char *type = tree->nodekind;
    // TODO trace
    switch (type) {
        case N_ASSIGN_STMT:
            // assign
            switch (assignStmtCheck(tree)) {
                // ID ASSIGN expression
                case 1:
                    TreeNode *id = tree->child;
                    TreeNode *exp = id->sibling->child;
                    genExp(exp, res);
                    fprintf(IR, "(asn %s, %s, _)\n", res, id->tokenString);
                    break;
                // ID LB expression RB ASSIGN expression
                case 2:
                    TreeNode *id = tree->child;
                    TreeNode *exp_1 = id->sibling->child;
                    TreeNode *exp_2 = id->sibling->sibling->child;
                    genExp(exp_2, res1);
                    genExp(exp_1, res2);
                    fprintf(IR, "(asn %s, %s, _)\n", id->tokenString, t0);
                    fprintf(IR, "(add %s, %s, %s)\n", t0, res2, t0);
                    fprintf(IR, "(asn %s, *%s, _)\n", res1, t0);
                    break;
                // assign_stmt: ID DOT ID ASSIGN expression
                case 3:
                    TreeNode *id_1 = tree->child;
                    TreeNode *id_2 = id_1->sibling;
                    TreeNode *exp = id_2->sibling->child;
                    genExp(exp, res1);
                    /* fprintf(IR, "()") */
                    // TODO
                    break;
            }
            break;
        case N_PROC_STMT:
            // procedure
            // optimize TODO
            switch (procStmtCheck(tree)) {
                // proc_stmt: ID
                case 1:
                    TreeNode *id = tree->child;
                    // inline optimize TODO
                    if (!inlineFlag)
                        fprintf(IR, "(call, %s, _, _)\n", id->tokenString);
                    break;
                // proc_stmt: ID LP args_list RP
                case 2:
                    break;
                // proc_stmt: SYS_PROC
                case 3:
                    break;
                // proc_stmt: SYS_PROC LP expression_list RP
                case 4:
                    break;
                // proc_stmt: READ LP factor RP
                case 5:
                    break;
            }
            break;
        case N_COMPOUND_STMT:
            // compound
            genStmtList(tree);
            break;
        case N_IF_STMT:
            // compound
            TreeNode *exp = tree->child->child;
            TreeNode *stmt = tree->child->sibling;
            TreeNode *else_clause = stmt->sibling;
            genExp(exp, res1);
            fprintf(IR, "(if_f %s, %s, _)\n", res1, L1);
            genStmt(stmt->child);
            if (else_clause->child == NULL) {
                fprintf(IR, "L1:\n");
            }
            else {
                fprintf(IR, "(jmp %s, _, _)\n", L2);
                fprintf(IR, "L1:\n");
                genStmt(else_clause->child);
                fprintf(IR, "L2:\n");
            }
            break;
        case N_REPEAT_STMT:
            // repeat
            TreeNode *stmt_list = tree->child;
            TreeNode *exp = stmt_list->sibling->child;
            fprintf(IR, "L1:\n");
            genStmtList(stmt_list);
            genExp(exp, res1);
            fprintf(IR, "(if_f %s, %s, _)\n", res1, L1);
            break;
        case N_WHILE_STMT:
            // while
            TreeNode *exp = tree->child->child;
            TreeNode *stmt = tree->child->sibling;
            genExp(exp, res1);
            fprintf(IR, "(if_f %s, %s, _)\n", res1, L1);
            genStmt(stmt->child);
            fprintf(IR, "L1:\n");
            break
        case N_FOR_STMT:
            // for
            TreeNode *id = tree->child;
            TreeNode *exp1 = id->sibling->child;
            TreeNode *direct = id->sibling->sibling;
            TreeNode *exp2 = direct->sibling->child;
            TreeNode *stmt = direct->sibling->sibling;
            genExp(exp1, res1);
            genExp(exp2, res2);
            fprintf(IR, "(asn %s, %s, _)\n", res1, id->tokenString);
            fprintf(IR, "L1:\n");
            if (direct->nodekind == N_TO)
                fprintf(IR, "(le %s, %s, %s)\n", id->tokenString, res2, t0);
            else if (direct->nodekind == N_DOWNTO)
                fprintf(IR, "(ge %s, %s, %s)\n", id->tokenString, res2, t0);
            fprintf(IR, "(if_f %s, %s, _)\n", t0, L2);
            genStmt(stmt->child);
            fprintf(IR, "jmp L1\n");
            fprintf(IR, "L2:\n");
            break;
        case N_CASE_STMT:
            // case
            TreeNode *exp = tree->child->child;
            TreeNode *case_list = tree->child->sibling;
            TreeNode *case_expr = case_list->child;
            genExp(exp, res1);
            while (case_expr != NULL) {
                TreeNode *ch1 = case_expr->child;
                // case_expr: ID COLON stmt SEMI
                if (ch1->nodekind == N_ID) {
                    fprintf(IR, "(eq, %s, %s, %s)\n", res1, ch1->tokenString, res2);
                    fprintf(IR, "(if_f %s, %s, _)\n", res2, L1);
                }
                // case_expr: const_value COLON stmt SEMI
                else {
                    fprintf(IR, "(eq, %s, %s, %s)\n", res1, ch1->tokenString, res2);
                    fprintf(IR, "(if_f %s, %s, _)\n", res2, L1);
                }
                case_expr = case_expr->sibling;
            }
            fprintf(IR, "L1:\n");
            break;
        case N_GOTO_STMT:
            // goto
            TreeNode *inte = tree->child;
            // TODO
            fprintf(IR, "(jmp %s, _, _)\n", );
            break;
    }
}

static void genStmtList(TreeNode *tree) {
    TreeNode *stmt = tree->child;
    while (stmt != NULL) {
        genStmt(stmt->child);
        stmt = stmt->sibling;
    }
}

static void cGen( TreeNode *tree )
{
    assert(tree);

    // TODO: skipping redundent nodes
}

static void codeGen( TreeNode *syntaxTree)
{

<<<<<<< HEAD
}

static int assignStmtCheck(TreeNode *stmt) {
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

static int procStmtCheck(TreeNode *stmt) {
    switch (stmt->child) {
        case N_ID:
            TreeNode *id = stmt->child;
            // proc_stmt: ID
            if (id->sibling == NULL)
                return 1;
            // proc_stmt: ID LP args_list RP
            return 2;
            break;
        case N_SYS_PROC:
            TreeNode *sys_proc = stmt->child;
            // proc_stmt: SYS_PROC
            if (sys_proc->sibling == NULL)
                return 3;
            // proc_stmt: SYS_PROC LP expression_list RP
            return 4;
            break;
        case N_READ:
            // proc_stmt: READ LP factor RP
            return 5;
            break;
    }
}

static void genStmtList(TreeNode *tree);
static void genStmt(TreeNode *tree) {
    char *type = tree->nodekind;
    // TODO trace
    switch (type) {
        case N_ASSIGN_STMT:
            // assign
            switch (assignStmtCheck(tree)) {
                // ID ASSIGN expression
                case 1:
                    TreeNode *id = tree->child;
                    TreeNode *exp = id->sibling->child;
                    genExp(exp, res);
                    fprintf(IR, "(asn %s, %s, _)\n", res, id->tokenString);
                    break;
                // ID LB expression RB ASSIGN expression
                case 2:
                    TreeNode *id = tree->child;
                    TreeNode *exp_1 = id->sibling->child;
                    TreeNode *exp_2 = id->sibling->sibling->child;
                    genExp(exp_2, res1);
                    genExp(exp_1, res2);
                    fprintf(IR, "(asn %s, %s, _)\n", id->tokenString, t0);
                    fprintf(IR, "(add %s, %s, %s)\n", t0, res2, t0);
                    fprintf(IR, "(asn %s, *%s, _)\n", res1, t0);
                    break;
                // assign_stmt: ID DOT ID ASSIGN expression
                case 3:
                    TreeNode *id_1 = tree->child;
                    TreeNode *id_2 = id_1->sibling;
                    TreeNode *exp = id_2->sibling->child;
                    genExp(exp, res1);
                    /* fprintf(IR, "()") */
                    // TODO
                    break;
            }
            break;
        case N_PROC_STMT:
            // procedure
            // optimize TODO
            switch (procStmtCheck(tree)) {
                // proc_stmt: ID
                case 1:
                    TreeNode *id = tree->child;
                    // inline optimize TODO
                    if (!inlineFlag)
                        fprintf(IR, "(call, %s, _, _)\n", id->tokenString);
                    break;
                // proc_stmt: ID LP args_list RP
                case 2:
                    break;
                // proc_stmt: SYS_PROC
                case 3:
                    break;
                // proc_stmt: SYS_PROC LP expression_list RP
                case 4:
                    break;
                // proc_stmt: READ LP factor RP
                case 5:
                    break;
            }
            break;
        case N_COMPOUND_STMT:
            // compound
            genStmtList(tree);
            break;
        case N_IF_STMT:
            // compound
            TreeNode *exp = tree->child->child;
            TreeNode *stmt = tree->child->sibling;
            TreeNode *else_clause = stmt->sibling;
            genExp(exp, res1);
            fprintf(IR, "(if_f %s, %s, _)\n", res1, L1);
            genStmt(stmt->child);
            if (else_clause->child == NULL) {
                fprintf(IR, "L1:\n");
            }
            else {
                fprintf(IR, "(jmp %s, _, _)\n", L2);
                fprintf(IR, "L1:\n");
                genStmt(else_clause->child);
                fprintf(IR, "L2:\n");
            }
            break;
        case N_REPEAT_STMT:
            // repeat
            TreeNode *stmt_list = tree->child;
            TreeNode *exp = stmt_list->sibling->child;
            fprintf(IR, "L1:\n");
            genStmtList(stmt_list);
            genExp(exp, res1);
            fprintf(IR, "(if_f %s, %s, _)\n", res1, L1);
            break;
        case N_WHILE_STMT:
            // while
            TreeNode *exp = tree->child->child;
            TreeNode *stmt = tree->child->sibling;
            genExp(exp, res1);
            fprintf(IR, "(if_f %s, %s, _)\n", res1, L1);
            genStmt(stmt->child);
            fprintf(IR, "L1:\n");
            break
        case N_FOR_STMT:
            // for
            TreeNode *id = tree->child;
            TreeNode *exp1 = id->sibling->child;
            TreeNode *direct = id->sibling->sibling;
            TreeNode *exp2 = direct->sibling->child;
            TreeNode *stmt = direct->sibling->sibling;
            genExp(exp1, res1);
            genExp(exp2, res2);
            fprintf(IR, "(asn %s, %s, _)\n", res1, id->tokenString);
            fprintf(IR, "L1:\n");
            if (direct->nodekind == N_TO)
                fprintf(IR, "(le %s, %s, %s)\n", id->tokenString, res2, t0);
            else if (direct->nodekind == N_DOWNTO)
                fprintf(IR, "(ge %s, %s, %s)\n", id->tokenString, res2, t0);
            fprintf(IR, "(if_f %s, %s, _)\n", t0, L2);
            genStmt(stmt->child);
            fprintf(IR, "jmp L1\n");
            fprintf(IR, "L2:\n");
            break;
        case N_CASE_STMT:
            // case
            TreeNode *exp = tree->child->child;
            TreeNode *case_list = tree->child->sibling;
            TreeNode *case_expr = case_list->child;
            genExp(exp, res1);
            while (case_expr != NULL) {
                TreeNode *ch1 = case_expr->child;
                // case_expr: ID COLON stmt SEMI
                if (ch1->nodekind == N_ID) {
                    fprintf(IR, "(eq, %s, %s, %s)\n", res1, ch1->tokenString, res2);
                    fprintf(IR, "(if_f %s, %s, _)\n", res2, L1);
                }
                // case_expr: const_value COLON stmt SEMI
                else {
                    fprintf(IR, "(eq, %s, %s, %s)\n", res1, ch1->tokenString, res2);
                    fprintf(IR, "(if_f %s, %s, _)\n", res2, L1);
                }
                case_expr = case_expr->sibling;
            }
            fprintf(IR, "L1:\n");
            break;
        case N_GOTO_STMT:
            // goto
            TreeNode *inte = tree->child;
            // TODO
            fprintf(IR, "(jmp %s, _, _)\n", );
            break;
    }
}

static void genStmtList(TreeNode *tree) {
    TreeNode *stmt = tree->child;
    while (stmt != NULL) {
        genStmt(stmt->child);
        stmt = stmt->sibling;
    }
}
