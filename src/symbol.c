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

int str2int(char* str){
  int length = strlen(str);
  int i=0,ans=0;
  for(i=0;i<length;i++){
    ans = ans * 10 + str[i]-'0';
  }
  return ans;
}

void add_loc_by_type(int type, int count){
  int size = 0;
  //fprintf(stderr,"now = %d,type = %d",now,type);
  switch(type){
  case Char:size=1;break;
  case Integer:size=4;break;
  case Real:size=4;break;
  case Boolean:size=1;break;
  case String:size=256;break;
  }
  fprintf(stderr,"now = %d",now);
  fprintf(stderr,"now_bucketsieze = %d",*(now+BUCKET_SIZE));
  
  (*(now+BUCKET_SIZE))->memloc += size*count;
}

/*字符串和数字的一一对应*/
int type_check(char* name){
	if(strcmp("char", name) == 0 || strcmp("CHAR", name) == 0)
		return Char;
	else if(strcmp("integer", name) == 0 || strcmp("INTEGER", name) == 0)
		return Integer;
	else if(strcmp("real", name) == 0 || strcmp("REAL", name) == 0)
		return Real;
	else if(strcmp("boolean", name) == 0 || strcmp("BOOLEAN", name) == 0)
		return Boolean;
	else if(strcmp("string", name) == 0 || strcmp("STRING", name) == 0)
		return String;
	else if(strcmp("array", name) == 0 || strcmp("ARRAY", name) == 0)
		return Array;
	else if(strcmp("record", name) == 0 || strcmp("RECORD", name) == 0)
		return Record;
	else if(strcmp("type", name) == 0)
		return Type;
	else if(strcmp("const", name) == 0)
		return Const;
	else
		return -1;
}
char* type_string(int type){
  switch(type){
  case 1:return "char";break;
  case 2:return "integer";break;
  case 3:return "real";break;
  case 4:return "boolean";break;
  case 5:return "string";break;
  case 6:return "array";break;
  case 7:return "record";break;
  case 8:return "type";break;
  case 9:return "const";break;
  case 10:return "function";break;
  case 11:return "procedure";break;
  default : return "unknow";break;
  }
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


/*初始化一个bucket，不能初始化全局的bucket*/
void init_bucket(symbolNode* bucket){
	int i;
	for(i=0;i<BUCKET_SIZE+1;i++){
		bucket[i] = NULL;
	}
  bucket[BUCKET_SIZE] = (symbolNode)malloc(sizeof(symbolNodeCon));
  bucket[BUCKET_SIZE] -> memloc = 0;
  bucket[BUCKET_SIZE] -> nextBucket = now;
  if(bucket == buckets)//
    bucket[BUCKET_SIZE] -> nextBucket = NULL;
}

/*新建一张symbol table*/
symbolNode* build_sym_tab(symbolNode* nodePointer){
	nodePointer = (symbolNode*)malloc(sizeof(symbolNode)*(BUCKET_SIZE+1));
  //fprintf(stderr,"nodepointer = %d",nodePointer);
	init_bucket(nodePointer);
	return nodePointer;
}

void look_ast(){
	return ;
}

/*常量加入符号表，不需要分配空间*/
int look_const_part(TreeNode * constPart){
  TreeNode* constPartExp = constPart -> child;
  TreeNode* id;
  TreeNode* content;
  while(constPartExp != NULL){
    id = constPartExp -> child;
    content = id -> sibling;
    int def_line = id -> lineno;
    content -> type = type_check(getNodeKindString(content -> nodekind));
    id -> type = content -> type;
    fprintf(stderr,"%s\n",getNodeKindString(content -> nodekind));
    symbolNode constNode = new_symbol_node(id->tokenString, def_line, Const, 0, content -> type);
    insert_symbol(constNode);
    constPartExp = constPartExp -> sibling;
  }
  return 0;
}

int look_type_part(TreeNode * typePart){
	TreeNode* typeDefinition = typePart -> child;
  fprintf(stderr,"looktypepart0\n");
	TreeNode* name;
	TreeNode* typeDecl;	
  symbolNode node ;
	while(typeDefinition != NULL){
    //fprintf(stderr,"looktypepart0.3\n");
		name = typeDefinition -> child;
    //fprintf(stderr,"looktypepart0.5\n");
		typeDecl = name -> sibling;
    //fprintf(stderr,"looktypepart1\n");
    
    if(strcmp(getNodeKindString(typeDecl->child->nodekind),"SIMPLE_TYPE_DECL") == 0){
		  node = new_symbol_node(name -> tokenString, name->lineno, Type, 0, type_check(name->sibling->child->tokenString));//??????????
		  insert_symbol(node);
    }
    else if(strcmp(getNodeKindString(typeDecl->child->nodekind),"ARRAY_TYPE_DECL") == 0){
        TreeNode* start = typeDecl -> child -> child;
        TreeNode* end = start -> sibling;
        TreeNode* eleType = typeDecl ->child -> sibling -> child;
        //node = new_symbol_node(name->tokenString, name->lineno, Type, )
    }
    else if(strcmp(getNodeKindString(typeDecl->child->nodekind),"RECORD_TYPE_DECL") == 0){

    }
    typeDefinition = typeDefinition -> sibling;
	}
  //fprintf(stderr,"%s  %d, %d\n",node->name,Type, node->type_const_arrayType);
	return 0;
}

int look_var_part(TreeNode * varPart){
	int typeName, isArray=0;
	TreeNode * varDecl = varPart -> child;
	while(varDecl != NULL){
		TreeNode * nameList = varDecl -> child;
    //fprintf(stderr,"haha\n");
    TreeNode* typeDecl = nameList -> sibling;
		TreeNode * typeNode = nameList -> sibling -> child;
    fprintf(stderr,"%s\n",getNodeKindString(typeDecl->nodekind));
		TreeNode * idList = nameList -> child;//就是ID
    //fprintf(stderr,"haha\n");
    if(strcmp(getNodeKindString(typeDecl->nodekind),"ARRAY_TYPE_DECL") == 0)
      isArray = 1;
    else
		  typeName = type_check(typeNode -> tokenString);
    fprintf(stderr,"typeName = %d\n",typeName);
    /*变量不是定义为了基本类型*/
    if(typeName == -1){
      //fprintf(stderr,"haha\n");
      typeName = get_type_by_name(typeNode -> tokenString);
     // fprintf(stderr, "typeName is %d\n",typeName);
      if(typeName == Type){
        symbolNode thisNode = st_lookup(now, typeNode -> tokenString);
        if(thisNode != NULL){
          //fprintf(stderr,"this Node %s,%d,%d\n",thisNode->name,thisNode->type,thisNode->type_const_arrayType);
          typeName = thisNode -> type_const_arrayType;
          //fprintf("%s\n",typeNode->tokenString);
          free(typeNode -> tokenString);
          typeNode->tokenString = (char*)malloc(sizeof(char)* (strlen (type_string(thisNode -> name)) + 1));
          strcpy(typeNode->tokenString,type_string(thisNode->type_const_arrayType));
        }
        else 
          return -1;
      }
      else
        return -1;
    }
    symbolNode node;
    //fprintf(stderr,"5\n");
		while(idList != NULL){
      if(isArray == 0){
        fprintf(stderr,"var_part_2\n");
        node = new_symbol_node(idList -> tokenString, idList->lineno, typeName, 0, 0);
        //fprintf(stderr,"6\n");
        idList -> type = typeName;
        typeNode -> type= typeName;
        //printf("type is %d", idList -> type);
        fprintf(stderr,"6.5\n");
			  insert_symbol(node);  //返回-1怎么办？？？？？？？
        fprintf(stderr,"7\n");
        add_loc_by_type(typeName,1);//为简单类型分配空间
        fprintf(stderr,"7.5\n");
      }
      else{
        fprintf(stderr,"8\n");
        TreeNode* start = typeDecl -> child -> child;
        TreeNode* end = start -> sibling;
        TreeNode* eleType = typeDecl ->child -> sibling -> child;
        idList -> type = Array;
        typeNode -> type= Array;
        fprintf(stderr,"idList type %d, typenode type %d",idList -> type,typeNode -> type);
        int startIndex = str2int(start->tokenString);
        int endIndex = str2int(end->tokenString);
        node = new_symbol_node(idList->tokenString, idList->lineno, Array, endIndex-startIndex+1, type_check(eleType->tokenString));
        add_loc_by_type(type_check(eleType->tokenString), endIndex-startIndex+1);//分配内存
      }
      idList = idList -> sibling;
		}//end of while
    //fprintf(stderr,"var_part_8\n");
		varDecl = varDecl -> sibling;
	}//end of outer while
  return 0;
}

int look_routine_part(TreeNode* routinePart){
  TreeNode* funcOrProcDecl = routinePart -> child;
  //TreeNode* 
  while(funcOrProcDecl != NULL){
    if(strcmp(getNodeKindString(funcOrProcDecl->nodekind),"FUNCTION_DECL") == 0){
      //fprintf(stderr,"func\n");
      look_func_decl(funcOrProcDecl);
    }
    else if(strcmp(getNodeKindString(funcOrProcDecl->nodekind),"PROCEDURE_DECL") == 0){
      //fprintf(stderr,"proc\n");
      look_proc_decl(funcOrProcDecl);
    }
    else
      return -1;
    funcOrProcDecl = funcOrProcDecl -> sibling;
  }
  return 0;  
}

symbolNode look_array_decl(char* name, int size, int type){
 // new_symbol_node(name, int def_line, int type, int length, int type_const_arrayType);
}

int look_params(TreeNode* parameters){//函数的参数分析
  TreeNode* paraType = parameters -> child;
  TreeNode* nameList;
  TreeNode* type;
  //fprintf(stderr,"look params-1\n");
  while(paraType != NULL){
    nameList = paraType -> child;
    type = nameList -> sibling -> child;
    TreeNode* id = nameList ->child;
    while(id != NULL){
      //fprintf(stderr,"look params1\n");
     // fprintf(stderr,"%s %d",type->tokenString)
      id->type = type_check(type->tokenString);
      type -> type = id->type;
      //fprintf(stderr,"look params2\n");
      symbolNode node = new_symbol_node(id->tokenString, id->lineno, type_check(type->tokenString), 0, 0);
      insert_symbol(node);
      //fprintf(stderr,"look params3\n");
      id = id->sibling;
    }
    paraType = paraType -> sibling;
  }
  return 0;
}
/*解析一个函数function*/
int look_func_decl(TreeNode* funcOrProcDecl){
  TreeNode* func_head = funcOrProcDecl->child;
  TreeNode* routine = func_head -> sibling;
  TreeNode* id = func_head -> child;
  TreeNode* parameters = id->sibling;
  TreeNode* return_type = parameters->sibling->child;
  char * name;
  name = (char*)malloc(sizeof(char)*(strlen(id->tokenString)+1));
  strcpy(name, id->tokenString);//函数名
  //                                函数名    行号                    符号类型  数组长度无效    返回值的类型
  symbolNode node = new_symbol_node(name, func_head->child->lineno, Function, 0, type_check(return_type -> tokenString));
  symbolNode* func_bucket;
  //fprintf(stderr,"look_func_decl1\n");  
  func_bucket = build_sym_tab(func_bucket);//建立一个新的symbol table，自动初始化
 // fprintf(stderr,"now1 = %d",now);
  now = func_bucket;//当前bucket的指针指向函数的bucket
  //fprintf(stderr,"now2 = %d",now);
  //fprintf(stderr,"look_func_decl1.5\n"); 
  symbolNode return_value = new_symbol_node(name, return_type->lineno, type_check(return_type->tokenString), 0,0); 
  //fprintf(stderr,"look_func_decl1.7\n"); 
  add_loc_by_type(type_check(return_type->tokenString),1);//把memloc加一个值，给返回值腾空间
  //fprintf(stderr,"look_func_decl2\n"); 
  insert_symbol(return_value);//把和函数名相同的返回值加入到符号表
  //fprintf(stderr,"look_func_decl3\n"); 
  look_params(parameters);
  return_type -> type = type_check(return_type->tokenString);
  //fprintf(stderr,"look_func_decl4\n"); 
  semantic_routine(routine);
  return 0;
}
/*解析一个函数producre*/
int look_proc_decl(TreeNode* funcOrProcDecl){
  TreeNode* procedure_head = funcOrProcDecl->child;
  TreeNode* routine = procedure_head -> sibling;
  //fprintf(stderr,"look_proc_decl3\n"); 
  TreeNode* id = procedure_head -> child -> sibling;
  //fprintf(stderr,"look_proc_decl4\n"); 
  TreeNode* parameters = id->sibling;
  //fprintf(stderr,"look_proc_decl5\n"); 
  //TreeNode* return_type = parameters->sibling->child;
  //fprintf(stderr,"look_proc_decl6\n"); 
  char * name;
  name = (char*)malloc(sizeof(char)*(strlen(id->tokenString)+1));
  //fprintf(stderr,"look_proc_decl1"); 
  strcpy(name, id->tokenString);//函数名
  //                                函数名    行号   符号类型  数组长度无效 
  symbolNode node = new_symbol_node(name, id->lineno, Procedure, 0, 0);
  symbolNode* proc_bucket; 
  //fprintf(stderr,"look_proc_decl2"); 
  proc_bucket = build_sym_tab(proc_bucket);//建立一个新的symbol table，自动初始化
  now = proc_bucket;//当前bucket的指针指向函数的bucket
  look_params(parameters);  
  semantic_routine(routine);
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
  return 0;
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
  //fprintf(stderr,"insert_symbol1\n");
	symbolNode which = *(now + hashValue);//桶中的第hashValue个位置
	symbolNode beforeWhich = which;
  //fprintf(stderr,"which is %d\n",which);
	/*以下为比较有没有重复定义*/
	while(which != NULL){
		beforeWhich = which;
		if(strcmp(name,which -> name) == 0){
			fprintf(stderr, REDEFINE, name, -2);//变量重复定义，%s变量名,%d行号
			return -1;
		}
    //fprintf(stderr,"insert_symbol2\n");
		which = which -> nextNode;
	}
	//which = (symbolNode)malloc(sizeof(struct symbolNodeCon));
  if(beforeWhich == NULL)
    (*(now + hashValue)) = node;
  else 
	  beforeWhich -> nextNode = node;
	return 0;
}

symbolNode st_lookup(symbolNode* node, char* name){
  int hashValue = hash(name);
  symbolNode thisLine = *(node + hashValue);
  while(thisLine != NULL){
    if(strcmp(thisLine -> name,name ) == 0){
      return thisLine;
    }
    thisLine = thisLine -> nextNode;
  }
  return NULL;
}

symbolNode new_symbol_node(char* name, int def_line, int type, int length, int type_const_arrayType){
  //fprintf(stderr,"new_symbol_node-1\n");
	symbolNode node = (symbolNode)malloc(sizeof(struct symbolNodeCon));
  //fprintf(stderr,"new_symbol_node0\n");
  node->name = (char*)malloc(sizeof(strlen(name)+1));
	strcpy(node->name, name);	
	node -> type = type;
  //fprintf(stderr,"new_symbol_node1\n");
	lineList list = (lineList)malloc(sizeof(struct lineListCon));
	list -> line = def_line;
	list -> next = NULL;
  //fprintf(stderr,"new_symbol_node2\n");
	node -> lines = list;
	node -> length = length;
	node -> type_const_arrayType = type_const_arrayType;
  node -> nextNode = NULL;
  node -> nextBucket = NULL;
  //fprintf(stderr,"new_symbol_node3\n");
	return node;
}

int semantic_routine_head(TreeNode* routineHead){
  TreeNode* labelPart = routineHead -> child;
  TreeNode* constPart = labelPart -> sibling;
  TreeNode* typePart = constPart -> sibling;
  TreeNode* varPart = typePart -> sibling;
  TreeNode* routinePart = varPart -> sibling;
  fprintf(stderr,"3\n");
  look_const_part(constPart);
  fprintf(stderr,"3.5\n");
  look_type_part(typePart);
  fprintf(stderr,"3.6\n");
  look_var_part(varPart);
  fprintf(stderr,"4\n");
  look_routine_part(routinePart);
  return 0;
}
int semantic_routine_stmt_list(TreeNode* routineStmt){
  
  return 0;
}

int semantic_routine(TreeNode* routine){
  TreeNode* routineHead = routine -> child;
	TreeNode* routineStmt = routineHead -> sibling;
  fprintf(stderr,"1\n");
	semantic_routine_head(routineHead);
  fprintf(stderr,"2\n");
	semantic_routine_stmt_list(routineStmt);
}

int semantic_analysis(TreeNode* root){
  now = &buckets[0];
  init_bucket(buckets);
	TreeNode* routine = root -> child -> sibling;
	semantic_routine(routine);
  return 0;
}






