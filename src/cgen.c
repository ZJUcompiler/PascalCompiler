/* PASCAL COMPILER 
   Code Generation 
                    */
#include "globals.h"
#include <assert.h>
#include "util.h"

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

static void genStmt( TreeNode *tree )
{

}

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

        // sprintf(IR, "(%s, %s, %s, %s)\n", toOpStr(tree->nodekind), "t0", "t1", varId);
        switch( tree->nodekind )
        {
            case N_EXP_GE: 
                sprintf(IR, "(GE, t0, t1, %s)\n", varId);
                break;
            case N_EXP_GT: 
                sprintf(IR, "(GT, t0, t1, %s)\n", varId);
                break;
            case N_EXP_LE: 
                sprintf(IR, "(LE, t0, t1, %s)\n", varId);
                break;
            case N_EXP_LT: 
                sprintf(IR, "(LT, t0, t1, %s)\n", varId);
                break;
            case N_EXP_EQUAL: 
                sprintf(IR, "(EQ, t0, t1, %s)\n", varId);
                break;
            case N_EXP_UNEQUAL: 
                sprintf(IR, "(NEQ, t0, t1, %s)\n", varId);
                break;
            case N_EXP_PLUS: 
                sprintf(IR, "(ADD, t0, t1, %s)\n", varId);
                break;
            case N_EXP_MINUS:
                sprintf(IR, "(SUB, t0, t1, %s)\n", varId);
                break;
            case N_EXP_OR: 
                sprintf(IR, "(OR, t0, t1, %s)\n", varId);
                break;
            case N_EXP_MUL:
                sprintf(IR, "(MUL, t0, t1, %s)\n", varId);
                break;
            case N_EXP_DIV:
                sprintf(IR, "(DIV, t0, t1, %s)\n", varId);
                break;
            case N_EXP_MOD:
                sprintf(IR, "(MOD, t0, t1, %s)\n", varId);
                break;
            case N_EXP_AND:
                sprintf(IR, "(AND, t0, t1, %s)\n", varId);
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

        // sprintf(IR, "%s\n", );
    }
    else if ( isArrK(tree) )
    {
        p1 = tree->child;
        p2 = p1->sibling;

        genExp(p1, "t0");
        
        genExp(p2, "t1");

        sprintf(IR, "(ADD, t0, t1, t0)\n");
        sprintf(IR, "(ASN, *t0, %s, _)\n", varId);
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
            sprintf(IR, "(ARG, t0, _, _)\n");
        }
        assert(strcmp(varId, "$v0")==0);
        sprintf(IR, "(CALL, %s, _, _)\n", tree->tokenString);
    }
    // not factor
    else if ( isNotFacK(tree) )
    {
        p1 = tree->child;
        p2 = p1->sibling;

        genExp(p2, "t0");
        sprintf(IR, "(EQ, t0, 0, %s)\n", varId);
    }
    // minus factor
    else if ( isRevFacK(tree) )
    {
        p1 = tree->child;
        p2 = p1->sibling;

        genExp(p2, "t0");
        sprintf(IR, "(SUB, 0, t0, %s)\n", varId);
    }
    // id or const
    else if ( isIdK(tree) || isStringK(tree) ) 
    {   // NOTE: strings are variables...
        // and at the same time arrays of char with the first as #len
        sprintf(IR, "(%s, %s, %s, _)\n", "ASN", tree->tokenString, varId);
    }
    else if ( isConstValK(tree) )
    {
        sprintf(IR, "(%s, %s, %s, _)\n", "ASN", toConstVal(tree), varId);
    }
    else if ( isCharK(tree) )
    {
        sprintf(IR, "(ASN, %d, %s, _)\n", tree->tokenString[1], varId);
    }
    else
    {
        assert(0);
    }
}

static void cGen( TreeNode *tree )
{
    assert(tree);

    // TODO: skipping redundent nodes
}

static void codeGen( TreeNode *syntaxTree)
{

}