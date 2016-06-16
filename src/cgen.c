/*************************************************************************
 > File Name: cgen.c
 > Author: Hac
 > Mail: hac@zju.edu.cn
 > Created Time: Wed 15 Jun 2016 03:19:47 PM CST
 ************************************************************************/

#include "stdio.h"
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
#define L2 "L2"

static int labelNum = 0;
static int label
int IR;

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
            switch (procStmtCheck(tree)) {
                // proc_stmt: ID
                case 1:
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