#pragma once

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "globals.h"
#include <assert.h>
TreeNode *newTreeNode(NodeKind kind);
void appendChild(TreeNode *t, TreeNode *child);
TreeNode *newTokenTreeNode(NodeKind kind, char* tokenString);
void printTreeNode(TreeNode* treeNode);
char* getNodeKindString(NodeKind kind);
void deleteTreeNode(TreeNode *t);
int toConstVal(TreeNode *t);
char *m_itoa(int);
char *m_ftoa(float);

static inline int isOpK( TreeNode *tree)
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

static inline int isRecK( TreeNode *tree )
{
    return (tree->nChild == 2) &&
            (tree->nodekind == N_FACTOR) &&
            (tree->child->nodekind == N_ID) &&
            (tree->child->sibling->nodekind == N_ID);
}

static inline int isArrK( TreeNode *tree )
{
    return (tree->nChild == 2) &&
            (tree->nodekind == N_FACTOR) &&
            (tree->child->nodekind == N_ID) &&
            (tree->child->sibling->nodekind == N_EXPRESSION);
}

static inline int isCallK( TreeNode *tree )
{
    return (tree->nChild == 2) &&
            (tree->nodekind == N_FACTOR) &&
            (tree->child->nodekind == N_ID|| tree->child->nodekind ==N_SYS_FUNCT) &&
            (tree->child->sibling->nodekind == N_ARGS_LIST);
}

static inline int isNotFacK( TreeNode *tree )
{
    return (tree->nChild == 2) &&
            (tree->nodekind == N_FACTOR) &&
            (tree->child->nodekind == N_NOT) &&
            (tree->child->sibling->nodekind == N_FACTOR);
}

static inline int isRevFacK( TreeNode *tree )
{
    return (tree->nChild == 2) &&
            (tree->nodekind == N_FACTOR) &&
            (tree->child->nodekind == N_MINUS) &&
            (tree->child->sibling->nodekind == N_FACTOR);
}

static inline int isIdK( TreeNode *tree )
{
    return (tree->nodekind == N_ID);
}

static inline int isConstValK( TreeNode *tree )
{
    return (tree->nodekind == N_INTEGER ||
            tree->nodekind == N_REAL ||
            // tree->nodekind == N_CHAR ||
            // tree->nodekind == N_STRING ||
            tree->nodekind == N_SYS_CON);
}

static inline int isCharK( TreeNode *tree)
{
    return tree->nodekind == N_CHAR;
}

static inline int isStringK( TreeNode *tree)
{
    return tree->nodekind == N_STRING;
}

static inline int isExpK( TreeNode *tree )
{
    assert(tree);
    return isOpK(tree) || isRecK(tree) || isArrK(tree) ||
        isCallK(tree) || isRevFacK(tree) ||
        isNotFacK(tree) || isIdK(tree) ||
        isConstValK(tree) || isCharK(tree) ||
        isStringK(tree);
}
