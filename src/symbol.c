#include <string.h>
#include "symbol.h"

extern TreeNode * root;
symbolNode *now = NULL;//指向桶的起始地址的指针

symbolNode buckets[BUCKET_SIZE+1];//多余一个空出，有其他用处
int layerNum = 0;

void print_symbol_table(symbolNode* now){
		symbolNode node;
		int i;
		printf("-------------------------------------------------------\n");
		for(i=0;i<BUCKET_SIZE;i++){
			node = (*(now+i));
      if(node != NULL){
			  printf("%d   name=%s, type=%s, length=%d, another_type=%s lineno=%d\n",i,node->name, type_string(node->type), node->length, type_string(node->type_const_arrayType), node->lines->line);
        while(node->nextNode != NULL){
          node = node -> nextNode;
          printf("%d   name=%s, type=%s, length=%d, another_type=%s lineno=%d\n",i,node->name, type_string(node->type), node->length, type_string(node->type_const_arrayType), node->lines->line);
        }  
      }
		}
    printf("memloc = %d\n",(*(now+BUCKET_SIZE))->memloc);
		printf("-------------------------------------------------------\n");
}

int get_expression_type(TreeNode* exp){
  printf("%s\n",getNodeKindString(exp -> child -> nodekind));
  return exp->type = get_sonex_type(exp->child);
}
int get_sonex_type(TreeNode* exp){
  char* nodekind = getNodeKindString(exp -> nodekind);
  //加减乘除
  if(strcmp(nodekind,"EXP_PLUS") == 0 || strcmp(nodekind,"EXP_MINUS")==0 || strcmp(nodekind,"EXP_MUL")==0 || strcmp(nodekind,"EXP_DIV")==0 ){
    return exp->type = get_exp_cal_type(exp);
  }
  //不等式
  else if(strcmp(nodekind,"EXP_GT") == 0 || strcmp(nodekind,"EXP_LT") == 0 || strcmp(nodekind,"EXP_LE") == 0 || strcmp(nodekind,"EXP_GE") == 0 || strcmp(nodekind,"EQUAL") == 0 || strcmp(nodekind,"UNEQUAL") == 0){
    if(get_exp_cal_type(exp) != -1){
      return exp->type = Boolean;
    }
  }
  else if(strcmp(nodekind,"EXP_AND") == 0 || strcmp(nodekind,"EXP_AND") == 0){
    TreeNode* left = exp->child;
    TreeNode* right = left ->sibling->sibling;
    if(strcmp(getNodeKindString(left->nodekind),"SYS_CON")==0 && strcmp(getNodeKindString(right->nodekind),"SYS_CON") == 0){
      return exp->type = Boolean;
    }
    else
      return -1;
  }
  else if(strcmp(nodekind,"ID") == 0){//ID的类型
    symbolNode thisNode = st_lookup(now, exp->tokenString);
    if(thisNode == NULL){
      fprintf(ERR,NO_SUCH_SYMBOL,exp->lineno,exp->tokenString);
      return -1;
    }
    int type = thisNode -> type;
    return type;
  }
  else if(strcmp(nodekind,"SYS_CON") == 0){
    if(strcmp(exp -> tokenString,"true") == 0 || strcmp(exp -> tokenString,"false") == 0)
      return Boolean;
    return -1;
  }
  else{
    return type_check(getNodeKindString(exp -> nodekind));
  }
  return 0;
}
int get_exp_cal_type(TreeNode* exp){
  TreeNode* child1 = exp -> child;
  TreeNode* child2 = child1 -> sibling;
  child1 -> type = get_sonex_type(child1);
  child2 -> type = get_sonex_type(child2);
  if(child1 -> type == child2 -> type){
    printf("%d\n",child1->type);    
    return child1->type;
  }
  else if((child1->type == 2 || child1->type == 3) && (child2->type == 2 || child2->type == 3)){
    return 3;
  }
  else{
    fprintf(ERR, TYPEMIXED, -521);
    return -1;
  }
}

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
  //fprintf(stderr,"now = %d",(int)now);
  //fprintf(stderr,"now_bucketsieze = %d",(int)(*(now+BUCKET_SIZE)));
  
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
  case 1:return (char*)("char");break;
  case 2:return (char*)("integer");break;
  case 3:return (char*)("real");break;
  case 4:return (char*)("boolean");break;
  case 5:return (char*)("string");break;
  case 6:return (char*)("array");break;
  case 7:return (char*)("record");break;
  case 8:return (char*)("type");break;
  case 9:return (char*)("const");break;
  case 10:return (char*)("function");break;
  case 11:return (char*)("procedure");break;
  default : return (char*)("unknow");break;
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
    //fprintf(stderr,"%s\n",getNodeKindString(content -> nodekind));
    symbolNode constNode = new_symbol_node(id->tokenString, def_line, Const, 0, content -> type);
    int succeed = insert_symbol(constNode);
    if(succeed == -1){
      fprintf(ERR,REDEFINE,constNode->lines->line,constNode->name);
    }
    constPartExp = constPartExp -> sibling;
  }
  return 0;
}

/*type part 的查询。。。相当于宏定义*/
int look_type_part(TreeNode * typePart){
	TreeNode* typeDefinition = typePart -> child;
  //fprintf(stderr,"looktypepart0\n");
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
		  int succeed = insert_symbol(node);
      if(succeed == -1){
        fprintf(ERR,REDEFINE,node->lines->line,node->name);
      }
    }
    else if(strcmp(getNodeKindString(typeDecl->child->nodekind),"ARRAY_TYPE_DECL") == 0){
        TreeNode* start, *end, *eleType;
        start = typeDecl -> child -> child;
        end  = start -> sibling;
        eleType = typeDecl ->child -> sibling -> child;
        //node = new_symbol_node(name->tokenString, name->lineno, Type, )
    }
    else if(strcmp(getNodeKindString(typeDecl->child->nodekind),"RECORD_TYPE_DECL") == 0){
        
    }
    typeDefinition = typeDefinition -> sibling;
	}
  //fprintf(stderr,"%s  %d, %d\n",node->name,Type, node->type_const_arrayType);
	return 0;
}

/*变量部分的扫描*/
int look_var_part(TreeNode * varPart){
	int typeName, isArray=0, isRecord = 0;;
	TreeNode * varDecl = varPart -> child;
	while(varDecl != NULL){
		TreeNode * nameList = varDecl -> child;
    //fprintf(stderr,"haha\n");
    TreeNode* typeDecl = nameList -> sibling;
		TreeNode * typeNode = nameList -> sibling -> child;
    //printf("%s\n",getNodeKindString(typeDecl->nodekind));
		TreeNode * idList = nameList -> child;//就是ID
    //printf("%s\n",getNodeKindString(typeDecl->nodekind));
    if(strcmp(getNodeKindString(typeDecl->nodekind),"ARRAY_TYPE_DECL") == 0)
      isArray = 1;
    else if(strcmp(getNodeKindString(typeDecl->nodekind),"RECORD_TYPE_DECL") == 0){
      isRecord = 1;
    }
    else
		  typeName = type_check(typeNode -> tokenString);
    //fprintf(stderr,"typeName = %d\n",typeName);
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
          typeNode->tokenString = (char*)malloc(sizeof(char)* (strlen (type_string(thisNode -> type_const_arrayType)) + 1));
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
    //printf("isArray = %d,isRecord = %d\n",isArray,isRecord);
		while(idList != NULL){
      if(isArray == 1){
        //fprintf(stderr,"8\n");
        TreeNode* start = typeDecl -> child -> child;
        TreeNode* end = start -> sibling;
        TreeNode* eleType = typeDecl ->child -> sibling -> child;
        idList -> type = Array;
        typeNode -> type= Array;
        //fprintf(stderr,"idList type %d, typenode type %d",idList -> type,typeNode -> type);
        int startIndex = str2int(start->tokenString);
        int endIndex = str2int(end->tokenString);
        node = new_symbol_node(idList->tokenString, idList->lineno, Array, endIndex-startIndex+1, type_check(eleType->tokenString));
        int succeed = insert_symbol(node);
        if(succeed == -1){
          fprintf(ERR,REDEFINE,node->lines->line,node->name);
        }
        add_loc_by_type(type_check(eleType->tokenString), endIndex-startIndex+1);//分配内存
      }
      else if(isRecord == 1){
        //printf("dd\n");
        node = new_symbol_node(idList->tokenString, idList->lineno, Record, 0, 0);//创建record的symbol node
        
        int succeed = insert_symbol(node);
        if(succeed == -1){
          fprintf(ERR,REDEFINE,node->lines->line,node->name);
        }
        //printf("dd\n");
        node -> nextBucket = build_sym_tab(node -> nextBucket);//建立一个新的bucket
        //printf("dd\n");
        now = node -> nextBucket;//让now指向当前的bucket
        //printf("d\n");
        TreeNode* fieldDecl = typeDecl -> child;
        while(fieldDecl != NULL){
          TreeNode* nameList = fieldDecl -> child;
          TreeNode* typeDecl = nameList -> sibling ->child;
          TreeNode* name = nameList -> child;
          //printf("d\n");
          typeDecl -> type = type_check(typeDecl->tokenString);
          //printf("a\n");
          while(name != NULL){
            name -> type = typeDecl -> type;
            symbolNode ele = new_symbol_node(name->tokenString, name->lineno, name -> type, 0, 0);
            int succeed = insert_symbol(ele);
            if(succeed == -1){
              fprintf(ERR,REDEFINE,ele->lines->line,ele->name);
            }
            add_loc_by_type(name->type,1); 
            name = name -> sibling;      
          }
          fieldDecl = fieldDecl -> sibling;
        }
        symbolNode * temp = now;
        now = (*(now+BUCKET_SIZE)) -> nextBucket;
        (*(now+BUCKET_SIZE)) -> memloc += (*(temp+BUCKET_SIZE)) -> memloc;
      }
      else{
        //fprintf(stderr,"var_part_2\n");
        node = new_symbol_node(idList -> tokenString, idList->lineno, typeName, 0, 0);
        //fprintf(stderr,"6\n");
        idList -> type = typeName;
        typeNode -> type= typeName;
        //printf("type is %d", idList -> type);
        //fprintf(stderr,"6.5\n");
        
			  int succeed = insert_symbol(node);  //返回-1怎么办？？？？？？？
        if(succeed == -1){
          fprintf(ERR,REDEFINE,node->lines->line,node->name);
        }
        //fprintf(stderr,"7\n");
        add_loc_by_type(typeName,1);//为简单类型分配空间
        //fprintf(stderr,"7.5\n");
      }
      idList = idList -> sibling;
		}//end of while
    //fprintf(stderr,"var_part_8\n");
		varDecl = varDecl -> sibling;
	}//end of outer while
  return 0;
}

/*函数部分的扫描*/
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

/*函数参数部分的扫描*/
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
      int succeed = insert_symbol(node);
      if(succeed == -1){
       fprintf(ERR,REDEFINE,node->lines->line,node->name);
      }
      add_loc_by_type(type_check(type->tokenString),1);
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
  int succeed = insert_symbol(node);
  if(succeed == -1){
      fprintf(ERR,REDEFINE,node->lines->line,node->name);
  }
  symbolNode* func_bucket;
  //fprintf(stderr,"look_func_decl1\n");  
  func_bucket = build_sym_tab(func_bucket);//建立一个新的symbol table，自动初始化
  node -> nextBucket = func_bucket;
 // fprintf(stderr,"now1 = %d",now);
  now = func_bucket;//当前bucket的指针指向函数的bucket
  //fprintf(stderr,"now2 = %d",now);
  symbolNode return_value = new_symbol_node(name, return_type->lineno, type_check(return_type->tokenString), 0,0); 
  //fprintf(stderr,"look_func_decl1.7\n"); 
  add_loc_by_type(type_check(return_type->tokenString),1);//把memloc加一个值，给返回值腾空间
  //fprintf(stderr,"look_func_decl2\n"); 
  succeed = insert_symbol(return_value);//把和函数名相同的返回值加入到符号表
  if(succeed == -1){
      fprintf(ERR,REDEFINE,return_value->lines->line,return_value->name);
    }
  //fprintf(stderr,"look_func_decl3\n"); 
  look_params(parameters);
  return_type -> type = type_check(return_type->tokenString);
  //fprintf(stderr,"look_func_decl4\n"); 
  semantic_routine(routine);
  now = (*(func_bucket+BUCKET_SIZE))->nextBucket;
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
  int succeed = insert_symbol(node);
  if(succeed == -1){
      fprintf(ERR,REDEFINE,node->lines->line,node->name);
  }
  //printf("now == == %d\n",(long)(now));
  symbolNode* proc_bucket; 
  //fprintf(stderr,"look_proc_decl2"); 
  proc_bucket = build_sym_tab(proc_bucket);//建立一个新的symbol table，自动初始化
  node -> nextBucket = proc_bucket;
  now = proc_bucket;//当前bucket的指针指向函数的bucket
  look_params(parameters);  
  semantic_routine(routine);
  return 0;
}

int look_stmt(TreeNode* stmt){
  TreeNode* subStmt;
  while(stmt != NULL){
    subStmt = stmt -> child;
    /*判断是哪种语句*/
    if( strcmp(getNodeKindString(subStmt->nodekind),"PROC_STMT") == 0){
      look_proc_stmt(subStmt);
    }
    else if(strcmp(getNodeKindString(subStmt->nodekind),"ASSIGN_STMT") == 0){
      look_assign_stmt(subStmt);
      //printf("dd");
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
    stmt = stmt -> sibling;
  }
  return 0;
}
/*正式的语句部分*/
int look_stmt_list_part(TreeNode* stmtList){
  TreeNode* stmt = stmtList -> child;
  return look_stmt(stmt);
}


int look_proc_stmt(TreeNode* subStmt){
  return 0;  
}
/*赋值表达式类型检查*/
int look_assign_stmt(TreeNode* subStmt){
  TreeNode* id = subStmt -> child;
  TreeNode* expression = id->sibling;
  TreeNode* index = NULL;
  if(expression -> sibling != NULL){//数组下表访问
    index = expression;
    expression = expression ->sibling;
    index -> type = get_expression_type(index);
  }
  else{//正常变量
    index = NULL;
  }

  int variableType = get_type_by_name(id->tokenString);
  printf("%s %d\n",id->tokenString, variableType);

  if(strcmp(getNodeKindString(id->nodekind),"ID") != 0){//写的不是变量
    fprintf(ERR, ILLEGAL_LEFT_VALUE,-520);
    return -1;
  }
  if(variableType == -1){//变量不存在
    fprintf(ERR,NO_SUCH_SYMBOL, id->lineno,id->tokenString );
    return -1;
  }
  else if(variableType == Array){//变量类型为数组，则富节点的类型是数组元素的类型
    symbolNode ele = st_lookup(now, id->tokenString);
    variableType = ele -> type_const_arrayType;
    id -> type = variableType;
  }
  int expressionType = get_expression_type(expression);
  //printf("aa");
  if( expressionType != variableType && !((expressionType == Integer)&&(variableType==Real)) ){//变量类型和表达式类型不同
    fprintf(ERR, TYPEMIXED2,-519,type_string(variableType),type_string(expressionType));
    return -1;
  }
  else{
    id->type = variableType;
    subStmt -> type = id -> type;
    return 0;
  }
  return 0;  
}

int look_while_stmt(TreeNode* subStmt){
  TreeNode* expression = subStmt->child;
  TreeNode* stmt = expression->sibling;
  printf("%s\n",getNodeKindString(expression->nodekind));
  if(get_expression_type(expression) == Boolean){
    //printf("a\n");
    look_stmt(stmt);
  }
  else{
    fprintf(ERR, TYPEMIXED3, -518, type_string(expression->type));
    //look_stmt(stmt);
    return -1;
  }
  return 0;  
}

int look_for_stmt(TreeNode* subStmt){
  TreeNode* id = subStmt->child;
  TreeNode* expression1 = id->sibling;
  TreeNode* expression2 = expression1 -> sibling -> sibling;
  TreeNode* stmt = expression2 -> sibling;
  symbolNode loopVar = st_lookup(now, id);
  int varType = loopVar -> type;
  int exp1Type = get_expression_type(expression1);
  int exp2Type = get_expression_type(expression2);
  if(varType != Integer){//循环变量不是integer
    fprintf(ERR, TYPEMIXED2, id->lineno, "integer", type_string(varType));    
    return -1;
  }
  else if( exp1Type != Integer ){
    fprintf(ERR, TYPEMIXED2, id->lineno, "integer", type_string(exp1Type));    
    return -1;
  }
  else if( exp2Type != Integer ){
    fprintf(ERR, TYPEMIXED2, id->lineno, "integer", type_string(exp2Type));    
    return -1;
  }
  else {//正确的情况
    look_stmt(stmt);
    return 0;
  }
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
			//fprintf(stderr, REDEFINE, name, -2);//变量重复定义，%s变量名,%d行号
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
  layerNum = 0;
  symbolNode thisLine = *(node + hashValue);

  while(node != NULL){
    while(thisLine != NULL){
      if(strcmp(thisLine -> name,name ) == 0){
        return thisLine;
      }
      thisLine = thisLine -> nextNode;
    }
    node = (*(node + BUCKET_SIZE)) -> nextBucket;
    layerNum ++;
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
  //fprintf(stderr,"3\n");
  look_const_part(constPart);
  //fprintf(stderr,"3.5\n");
  look_type_part(typePart);
  //fprintf(stderr,"3.6\n");
  look_var_part(varPart);
  //fprintf(stderr,"4\n");
  look_routine_part(routinePart);
  return 0;
}
int semantic_routine_stmt_list(TreeNode* routineStmt){
  look_stmt_list_part(routineStmt);
}

int semantic_routine(TreeNode* routine){
  TreeNode* routineHead = routine -> child;
	TreeNode* routineStmt = routineHead -> sibling;
	semantic_routine_head(routineHead);
  //printf("dd\n");
	semantic_routine_stmt_list(routineStmt);
}

int semantic_analysis(TreeNode* root){
  now = &buckets[0];
  init_bucket(buckets);
	TreeNode* routine = root -> child -> sibling;
	semantic_routine(routine);
  return 0;
}






