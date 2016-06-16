#ifndef SYMBOL_H
#define SYMBOL_H
	
#include "globals.h"
#include "util.h"

#define BUCKET_SIZE 101
#define Char 1
#define Integer 2
#define Real 3
#define Boolean 4
#define String 5
#define Array 6
#define Record 7
#define Type 8
#define Const 9

#define REDEFINE "Redefinition of variable %s\n in line %d"
#define NO_SUCH_SYMBOL "No such symbol named "

typedef struct lineListCon{
	int line;
	struct lineList * next;
}* lineList;

struct symbolNodeCon;
typedef struct symbolNodeCon* symbolNode;
typedef struct symbolNodeCon{
	char * name;
	int type;//符号的类型
	int memloc;//符号在内存中的位置
	lineList lines;//所有在程序中出现的行
	int length;//数组长度，仅对数组有效
	int type_const_arrayType;//数组的元素类型，仅对数组有效
	struct symbolNodeCon* nextNode;//指向链表中下一个symbol node
	struct symbolNode * nextBucket;//指向另外一个bucket，仅对函数和record有效
} symbolNodeCon;

int hash(char*);
int type_check(char* name)
int find_expression_type(TreeNode* expression)
void init_bucket(symbolNode);
symbolNode* build_sym_tab(symbolNode* nodePointer);/*新建一张symbol table，指针初始化为全空*/
void look_ast();
int look_type_part(TreeNode * typePart);
int look_var_part(TreeNode * varPart);
int look_routine_part(TreeNode * routinePart);
int look_stmt_list_part(TreeNode* stmtList);
int look_proc_stmt(subStmt);
int look_assign_stmt(subStmt);
int look_while_stmt(subStmt);
int look_for_stmt(subStmt);
int look_repeat_stmt(subStmt);
int look_goto_stmt(subStmt);
int look_case_stmt(subStmt);
int look_compound_stmt(subStmt);
int insert_symbol(symbolNode node);
sybolNode st_lookup(symbolNode*, char* name);
symbolNode new_symbol_node(char* name, int def_line, int type);
int semantic_routine_head(TreeNode* routineHead);
int semantic_routine_stmt(TreeNode* routineStmt);

int semantic_analysis(TreeNode root);

#endif
