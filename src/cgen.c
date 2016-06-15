/* PASCAL COMPILER 
   Code Generation 
                    */
#include "globals.h"
#include <assert.h>

static int isExpK( TreeNode *tree )
{
    assert(tree);
    return tree->nodeKind == 
}

static void genStmt( TreeNode *tree )
{

}

static void genExp( TreeNode *tree )
{
    TreeNode *p1, *p2;
    assert( isExpK(tree) );
    
    // use function returns to avoid MACRO definition
    // (to avoid design complication/duplication)
    if ( isOpK(tree) ) 
    {
        p1 = tree->child;
        p2 = tree->child->sibling;

        genExp(p1);

        emitTAC("", );

        genExp(p2);

        emitTAC("", )
    }
    else if ( isRecK(tree) ) 
    {

    }
    else if ( isArrK(tree) )
    {

    }
    // function call, not factor, minus factor
    else if ( isCallK(tree) )
    {

    }
    else if ( isNotFac(tree) )
    {

    }
    else if ( isRevFac(tree) )
    {

    }
    else 
    {
        assert(0);
    }


}

static void cGen( TreeNode *tree )
{

}

static void codeGen( TreeNode *syntaxTree)
{

}