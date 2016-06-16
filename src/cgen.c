#include "stdio.h"
#include "util.h"
#include <assert.h>
#include "globals.h"
#include "constTab.h"
#include "symbol.h"
#include "optimize.h"

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

static symbolNode *cur_domain = NULL;
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

        genExp(p1, t0);

        genExp(p2, t1);

        switch( tree->nodekind )
        {
            case N_EXP_GE: 
                fprintf(IR, "(ge %s, %s, %s)\n", t0, t1, varId);
                break;
            case N_EXP_GT: 
                fprintf(IR, "(gt %s, %s, %s)\n", t0, t1, varId);
                break;
            case N_EXP_LE: 
                fprintf(IR, "(le %s, %s, %s)\n", t0, t1, varId);
                break;
            case N_EXP_LT: 
                fprintf(IR, "(lt %s, %s, %s)\n", t0, t1, varId);
                break;
            case N_EXP_EQUAL: 
                fprintf(IR, "(eq %s, %s, %s)\n", t0, t1, varId);
                break;
            case N_EXP_UNEQUAL: 
                fprintf(IR, "(neq %s, %s, %s)\n", t0, t1, varId);
                break;
            case N_EXP_PLUS: 
                fprintf(IR, "(add %s, %s, %s)\n", t0, t1, varId);
                break;
            case N_EXP_MINUS:
                fprintf(IR, "(sub %s, %s, %s)\n", t0, t1, varId);
                break;
            case N_EXP_OR: 
                fprintf(IR, "(or %s, %s, %s)\n", t0, t1, varId);
                break;
            case N_EXP_MUL:
                fprintf(IR, "(mul %s, %s, %s)\n", t0, t1, varId);
                break;
            case N_EXP_DIV:
                fprintf(IR, "(div %s, %s, %s)\n", t0, t1, varId);
                break;
            case N_EXP_MOD:
                fprintf(IR, "(mod %s, %s, %s)\n", t0, t1, varId);
                break;
            case N_EXP_AND:
                fprintf(IR, "(and %s, %s, %s)\n", t0, t1, varId);
                break;
            default:
                assert(0);
        }
    }
    else if ( isRecK(tree) ) 
    {
        p1 = tree->child;
        p2 = p1->sibling;

        symbolNode node = st_lookup(cur_domain, p1->tokenString);
        symbolNode field = st_lookup(node->nextBucket, p2->tokenString);

        // name of a record represents its address
        fprintf(IR, "(add %s, %d, %s)\n", p1->tokenString, field->memloc, t0);
        fprintf(IR, "(asn *%s, %s, _)\n", t0, varId);
    }
    else if ( isArrK(tree) )
    {
        p1 = tree->child;
        p2 = p1->sibling;

        genExp(p1, t0);
        
        genExp(p2, t1);

        fprintf(IR, "(add %s, %s, %s)\n", t0, t1, t0);
        fprintf(IR, "(asn *%s, %s, _)\n", t0, varId);
    }
    // function call
    else if ( isCallK(tree) )
    {   
        p1 = tree->child;
        p2 = p1->sibling;

        TreeNode *p_arg = p2->child;
        while (p_arg)
        {
            genExp(p_arg, t0);
            fprintf(IR, "(arg %s, _, _)\n", t0);
        }
        assert(strcmp(varId, "$v0")==0);    // TODO: function return
        fprintf(IR, "(call %s, _, _)\n", tree->tokenString);
    }
    // not factor
    else if ( isNotFacK(tree) )
    {
        p1 = tree->child;
        p2 = p1->sibling;

        genExp(p2, t0);
        fprintf(IR, "(eq %s, 0, %s)\n", t0, varId);
    }
    // minus factor
    else if ( isRevFacK(tree) )
    {
        p1 = tree->child;
        p2 = p1->sibling;

        genExp(p2, t0);
        fprintf(IR, "(sub 0, %s, %s)\n", t0, varId);
    }
    // id or const
    else if ( isIdK(tree) ) 
    {   
        fprintf(IR, "(asn %s, %s, _)\n", tree->tokenString, varId);
    }
    else if ( isConstValK(tree) )
    {
        fprintf(IR, "(asn %x, %s, _)\n", toConstVal(tree), varId);
    }
    else if ( isStringK(tree) )
    {   
        // return string address on varID
        // genStmt handle memcpy() for string assignment
        // Strings should be assigned a label and put into the const area
        char label[32];
        sprintf(label, "_$CONST$_L%d", ct_count);
        fprintf(IR, "(asn %s, %s, _)\n", label, varId);
        ct_insert_str(tree->tokenString, label);
    }
    else if ( isCharK(tree) )
    {
        fprintf(IR, "(asn %d, %s, _)\n", (int)(tree->tokenString[1]), varId);
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

static void genStmtList(TreeNode *tree);
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
                    genExp(exp, res1);
                    fprintf(IR, "(asn %s, %s, _)\n", res1, id->tokenString);
                    break;
                }
                // ID LB expression RB ASSIGN expression
                case 2: {
                    TreeNode *id = tree->child;
                    TreeNode *exp_1 = id->sibling->child;
                    TreeNode *exp_2 = id->sibling->sibling->child;
                    genExp(exp_2, res1);
                    genExp(exp_1, res2);
                    fprintf(IR, "(asn %s, %s, _)\n", id->tokenString, t0);
                    fprintf(IR, "(add %s, %s, %s)\n", t0, res2, t0);
                    fprintf(IR, "(asn %s, *%s, _)\n", res1, t0);
                    break;
                }
                // assign_stmt: ID DOT ID ASSIGN expression
                case 3: {
                    TreeNode *id_1 = tree->child;
                    TreeNode *id_2 = id_1->sibling;
                    TreeNode *exp = id_2->sibling->child;
                    genExp(exp, res1);
                    symbolNode node = st_lookup(cur_domain, id_1->tokenString);
                    symbolNode field = st_lookup(node->nextBucket, id_2->tokenString);
                    fprintf(IR, "(add %s, %s, %s)\n", 
                            id_1->tokenString, field->memloc,t0);
                    fprintf(IR, "(asn %s, *%s, _)\n", res1, t0);
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
                        fprintf(IR, "(call %s, _, _)\n", id->tokenString);
                    break;
                }
                // proc_stmt: ID LP args_list RP
                case 2: {
                    TreeNode *id = tree->child;
                    TreeNode *p = id->sibling->child;
                    while(p)
                    {
                        genExp(p, res1);
                        fprintf(IR, "(arg %s, _, _)\n", res1);
                    }
                    fprintf(IR, "(call %s, _, _)\n", id->tokenString);
                    break;
                }
                // proc_stmt: SYS_PROC
                case 3: {
                    TreeNode *id = tree->child;
                    fprintf(IR, "(call %s, _, _)\n", id->tokenString);
                    break;
                }
                // proc_stmt: SYS_PROC LP expression_list RP
                case 4: {
                    TreeNode *id = tree->child;
                    TreeNode *p = id->sibling->child;
                    while(p)
                    {
                        genExp(p, res1);
                        fprintf(IR, "(arg %s, _, _)\n", res1);
                    }
                    fprintf(IR, "(call %s, _, _)\n", id->tokenString);
                    break;
                }
                // proc_stmt: READ LP factor RP
                case 5: {
                    
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
        }
        case N_REPEAT_STMT: {
            // repeat
            TreeNode *stmt_list = tree->child;
            TreeNode *exp = stmt_list->sibling->child;
            fprintf(IR, "L1:\n");
            genStmtList(stmt_list);
            genExp(exp, res1);
            fprintf(IR, "(if_f %s, %s, _)\n", res1, L1);
            break;
        }
        case N_WHILE_STMT: {
            // while
            TreeNode *exp = tree->child->child;
            TreeNode *stmt = tree->child->sibling;
            genExp(exp, res1);
            fprintf(IR, "(if_f %s, %s, _)\n", res1, L1);
            genStmt(stmt->child);
            fprintf(IR, "L1:\n");
            break;
        }
        case N_FOR_STMT: {
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
        }
        case N_CASE_STMT: {
            // case
            TreeNode *exp = tree->child->child;
            TreeNode *case_list = tree->child->sibling;
            TreeNode *case_expr = case_list->child;
            genExp(exp, res1);
            while (case_expr != NULL) {
                TreeNode *ch1 = case_expr->child;
                // case_expr: ID COLON stmt SEMI
                if (ch1->nodekind == N_ID) {
                    fprintf(IR, "(eq %s, %s, %s)\n", res1, ch1->tokenString, res2);
                    fprintf(IR, "(if_f %s, %s, _)\n", res2, L1);
                }
                // case_expr: const_value COLON stmt SEMI
                else {
                    fprintf(IR, "(eq %s, %s, %s)\n", res1, ch1->tokenString, res2);
                    fprintf(IR, "(if_f %s, %s, _)\n", res2, L1);
                }
                case_expr = case_expr->sibling;
            }
            fprintf(IR, "L1:\n");
            break;
        }
        case N_GOTO_STMT: {
            // goto
            // TreeNode *inte = tree->child;
            // TODO
            // fprintf(IR, "(jmp %s, _, _)\n", );
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

// static void cGen( TreeNode *tree )
// {
//     assert(tree);

//     // TODO: skipping redundent nodes
// }

static void codeGen( TreeNode *syntaxTree)
{
    cur_domain = bucket;
    assert(syntaxTree->nodekind == N_PROGRAM);
    genStmtList(syntaxTree->child->sibling->child->sibling);
}