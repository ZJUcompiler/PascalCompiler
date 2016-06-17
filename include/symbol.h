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
#define Function 10
#define Procedure 11

#define REDEFINE "line %d : Redefinition of symbol %s\n"
#define TYPEMIXED "line %d : Calculation cannot be done between different data type except 'REAL' and 'INTEGER'\n"
#define TYPEMIXED2 "line %d : Expected '%s', however, a '%s' type got\n"
#define TYPEMIXED3 "line %d : Expected 'boolean', however, a '%s' type got\n"
#define ILLEGAL_LEFT_VALUE "line %d : The symbol except VARIABLE cannot be assign\n"
#define NO_SUCH_SYMBOL "line %d : No such symbol named '%s'\n"


#define ERR stderr


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
	int type_const_arrayType;//数组的元素类型，仅对数组有效,type定义的类型，const的类型，函数返回值类型
	struct symbolNodeCon* nextNode;//指向链表中下一个symbol node
	symbolNode * nextBucket;//指向另外一个bucket，仅对函数和record有效
} symbolNodeCon;

extern symbolNode buckets[BUCKET_SIZE+1];

void print_symbol_table(symbolNode* now);
int get_expression_type(TreeNode* exp);
int get_sonex_type(TreeNode* exp);
int get_exp_cal_type(TreeNode* exp);
int hash(char*);
int str2int(char*);
void add_loc_by_type(int,int);//根据给出的类型自动增加memloc
int type_check(char* name);
char* type_string(int type);
int find_expression_type(TreeNode* expression);
void init_bucket(symbolNode*);
symbolNode* build_sym_tab(symbolNode* nodePointer);/*新建一张symbol table，指针初始化为全空*/
void look_ast();
int look_const_part(TreeNode * constPart);
int look_type_part(TreeNode * typePart);
int look_var_part(TreeNode * varPart);
int look_routine_part(TreeNode * routinePart);
symbolNode look_array_decl(char* name, int size, int type);
int look_params(TreeNode* parameters);//函数的参数分析
int look_func_decl(TreeNode* funcOrProcDecl);//函数或者过程的分析
int look_proc_decl(TreeNode* funcOrProcDecl);
int look_stmt_list_part(TreeNode* stmtList);
int look_proc_stmt(TreeNode* subStmt);
int look_assign_stmt(TreeNode* subStmt);
int look_while_stmt(TreeNode* subStmt);
int look_for_stmt(TreeNode* subStmt);
int look_repeat_stmt(TreeNode* subStmt);
int look_goto_stmt(TreeNode* subStmt);
int look_case_stmt(TreeNode* subStmt);
int look_compound_stmt(TreeNode* subStmt);
int insert_symbol(symbolNode node);
symbolNode st_lookup(symbolNode*, char* name);
symbolNode new_symbol_node(char* name, int def_line, int type, int length, int type_const_arrayType);
int semantic_routine_head(TreeNode* routineHead);
int semantic_routine_stmt_list(TreeNode* routineStmt);
int semantic_routine(TreeNode* routine);
int semantic_analysis(TreeNode* root);

#endif
