#include <string.h>
#include "symbol.h"

extern TreeNode * root;
symbolNode *now = NULL;//指向桶的起始地址的指针

symbolNode buckets[BUCKET_SIZE+1];//多余一个空出，有其他用处

int hash(char* str){
	int i, ans=0;	
	int length = strlen(str);
	for(i=0;i<length;i++){
		ans += str[i]*(i+1);
	}
	ans = ans % BUCKET_SIZE;
	return ans;
}

int type_check(char* name){
	if(strcmp("char", name) == 0)
		return Char;
	else if(strcmp("integer", name) == 0)
		return Integer;
	else if(strcmp("real", name) == 0)
		return Real;
	else if(strcmp("boolean", name) == 0)
		return Boolean;
	else if(strcmp("string", name) == 0)
		return String;
	else if(strcmp("array", name) == 0)
		return Array;
	else if(strcmp("record", name) == 0)
		return Record;
	else if(strcmp("type", name) == 0)
		return Type;
	else if(strcmp("const", name) == 0)
		return Const;
	else
		return -1;
}

int find_expression_type(TreeNode* expression){
  return -1;
}

/*根据符号名得到变量的类型，没有找到这个符号就返回-1*/
int get_type_by_name(char * name){
  int hashValue = hash(name);
  symbolNode node= *(now + hashValue);
  while(node != NULL){
    if(strcmp(name, node->name) == 0){
      return node->type;
    }
    node = node -> nextNode;
  }
  return -1;//没有这个定义
}


/*初始化bucket*/
void init_bucket(symbolNode* bucket){
	int i;
	for(i=0;i<BUCKET_SIZE+1;i++){
		buckets[i] = NULL;
	}
  buckets[BUCKET_SIZE] = (symbolNode)malloc(sizeof(symbolNodeCon));
}

/*新建一张symbol table*/
symbolNode* build_sym_tab(symbolNode* nodePointer){
	nodePointer = (symbolNode*)malloc(sizeof(symbolNode)*(BUCKET_SIZE+1));
	init_bucket(nodePointer);
	return nodePointer;
}

void look_ast(){
	return ;
}

int look_const_type(TreeNode * constPart){
  return 0;
}

int look_type_part(TreeNode * typePart){
	TreeNode* typeDefinition = typePart -> child;
	TreeNode* name;
	TreeNode* typeDecl;	
	while(typeDefinition != NULL){
		name = typeDefinition -> child;
		typeDecl = name -> sibling -> child;
		symbolNode node = new_symbol_node(name -> tokenString, name->lineno, Type, 0, type_check(name->sibling->child->tokenString));//??????????
		insert_symbol(node);
		typeDefinition = typeDefinition -> sibling;
	}
	return 0;
}

int look_var_part(TreeNode * varPart){
	int typeName;
	TreeNode * varDecl = varPart -> child;
	while(varDecl != NULL){
		TreeNode * nameList = varDecl -> child;
		TreeNode * typeNode = nameList -> sibling;
		TreeNode * idList = nameList -> child;
		typeName = type_check(typeNode -> child -> tokenString);
/*
		if(strcmp(typeNode -> child -> tokenString,"char") == 0){
			typeName = Char;//1
		}
		else if(strcmp(typeNode -> child -> tokenString,"integer") == 0){
			typeName = Integer;//2
		}
		else if(strcmp(typeNode -> child -> tokenString,"real") == 0){
			typeName = Real;//3
		}
		else if(strcmp(typeNode -> child -> tokenString,"boolean") == 0){
			typeName = Boolean;//4
		}
		else if(strcmp(typeNode -> child -> tokenString,"string") == 0){
			typeName = String;//5
		}
		else{
			return -1;//unknown type
		}
*/
		while(idList != NULL){
			symbolNode node = new_symbol_node(idList -> tokenString, idList->lineno, typeName, 0, 0);
			insert_symbol(node);//返回-1怎么办？？？？？？？
			idList = idList -> sibling;
		}//end of while
		varDecl = varDecl -> sibling;
	}//end of outer while
}

int look_routine_part(TreeNode* routinePart){
  return 0;  
}

int look_stmt_list_part(TreeNode* stmtList){
  TreeNode* stmt = stmtList -> child;
  TreeNode* subStmt;
  while(stmt != NULL){
    subStmt = stmt -> child;
    /*判断是哪种语句*/
    if( strcmp(getNodeKindString(subStmt->nodekind),"PROC_STMT") == 0){
      look_proc_stmt(subStmt);
    }
    else if(strcmp(getNodeKindString(subStmt->nodekind),"ASSIGN_STMT") == 0){
      look_assign_stmt(subStmt);
    }
    else if(strcmp(getNodeKindString(subStmt->nodekind),"WHILE_STMT") == 0){
      look_while_stmt(subStmt);
    }
    else if(strcmp(getNodeKindString(subStmt->nodekind),"FOR_STMT") == 0){
      look_for_stmt(subStmt);
    }
    else if(strcmp(getNodeKindString(subStmt->nodekind),"REPEAT_STMT") == 0){
      look_repeat_stmt(subStmt);
    }
    else if(strcmp(getNodeKindString(subStmt->nodekind),"GOTO_STMT") == 0){
      look_goto_stmt(subStmt);
    }
    else if(strcmp(getNodeKindString(subStmt->nodekind),"CASE_STMT") == 0){
      look_case_stmt(subStmt);
    }
    else if(strcmp(getNodeKindString(subStmt->nodekind),"COMPOUND_STMT") == 0){
      look_compound_stmt(subStmt);
    }
    else
      return -1;
  }
}


int look_proc_stmt(TreeNode* subStmt){
  return 0;  
}
/*赋值表达式类型检查*/
int look_assign_stmt(TreeNode* subStmt){
  TreeNode* id = subStmt -> child;
  TreeNode* expression = id->sibling;
  int variableType = get_type_by_name(id->tokenString);
  if(variableType ==  -1){
    fprintf(stderr,"line %d: %s \'%s\'\n", id->lineno,NO_SUCH_SYMBOL, id->tokenString );
  }
  return 0;  
}

int look_while_stmt(TreeNode* subStmt){
  return 0;  
}
int look_for_stmt(TreeNode* subStmt){
  return 0;  
}
int look_repeat_stmt(TreeNode* subStmt){
  return 0;  
}
int look_goto_stmt(TreeNode* subStmt){
  return 0;  
}
int look_case_stmt(TreeNode* subStmt){
  return 0;  
}
int look_compound_stmt(TreeNode* subStmt){
  return 0;  
}

int insert_symbol(symbolNode node){
	char * name = node -> name;
	int hashValue = hash(name);
	symbolNode which = *(now + hashValue);//桶中的第hashValue个位置
	symbolNode beforeWhich = which;
	/*以下为比较有没有重复定义*/
	while(which != NULL){
		beforeWhich = which;
		if(strcmp(name,which -> name) == 0){
			fprintf(stderr, REDEFINE, name, -2);//变量重复定义，%s变量名,%d行号
			return -1;
		}
		which = which -> nextNode;
	}
	//which = (symbolNode)malloc(sizeof(struct symbolNodeCon));
	beforeWhich -> nextNode = node;
	return 0;
}

symbolNode st_lookup(symbolNode* node, char* name){
  return NULL;
}

symbolNode new_symbol_node(char* name, int def_line, int type, int length, int type_const_arrayType){
	symbolNode node = (symbolNode)malloc(sizeof(struct symbolNodeCon));
	strcpy(node->name, name);	
	node -> type = type;

	lineList list = (lineList)malloc(sizeof(struct lineListCon));
	list -> line = def_line;
	list -> next = NULL;

	node -> lines = list;
	node -> length = length;
	node -> type_const_arrayType = type_const_arrayType;
	return node;
}

int semantic_routine_head(TreeNode* routineHead){
  return 0;
}
int semantic_routine_stmt(TreeNode* routineStmt){
  return 0;
}

int semantic_analysis(TreeNode* root){
	TreeNode* routine = root -> child -> sibling;
	TreeNode* routineHead = routine -> child;
	TreeNode* routineStmt = routineHead -> sibling;
	semantic_routine_head(routineHead);
	semantic_routine_stmt(routineStmt);
  return 0;
}






