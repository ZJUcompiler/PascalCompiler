#include "globals.h"
#include "util.h"

inline int isConstValK( TreeNode *tree )
{
    return (tree->nodeKind == N_INTEGER ||
            tree->nodeKind == N_REAL ||
            // tree->nodeKind == N_CHAR ||
            // tree->nodeKind == N_STRING ||
            tree->nodeKind == N_SYS_CON);
}

inline int isCharK( TreeNode *tree)
{
    return tree->nodeKind == N_CHAR;
}

inline int isStringK( TreeNode *tree)
{
    return tree->nodeKind == N_STRING;
}

static void foldConst(TreeNode *t)
{
    if ( !t || !(t->child) ) return;
    TreeNode *p1, *p2;
    char *r;
    p1 = t->child;
    p2 = p1->sibling;

    foldConst(p1);

    foldConst(p2);

    if ( isConstValK(p1) && isConstValK(p2) )
    {
        switch(t->nodeKind)
        {
            case N_EXP_GE:
                r = itoa(atof(p1->tokenString)>=atof(p2->tokenString));
                t->nodeKind = N_INTEGER;
                break;
            case N_EXP_GT:
                r = itoa(atof(p1->tokenString)>atof(p2->tokenString));
                t->nodeKind = N_INTEGER;
                break;
            case N_EXP_LE:
                r = itoa(atof(p1->tokenString)<=atof(p2->tokenString));
                t->nodeKind = N_INTEGER;
                break;
            case N_EXP_LT:
                r = itoa(atof(p1->tokenString)<atof(p2->tokenString));
                t->nodeKind = N_INTEGER;
                break;
            case N_EXP_EQUAL:
                r = itoa(atof(p1->tokenString)==atof(p2->tokenString));
                t->nodeKind = N_INTEGER;
                break;
            case N_EXP_UNEQUAL:
                r = itoa(atof(p1->tokenString)!=atof(p2->tokenString));
                t->nodeKind = N_INTEGER;
                break;
            case N_EXP_PLUS:
                if (p1->nodeKind == N_REAL || p2->nodeKind == N_REAL)
                {
                    r = ftoa(atof(p1->tokenString)+atof(p2->tokenString));
                    t->nodeKind = N_REAL;
                }
                else
                {
                    r = itoa(atoi(p1->tokenString)+atoi(p2->tokenString));
                    t->nodeKind = N_INTEGER;
                }
                break;
            case N_EXP_MINUS:
                if (p1->nodeKind == N_REAL || p2->nodeKind == N_REAL)
                {
                    r = ftoa(atof(p1->tokenString)-atof(p2->tokenString));
                    t->nodeKind = N_REAL;
                }
                else
                {
                    r = itoa(atoi(p1->tokenString)-atoi(p2->tokenString));
                    t->nodeKind = N_INTEGER;
                }
                break;
            case N_EXP_OR:
                r = itoa(atoi(toConstVal(p1))||atoi(toConstVal(p2->tokenString)));
                t->nodeKind = N_INTEGER;
                break;
            case N_EXP_MUL:
                if (p1->nodeKind == N_REAL || p2->nodeKind == N_REAL)
                {
                    r = ftoa(atof(p1->tokenString)*atof(p2->tokenString));
                    t->nodeKind = N_REAL;
                }
                else
                {
                    r = itoa(atoi(p1->tokenString)*atoi(p2->tokenString));
                    t->nodeKind = N_INTEGER;
                }
                break;
            case N_EXP_DIV:
                if (p1->nodeKind == N_REAL || p2->nodeKind == N_REAL)
                {
                    r = ftoa(atof(p1->tokenString)/atof(p2->tokenString));
                    t->nodeKind = N_REAL;
                }
                else
                {
                    r = itoa(atoi(p1->tokenString)/atoi(p2->tokenString));
                    t->nodeKind = N_INTEGER;
                }
                break;
            case N_EXP_MOD:
                r = itoa(atoi(p1->tokenString)%atoi(p2->tokenString));
                t->nodeKind = N_INTEGER;
                break;
            case N_EXP_AND:
                r = itoa(atoi(toConstVal(p1))&&atoi(toConstVal(p2->tokenString)));
                t->nodeKind = N_INTEGER;
                break;
        } 
        if (t->tokenString)
            free(t->tokenString);
        t->tokenString = r;
        t->child = NULL;
        deleteTreeNode(p2);
        deleteTreeNode(p1);
    }
    else if ( isCharK(p1) && isCharK(p2) )
    {
        // TODO: what is the behavior? what is a char anyway?
    }
    else if ( isStringK(p1) && isStringK(p2) )
    {
        if (t->tokenString)
            free(t->tokenString);
        r = strcat(p1->tokenString, p2->tokenString);
        t->tokenString = (char*)mallloc(strlen(r)+1);
        strcpy(t->tokenString, r);
        t->child = NULL;
        deleteTreeNode(p2);
        deleteTreeNode(p1);
    }
}

void O0(TreeNode *tree)
{
    foldConst(tree);
}

void O1(char *tacIr)
{
    // TODO: constant folding
    // TODO: jump
}

void O2(char *IR)
{
    // TODO: tail recursion
    // TODO: inline function
}