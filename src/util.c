#include "util.h"
#include <assert.h>

TreeNode *newTreeNode(NodeKind kind){
	TreeNode* t = (TreeNode *) malloc(sizeof(TreeNode));
	t->child = NULL;
	t->sibling = NULL;
	t->nodekind = kind;
	t->tokenString = NULL;
	t->nChild = 0;
	if (traceflag) printTreeNode(t);

	return t;
}

TreeNode *newTokenTreeNode(NodeKind kind, char* tokenString){
	TreeNode* t = (TreeNode *) malloc(sizeof(TreeNode));
	t->child = NULL;
	t->sibling = NULL;
	t->nodekind = kind;
	t->nChild = 0;
	t->lineno = lineno;
	int len = strlen(tokenString);
	t->tokenString = (char *)malloc(len + 1);
	strcpy(t->tokenString, tokenString);
	(t->tokenString)[len] = '\0';
	if (traceflag) printTreeNode(t);

	return t;
}

// leaf node only
void deleteTreeNode(TreeNode *t)
{
	assert(t->child == NULL);
//	assert(t->sibling == NULL);//bless me
	if (t->tokenString)
	{
		free(t->tokenString);
	}
	free(t);
}

void appendChild(TreeNode *t, TreeNode *child){
	if (t->child == NULL) t->child = child;
	else {
		TreeNode *p = t->child;
		while (p->sibling != NULL) p = p->sibling;
		p->sibling = child;
	}
	t->nChild++;
}

char* type_string(int type);
int isTerminal(NodeKind kind);
void printTreeNode(TreeNode* treeNode){
	char *name = getNodeKindString(treeNode->nodekind);
	int isTerm = isTerminal(treeNode->nodekind);
	if (isTerm)
		printf("<%s>[%s]{%d}(%s)\n", name, treeNode->tokenString, treeNode->lineno, type_string(treeNode->type));
	else
		printf("%s(%s)\n", name,type_string(treeNode->type));
}

int isTerminal(NodeKind kind){
	switch(kind){
		case N_AND:
		case N_ARRAY:
		case N_ASSIGN:
		case N_BEGIN:
		case N_CASE:
		case N_CHAR:
		case N_COLON:
		case N_COMMA:
		case N_CONST:
		case N_DIV:
		case N_DO:
		case N_DOT:
		case N_DOTDOT:
		case N_DOWNTO:
		case N_ELSE:
		case N_END:
		case N_EQUAL:
		case N_FOR:
		case N_FUNCTION:
		case N_GE:
		case N_GOTO:
		case N_GT:
		case N_ID:
		case N_IF:
		case N_INTEGER:
		case N_LB:
		case N_LE:
		case N_LP:
		case N_LT:
		case N_MINUS:
		case N_MOD:
		case N_MUL:
		case N_NOT:
		case N_OF:
		case N_OR:
		case N_PLUS:
		case N_PROCEDURE:
		case N_RB:
		case N_READ:
		case N_REAL:
		case N_RECORD:
		case N_REPEAT:
		case N_RP:
		case N_SEMI:
		case N_STRING:
		case N_SYS_CON:
		case N_SYS_FUNCT:
		case N_SYS_PROC:
		case N_SYS_TYPE:
		case N_THEN:
		case N_TO:
		case N_TYPE:
		case N_UNEQUAL:
		case N_UNTIL:
		case N_VAR:
		case N_WHILE:
			return 1;
		default:
			return 0;
	}
}

char* getNodeKindString(NodeKind kind){
	switch(kind){
		case N_ID:
			return "ID";
		case N_ROUTINE:
			return "ROUTINE";
		case N_ROUTINE_HEAD:
			return "ROUTINE_HEAD";
		case N_STMT_LIST:
			return "STMT_LIST";
		case N_LABEL_PART:
			return "LABEL_PART";
		case N_CONST_PART:
			return "CONST_PART";
		case N_CONST_PART_EXP:
			return "CONST_PART_EXP";
		case N_TYPE_PART:
			return "TYPE_PART";
		case N_TYPE_DEFINITION:
			return "TYPE_DEFINITION";
		case N_VAR_PART:
			return "VAR_PART";
		case N_ROUTINE_PART:
			return "ROUTINE_PART";
		case N_SIMPLE_TYPE_DECL:
			return "SIMPLE_TYPE_DECL";
		case N_ARRAY_TYPE_DECL:
			return "ARRAY_TYPE_DECL";
		case N_RECORD_TYPE_DECL:
			return "RECORD_TYPE_DECL";
		case N_NAME_LIST:
			return "NAME_LIST";
		case N_FIELD_DECL:
			return "FIELD_DECL";
		case N_VAR_DECL:
			return "VAR_DECL";
		case N_FUNCTION_DECL:
			return "FUNCTION_DECL";
		case N_PROCEDURE_DECL:
			return "PROCEDURE_DECL";
		case N_FUNCTION_HEAD:
			return "FUNCTION_HEAD";
		case N_PARAMETERS:
			return "PARAMETERS";
		case N_PARA_TYPE:
			return "PARA_TYPE";
		case N_PROCEDURE_HEAD:
			return "PROCEDURE_HEAD";
		case N_STMT:
			return "STMT";
		case N_ASSIGN_STMT:
			return "ASSIGN_STMT";
		case N_PROC_STMT:
			return "PROC_STMT";
		case N_COMPOUND_STMT:
			return "COMPOUND_STMT";
		case N_IF_STMT:
			return "IF_STMT";
		case N_REPEAT_STMT:
			return "REPEAT_STMT";
		case N_WHILE_STMT:
			return "WHILE_STMT";
		case N_FOR_STMT:
			return "FOR_STMT";
		case N_CASE_STMT:
			return "CASE_STMT";
		case N_GOTO_STMT:
			return "GOTO_STMT";
		case N_ARGS_LIST:
			return "ARGS_LIST";
		case N_CASE_EXPR_LIST:
			return "CASE_EXPR_LIST";
		case N_CASE_EXPR:
			return "CASE_EXPR";
		case N_EXPRESSION_LIST:
			return "EXPRESSION_LIST";
		case N_EXPRESSION:
			return "EXPRESSION";
		case N_EXP_GE:
			return "EXP_GE";
		case N_EXP_GT:
			return "EXP_GT";
		case N_EXP_LE:
			return "EXP_LE";
		case N_EXP_LT:
			return "EXP_LT";
		case N_EXP_EQUAL:
			return "EXP_EQUAL";
		case N_EXP_UNEQUAL:
			return "EXP_UNEQUAL";
		case N_EXP_PLUS:
			return "EXP_PLUS";
		case N_EXP_MINUS:
			return "EXP_MINUS";
		case N_EXP_OR:
			return "EXP_OR";
		case N_EXP_MUL:
			return "EXP_MUL";
		case N_EXP_DIV:
			return "EXP_DIV";
		case N_EXP_MOD:
			return "EXP_MOD";
		case N_EXP_AND:
			return "EXP_AND";
		case N_FACTOR:
			return "FACTOR";
		case N_AND:
			return "AND";
		case N_ARRAY:
			return "ARRAY";
		case N_ASSIGN:
			return "ASSIGN";
		case N_BEGIN:
			return "BEGIN";
		case N_CASE:
			return "CASE";
		case N_CHAR:
			return "CHAR";
		case N_COLON:
			return "COLON";
		case N_COMMA:
			return "COMMA";
		case N_CONST:
			return "CONST";
		case N_DIV:
			return "DIV";
		case N_DO:
			return "DO";
		case N_DOT:
			return "DOT";
		case N_DOTDOT:
			return "DOTDOT";
		case N_DOWNTO:
			return "DOWNTO";
		case N_ELSE:
			return "ELSE";
		case N_END:
			return "END";
		case N_EQUAL:
			return "EQUAL";
		case N_FOR:
			return "FOR";
		case N_FUNCTION:
			return "FUNCTION";
		case N_GE:
			return "GE";
		case N_GOTO:
			return "GOTO";
		case N_GT:
			return "GT";
		case N_IF:
			return "IF";
		case N_INTEGER:
			return "INTEGER";
		case N_LB:
			return "LB";
		case N_LE:
			return "LE";
		case N_LP:
			return "LP";
		case N_LT:
			return "LT";
		case N_MINUS:
			return "MINUS";
		case N_MOD:
			return "MOD";
		case N_MUL:
			return "MUL";
		case N_NOT:
			return "NOT";
		case N_OF:
			return "OF";
		case N_OR:
			return "OR";
		case N_PLUS:
			return "PLUS";
		case N_PROCEDURE:
			return "PROCEDURE";
		case N_PROGRAM:
			return "PROGRAM";
		case N_RB:
			return "RB";
		case N_READ:
			return "READ";
		case N_REAL:
			return "REAL";
		case N_RECORD:
			return "RECORD";
		case N_REPEAT:
			return "REPEAT";
		case N_RP:
			return "RP";
		case N_SEMI:
			return "SEMI";
		case N_STRING:
			return "STRING";
		case N_SYS_CON:
			return "SYS_CON";
		case N_SYS_FUNCT:
			return "SYS_FUNCT";
		case N_SYS_PROC:
			return "SYS_PROC";
		case N_SYS_TYPE:
			return "SYS_TYPE";
		case N_THEN:
			return "THEN";
		case N_TO:
			return "TO";
		case N_TYPE:
			return "TYPE";
		case N_UNEQUAL:
			return "UNEQUAL";
		case N_UNTIL:
			return "UNTIL";
		case N_VAR:
			return "VAR";
		case N_WHILE:
			return "WHILE";
		default:
			return "UNKNOWN";
	}
}

int toConstVal( TreeNode *tree )
{
    switch (tree->nodekind)
    {
        case N_INTEGER:
            return atoi(tree->tokenString);
        case N_REAL:
        	return (int)atof(tree->tokenString);
        case N_SYS_CON:
            if (strcmp(tree->tokenString, "true")==0)
                return 1;
            else if(strcmp(tree->tokenString, "maxint")==0)
                return (int)2147483648;
            else if(strcmp(tree->tokenString, "false")==0)
                return 0;
            assert(0);
            break;
        default:
            assert(0);
    }
}
