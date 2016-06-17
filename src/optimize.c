#include "globals.h"
#include "util.h"

int opt_inlineFlag;

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
        switch(t->nodekind)
        {
            case N_EXP_GE:
                r = m_itoa(atof(p1->tokenString)>=atof(p2->tokenString));
                t->nodekind = N_INTEGER;
                break;
            case N_EXP_GT:
                r = m_itoa(atof(p1->tokenString)>atof(p2->tokenString));
                t->nodekind = N_INTEGER;
                break;
            case N_EXP_LE:
                r = m_itoa(atof(p1->tokenString)<=atof(p2->tokenString));
                t->nodekind = N_INTEGER;
                break;
            case N_EXP_LT:
                r = m_itoa(atof(p1->tokenString)<atof(p2->tokenString));
                t->nodekind = N_INTEGER;
                break;
            case N_EXP_EQUAL:
                r = m_itoa(atof(p1->tokenString)==atof(p2->tokenString));
                t->nodekind = N_INTEGER;
                break;
            case N_EXP_UNEQUAL:
                r = m_itoa(atof(p1->tokenString)!=atof(p2->tokenString));
                t->nodekind = N_INTEGER;
                break;
            case N_EXP_PLUS:
                if (p1->nodekind == N_REAL || p2->nodekind == N_REAL)
                {
                    r = m_ftoa(atof(p1->tokenString)+atof(p2->tokenString));
                    t->nodekind = N_REAL;
                }
                else
                {
                    r = m_itoa(atoi(p1->tokenString)+atoi(p2->tokenString));
                    t->nodekind = N_INTEGER;
                }
                break;
            case N_EXP_MINUS:
                if (p1->nodekind == N_REAL || p2->nodekind == N_REAL)
                {
                    r = m_ftoa(atof(p1->tokenString)-atof(p2->tokenString));
                    t->nodekind = N_REAL;
                }
                else
                {
                    r = m_itoa(atoi(p1->tokenString)-atoi(p2->tokenString));
                    t->nodekind = N_INTEGER;
                }
                break;
            case N_EXP_OR:
                r = m_itoa( toConstVal(p1)||toConstVal(p2));
                t->nodekind = N_INTEGER;
                break;
            case N_EXP_MUL:
                if (p1->nodekind == N_REAL || p2->nodekind == N_REAL)
                {
                    r = m_ftoa(atof(p1->tokenString)*atof(p2->tokenString));
                    t->nodekind = N_REAL;
                }
                else
                {
                    r = m_itoa(atoi(p1->tokenString)*atoi(p2->tokenString));
                    t->nodekind = N_INTEGER;
                }
                break;
            case N_EXP_DIV:
                if (p1->nodekind == N_REAL || p2->nodekind == N_REAL)
                {
                    r = m_ftoa(atof(p1->tokenString)/atof(p2->tokenString));
                    t->nodekind = N_REAL;
                }
                else
                {
                    r = m_itoa(atoi(p1->tokenString)/atoi(p2->tokenString));
                    t->nodekind = N_INTEGER;
                }
                break;
            case N_EXP_MOD:
                r = m_itoa(atoi(p1->tokenString)%atoi(p2->tokenString));
                t->nodekind = N_INTEGER;
                break;
            case N_EXP_AND:
                r = m_itoa( toConstVal(p1)&&toConstVal(p2));
                t->nodekind = N_INTEGER;
                break;
            default:
                assert(0);
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
        t->tokenString = (char*)malloc(strlen(r)+1);
        strcpy(t->tokenString, r);
        t->child = NULL;
        deleteTreeNode(p2);
        deleteTreeNode(p1);
    }
}

void O0(TreeNode *tree)
{
    foldConst(tree);
    // TODO: jump elimination
}

void O1(char *tacIr)
{
    // TODO: control flow
    // TODO: data flow
}

void O2(char *IR)
{
    // TODO: tail recursion
    // TODO: inline function
}

char *m_itoa(int i)
{
    char *s = (char*)malloc(16);
    sprintf(s, "%d", i);
    return s;
}

char *m_ftoa(float f)
{
    char *s = (char*)malloc(16);
    sprintf(s, "%d", *(int*)&f);
    return s;
}
