#include <string.h>
#include "symbol.h"

extern TreeNode * root;
symbolNode *now = NULL;//指向桶的起始地址的指针
int lineNum;

symbolNode buckets[BUCKET_SIZE+1];//多余一个空出，有其他用处
int layerNum = 0;

void print_symbol_table(symbolNode* now){
		symbolNode node;
		int i;
		printf("---------------------------------------------------------------\n");
		for(i=0;i<BUCKET_SIZE;i++){
			node = (*(now+i));
      if(node != NULL){
			  printf("%d   name=%s, type=%s, length=%d, another_type=%s lineno=%d memloc=%d\n ",i,node->name, type_string(node->type), node->length, type_string(node->type_const_arrayType), node->lines->line, node->memloc);
        while(node->nextNode != NULL){
          node = node -> nextNode;
          printf("%d   name=%s, type=%s, length=%d, another_type=%s lineno=%d memloc=%d\n",i,node->name, type_string(node->type), node->length, type_string(node->type_const_arrayType), node->lines->line, node->memloc);
        }
      }
		}
		printf("nowBucket = %ld\n",(long)now);
    printf("memloc = %ld\n",(long)((*(now+BUCKET_SIZE))->memloc));
		printf("nextBucket = %ld\n",(long)((*(now+BUCKET_SIZE))->nextBucket));
		printf("--------------------------------------------------------------\n");
}
/*获取表达式的类型*/
int get_expression_type(TreeNode* exp){
  //printf("dd%s\n",getNodeKindString(exp -> child -> nodekind));
  return exp->type = get_sonex_type(exp->child);
}
int get_sonex_type(TreeNode* exp){
  char* nodekind = getNodeKindString(exp -> nodekind);
  //加减乘除
	//printf("dd\n");
  if(strcmp(nodekind,"EXP_PLUS") == 0 || strcmp(nodekind,"EXP_MINUS")==0 || strcmp(nodekind,"EXP_MUL")==0 || strcmp(nodekind,"EXP_DIV")==0 || strcmp(nodekind,"EXP_MOD")==0){
    return exp->type = get_exp_cal_type(exp);
  }
  //不等式
  else if(strcmp(nodekind,"EXP_GT") == 0 || strcmp(nodekind,"EXP_LT") == 0 || strcmp(nodekind,"EXP_LE") == 0 || strcmp(nodekind,"EXP_GE") == 0 || strcmp(nodekind,"EXP_EQUAL") == 0 || strcmp(nodekind,"EXP_UNEQUAL") == 0){
    if(get_exp_cal_type(exp) != -1){
      return exp->type = Boolean;
    }
  }
  else if(strcmp(nodekind,"EXP_AND") == 0 || strcmp(nodekind,"EXP_OR") == 0){
    assert(exp->nChild == 2);
		//printf("today\n");
    TreeNode* left = exp->child;
//    TreeNode* right = left ->sibling->sibling;
    TreeNode* right = left ->sibling;
		int leftType = get_sonex_type(left);
		int rightType = get_sonex_type(right);
    if(leftType == Boolean && rightType == Boolean){
      return exp->type = Boolean;
    }
    else
      return -1;
  }
  else if(strcmp(nodekind,"ID") == 0){//ID的类型
    symbolNode thisNode = st_lookup(now, exp->tokenString);
    lineNum = exp -> lineno;
    if(thisNode == NULL){
      fprintf(ERR,NO_SUCH_SYMBOL,exp->lineno,exp->tokenString);
      return -1;
    }
    int type = thisNode -> type;
		if(type == 10 || type == 11)//函数或者过程
			type = thisNode -> type_const_arrayType;
    return exp->type = type;
  }
  else if(strcmp(nodekind,"SYS_CON") == 0){
    lineNum = exp -> lineno;
    if(strcmp(exp -> tokenString,"true") == 0 || strcmp(exp -> tokenString,"false") == 0)
      return exp->type = Boolean;
		else if(strcmp(exp -> tokenString,"maxint") == 0)
			return exp->type = Integer;
    return -1;
  }
  else if(strcmp(nodekind,"FACTOR") == 0){
    TreeNode* id;
    TreeNode* argsList;
    id = exp -> child;
		int count = 0;//参数个数
    argsList = id ->sibling;
		TreeNode* expression = argsList->child;
		while(expression != NULL){
			count ++;
		  expression -> type = get_expression_type(expression);
		  expression = expression -> sibling;
		}
		if(strcmp(getNodeKindString(id -> nodekind),"SYS_FUNCT" ) == 0){
			if(count < 1){
				fprintf(ERR,TOO_LITTLE_ARGS2, id->lineno);
				return -1;
			}
			else if(count > 1){
				fprintf(ERR,TOO_MANY_ARGS2, id->lineno);
				return -1;
			}

			expression = argsList->child;
			expression->type = get_expression_type(expression);
			if(strcmp(id -> tokenString,"abs" ) == 0){
				id -> type = expression ->type;
			}
			else if(strcmp(id -> tokenString,"sqr" ) == 0){
				id -> type = expression ->type;
			}
			else if(strcmp(id -> tokenString,"sqrt" ) == 0){
				id -> type = Real;
			}
			else if(strcmp(id -> tokenString,"odd" ) == 0){
				id -> type = Boolean;
			}
			else if(strcmp(id -> tokenString,"succ" ) == 0){
				id -> type = expression ->type;
			}
			else if(strcmp(id -> tokenString,"pred" ) == 0){
				id -> type = expression ->type;
			}
			else if(strcmp(id -> tokenString,"ord" ) == 0){
				id -> type = Integer;
			}
			else if(strcmp(id -> tokenString,"chr" ) == 0){
				id -> type = Char;
			}
			else{
				fprintf(ERR, NO_SUCH_SYMBOL, id->lineno, id->tokenString);
				return -1;
			}
			return exp->type = id->type;
		}
		else if(strcmp(id->tokenString,"-") == 0){//负号
			if(argsList == NULL){
				fprintf(ERR,TOO_LITTLE_ARGS,id->lineno);
			}
			return exp->type = get_sonex_type(argsList);//factor 又挂了factor
		}
		else{//不是系统函数
		  symbolNode func = st_lookup(now,id->tokenString);
			if(func == NULL){//找不到这个函数
				fprintf(ERR,  NO_SUCH_SYMBOL, id->lineno, id->tokenString);
			}
		  symbolNode* temp = now;
		  while(func->type != Function){
		    temp = (*(temp+BUCKET_SIZE))->nextBucket;
		    if(temp == NULL){
		      //printf("y");
		      break;
		    }
		    func = st_lookup(temp,id->tokenString);
		  }
		  if(func->type != Function){
		    fprintf(ERR, NO_SUCH_SYMBOL,id->lineno,id->tokenString);
		  }
		  exp -> type = func->type_const_arrayType;

		  return exp->type;
		}
  }
  else{
		lineNum = exp -> lineno;
    return exp->type = type_check(getNodeKindString(exp -> nodekind));
  }
  return 0;
}
int get_exp_cal_type(TreeNode* exp){
  TreeNode* child1 = exp -> child;
  TreeNode* child2 = child1 -> sibling;
  child1 -> type = get_sonex_type(child1);
  child2 -> type = get_sonex_type(child2);
  if(child1 -> type == child2 -> type){
    return child1->type;
  }
  else if((child1->type == 2 || child1->type == 3) && (child2->type == 2 || child2->type == 3)){
    return 3;
  }
  else{
    fprintf(ERR, TYPEMIXED, lineNum);
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

void add_loc_by_type(int type, int count, int pos){
  int size = 0;
  //fprintf(stderr,"now = %d,type = %d",now,type);
  switch(type){
  case Char:size=1;break;
  case Integer:size=4;break;
  case Real:size=4;break;
  case Boolean:size=1;break;
  case String:size=256;break;
  }

  (*(now+pos))->memloc += size*count;
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
  default : return (char*)("unknown");break;
  }
}

int find_expression_type(TreeNode* expression){
  return -1;
}

/*根据符号名得到变量的类型，没有找到这个符号就返回-1*/
int get_type_by_name(symbolNode* node, char * name){
	symbolNode findNode = st_lookup(node,name);	
	if(findNode == NULL)
  	return -1;//没有这个定义
	else
		return findNode -> type;
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
    symbolNode constNode = new_symbol_node(id->tokenString, def_line, Const, 0, content -> type);
    int succeed = insert_symbol(constNode);
    if(succeed == -1){
      //printf("aa");
      fprintf(ERR,REDEFINE,constNode->lines->line,constNode->name);
      //printf("aa");
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
		name = typeDefinition -> child;
		typeDecl = name -> sibling;
		int type = look_type_decl(typeDecl);
		node = new_symbol_node(name -> tokenString, name->lineno, Type, 0, type);
		int succeed = insert_symbol(node);
		if(succeed == -1){
      fprintf(ERR,REDEFINE,node->lines->line,node->name);
			return -1;
    }

		name -> type = Type;
    typeDefinition = typeDefinition -> sibling;
	}
	return 0;
}

int look_simple_type_decl(TreeNode* decl){
	TreeNode* subDecl = decl -> child;
	while(subDecl != NULL){
		if(strcmp(getNodeKindString(subDecl->nodekind),"SYS_TYPE") == 0){//SYS_TYPE
			//printf("integer\n");
			return decl -> type = subDecl->type = type_check(subDecl->tokenString);
		}
		else if(strcmp(getNodeKindString(subDecl->nodekind),"ID") == 0){//ID
			int type = get_type_by_name(now, subDecl->tokenString);
			if(type == -1){
				fprintf(ERR, NO_SUCH_SYMBOL, subDecl->lineno, subDecl->tokenString);
				return -1;
			}
		}
		else if(strcmp(getNodeKindString(subDecl->nodekind),"INTEGER") == 0){//const_value DOTDOT const_value
			TreeNode* maxIndex = subDecl ->sibling;
			if(maxIndex != NULL){
				subDecl->type = type_check(getNodeKindString(subDecl->nodekind));
				maxIndex->type = type_check(getNodeKindString(maxIndex->nodekind));
				return decl->type = subDecl->type;
			}
		}
		else{
			return -1;
		}
		subDecl = subDecl -> sibling;
	}
	return -1;
}

int look_array_type_decl(TreeNode* decl){
	TreeNode* left,*right;
	left = decl -> child;
	right = left -> sibling;
	look_type_decl(left);
	look_type_decl(right);
	return decl ->type = Array;//decl->type = right->type;
}

int look_record_type_decl(TreeNode* decl){
	TreeNode* field = decl ->child;
	while (field != NULL){
		TreeNode* nameList = field ->child;
		TreeNode* id = nameList ->child;
		TreeNode* typeDecl = nameList ->sibling;	
		int type = look_type_decl(typeDecl);
		while(id != NULL){
			id -> type = type;
			id = id -> sibling;
		}
		field = field -> sibling;
	}
	return Record;
}

int look_type_decl(TreeNode* decl){
	if(strcmp(getNodeKindString(decl->nodekind),"SIMPLE_TYPE_DECL") == 0){
		return look_simple_type_decl(decl);
	}
	else if(strcmp(getNodeKindString(decl->nodekind),"ARRAY_TYPE_DECL") == 0){
		return look_array_type_decl(decl);
	}
	else if(strcmp(getNodeKindString(decl->nodekind),"RECORD_TYPE_DECL") == 0){
		return look_record_type_decl(decl);
	}
	return -1;
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
		TreeNode * idList = nameList -> child;//就是ID
    if(strcmp(getNodeKindString(typeDecl->nodekind),"ARRAY_TYPE_DECL") == 0){
      isArray = 1;
			isRecord = 0;
		}
    else if(strcmp(getNodeKindString(typeDecl->nodekind),"RECORD_TYPE_DECL") == 0){
      isRecord = 1;
			isArray = 0;
    }
    else{
			isRecord = 0;
			isArray = 0;
		  typeName = type_check(typeNode -> tokenString);
		}
    //fprintf(stderr,"typeName = %d\n",typeName);

    /*变量不是定义为了基本类型*/
    if(typeName == -1){
      //fprintf(stderr,"haha\n");
      typeName = get_type_by_name(now,typeNode -> tokenString);
     // fprintf(stderr, "typeName is %d\n",typeName);
      if(typeName == Type){
        symbolNode thisNode = st_lookup(now, typeNode -> tokenString);
        if(thisNode != NULL){
          typeName = thisNode -> type_const_arrayType;
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
    //printf("isArray = %d,isRecord = %d\n",isArray,isRecord);
		while(idList != NULL){
      if(isArray == 1){//数组声明
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
        add_loc_by_type(type_check(eleType->tokenString), endIndex-startIndex+1, BUCKET_SIZE);//分配内存
        int pos = hash(idList->tokenString);
        (*(now+pos))->memloc = (*(now+BUCKET_SIZE))->memloc;
      }
      else if(isRecord == 1){//记录声明
        //printf("dd\n");
        node = new_symbol_node(idList->tokenString, idList->lineno, Record, 0, 0);//创建record的symbol node
				idList->type = Record;
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
            add_loc_by_type(name->type,1, BUCKET_SIZE);//分配空间
            int pos = hash(name->tokenString);
            (*(now+pos))->memloc = (*(now+BUCKET_SIZE))->memloc;
            name = name -> sibling;
          }
          fieldDecl = fieldDecl -> sibling;
        }
        symbolNode * temp = now;
        now = (*(now+BUCKET_SIZE)) -> nextBucket;
        (*(now+BUCKET_SIZE)) -> memloc += (*(temp+BUCKET_SIZE)) -> memloc;
      }
      else{//普通变量声明
        node = new_symbol_node(idList -> tokenString, idList->lineno, typeName, 0, 0);
        idList -> type = typeName;
        typeNode -> type= typeName;

			  int succeed = insert_symbol(node);  //返回-1怎么办则重复定义
        if(succeed == -1){
          fprintf(ERR,REDEFINE,node->lines->line,node->name);
        }
        add_loc_by_type(typeName,1, BUCKET_SIZE);//为简单类型分配空间
        int pos = hash(idList->tokenString);
        (*(now+pos))->memloc = (*(now+BUCKET_SIZE))->memloc;
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
	return NULL;
}

/*函数参数部分的扫描*/
int look_params(TreeNode* parameters){//函数的参数分析
	int count = 0;
  TreeNode* paraType = parameters -> child;
  TreeNode* nameList;
  TreeNode* type;
  //fprintf(stderr,"look params-1\n");
  while(paraType != NULL){
    nameList = paraType -> child;
    type = nameList -> sibling -> child;
    TreeNode* id = nameList ->child;
    while(id != NULL){
      id->type = type_check(type->tokenString);
      type -> type = id->type;
      //fprintf(stderr,"look params2\n");
      symbolNode node = new_symbol_node(id->tokenString, id->lineno, type_check(type->tokenString), 0, 0);
      int succeed = insert_symbol(node);
      if(succeed == -1){
       fprintf(ERR,REDEFINE,node->lines->line,node->name);
				return -1;
      }
			count ++;//记录有几个参数
      add_loc_by_type(type_check(type->tokenString),1, BUCKET_SIZE);
      int pos = hash(id->tokenString);
      (*(now+pos))->memloc = -(*(now+BUCKET_SIZE))->memloc-4;
      //fprintf(stderr,"look params3\n");
      id = id->sibling;
    }
    paraType = paraType -> sibling;
  }
	(*(now+BUCKET_SIZE))->memloc = 0;
	//now = (*(now+BUCKET_SIZE))->nextBucket;
  return count;
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
      //fprintf(stderr,"aa");
      fprintf(ERR,REDEFINE,node->lines->line,node->name);
      //fprintf(stderr,"aa\n");
  }
  symbolNode* func_bucket = NULL;
  //fprintf(stderr,"look_func_decl1\n");
	int count = 0;//函数有几个参数
  func_bucket = build_sym_tab(func_bucket);//建立一个新的symbol table，自动初始化
  node -> nextBucket = func_bucket;
 // fprintf(stderr,"now1 = %d",now);
  now = func_bucket;//当前bucket的指针指向函数的bucket
  //fprintf(stderr,"now2 = %d",now);
  symbolNode return_value = new_symbol_node(name, return_type->lineno, type_check(return_type->tokenString), 0,0);
  succeed = insert_symbol(return_value);//把和函数名相同的返回值加入到符号表
  //fprintf(stderr,"look_func_decl1.7\n");
  add_loc_by_type(type_check(return_type->tokenString),1, BUCKET_SIZE);//把memloc加一个值，给返回值腾空间
  int pos = hash(name);
  (*(now+pos))->memloc = -(*(now+BUCKET_SIZE))->memloc-4;
  if(succeed == -1){
      //fprintf(stderr,"aa");
      fprintf(ERR,REDEFINE,return_value->lines->line,return_value->name);
      //fprintf(stderr,"aa");
    }
  //fprintf(stderr,"look_func_decl3\n");
   count = look_params(parameters);
	node -> length = count;
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
  char * name;
	int count=0;
  name = (char*)malloc(sizeof(char)*(strlen(id->tokenString)+1));
  //fprintf(stderr,"look_proc_decl1");
  strcpy(name, id->tokenString);//函数名
  //                                函数名    行号   符号类型  数组长度无效
  symbolNode node = new_symbol_node(name, id->lineno, Procedure, 0, 0);
  int succeed = insert_symbol(node);
  if(succeed == -1){
      //printf("aa");
      fprintf(ERR,REDEFINE,node->lines->line,node->name);
      //printf("aa");
  }
  //printf("now == == %d\n",(long)(now));
  symbolNode* proc_bucket = NULL;
  //fprintf(stderr,"look_proc_decl2");
  proc_bucket = build_sym_tab(proc_bucket);//建立一个新的symbol table，自动初始化
  node -> nextBucket = proc_bucket;
  now = proc_bucket;//当前bucket的指针指向函数的bucket
  count = look_params(parameters);
	node -> length = count;
  semantic_routine(routine);
  return 0;
}

int look_stmt(TreeNode* stmt){
  TreeNode* subStmt;
  while(stmt != NULL){
    subStmt = stmt -> child;
    /*判断是哪种语句*/
    if( strcmp(getNodeKindString(subStmt->nodekind),"PROC_STMT") == 0){//有了
      look_proc_stmt(subStmt);
    }
    else if( strcmp(getNodeKindString(subStmt->nodekind),"IF_STMT") == 0){//有了
      look_if_stmt(subStmt);
    }
    else if(strcmp(getNodeKindString(subStmt->nodekind),"ASSIGN_STMT") == 0){//有了
			//printf("dad\n");
      look_assign_stmt(subStmt);
      //printf("dd\n");
    }
    else if(strcmp(getNodeKindString(subStmt->nodekind),"WHILE_STMT") == 0){//有了
      look_while_stmt(subStmt);
    }
    else if(strcmp(getNodeKindString(subStmt->nodekind),"FOR_STMT") == 0){//有了
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
    else if(strcmp(getNodeKindString(subStmt->nodekind),"STMT_LIST") == 0){//有了
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
	int count = 0;
  TreeNode* func_name = subStmt -> child;
  TreeNode* func_params = func_name -> sibling;
	//symbolNode paramNode;
  if(func_params != NULL){
    TreeNode* param = func_params -> child;
    while(param != NULL){
			count ++;
			//paramNode = st_lookup(now, param);
      param -> type = get_expression_type(param);
      param = param -> sibling;
    }
  }
	func_name -> type = Procedure;
	symbolNode func = st_lookup(now, func_name->tokenString);
	//printf("a?\n");
	if(strcmp(getNodeKindString(func_name->nodekind),"ID") == 0){//普通函数
	 // printf("now = %d, %s\n",now,func_name->tokenString);
		if(func == NULL){
			//printf("a?\n");
			fprintf(ERR, NO_SUCH_SYMBOL, func_name->lineno, func_name->tokenString);
			return -1;
		}
		if(count > func->length){//参数太多
			fprintf(ERR,TOO_MANY_ARGS,func_name->lineno);
			return -1;
		}
		else if(count < func->length){//参数太少
			fprintf(ERR,TOO_LITTLE_ARGS,func_name->lineno);
			return -1;
		}
		else ;//参数个数对的

	}
	else if(strcmp(func_name->tokenString,"read") == 0){//系统函数
		symbolNode id = st_lookup(now, func_params->tokenString);
		if(id == NULL){
			fprintf(ERR,NO_SUCH_SYMBOL,func_params->lineno, func_params->tokenString);
			return -1;
		}
		func_params -> type = id->type;
		return 0;
	}
	else if(strcmp(func_name->tokenString,"write") == 0){//系统函数
		if(count > 1){
			fprintf(ERR,TOO_MANY_ARGS,func_name->lineno);
			return -1;
		}
		else if(count < 1){
			fprintf(ERR,TOO_LITTLE_ARGS,func_name->lineno);
			return -1;
		}
		return 0;
	}
	else if(strcmp(func_name->tokenString,"writeln") == 0){//系统函数
		if(count > 1){
			fprintf(ERR,TOO_MANY_ARGS,func_name->lineno);
			return -1;
		}
		else if(count < 1){
			fprintf(ERR,TOO_LITTLE_ARGS,func_name->lineno);
			return -1;
		}
		return 0;
	}
	else{//没这个函数
		fprintf(ERR, NO_SUCH_SYMBOL, func_name->lineno, func_name->tokenString);
		return -1;
	}
  subStmt -> type = func->type_const_arrayType;
  if(subStmt -> type >= 1 && subStmt -> type <= 11){
    //subStmt->nodekind =
  }
  return 0;
}
/*赋值表达式类型检查*/
int look_assign_stmt(TreeNode* subStmt){
  TreeNode* id = subStmt -> child;
  TreeNode* expression = id->sibling;
  TreeNode* index = NULL;
  if(expression -> sibling != NULL){//数组下表访问或者是record访问
    index = expression;
    expression = expression ->sibling;
		if(strcmp(getNodeKindString(id->nodekind),"ID") == 0){//record访问
			symbolNode recordSelf = st_lookup(now, id->tokenString);
			symbolNode attr = st_lookup(recordSelf->nextBucket, index->tokenString);
			index->type = attr->type;
		}
		else{
    	index -> type = get_expression_type(index);
		}
  }
  else{//正常变量
    index = NULL;
  }
	
	symbolNode idSymbol = st_lookup(now, id->tokenString);
	if(idSymbol == NULL){
		fprintf(ERR, NO_SUCH_SYMBOL, id->lineno, id->tokenString);
		return -1;
	}
  int variableType = idSymbol -> type;
  //printf("%s %d\n",id->tokenString, variableType);

  if(strcmp(getNodeKindString(id->nodekind),"ID") != 0){//写的不是变量
    fprintf(ERR, ILLEGAL_LEFT_VALUE,lineNum);
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
	else if(variableType == Record){
		variableType = index->type;
	}
  int expressionType = get_expression_type(expression);
  //printf("aa");
  if( expressionType != variableType && !((expressionType == Integer)&&(variableType==Real)) ){//变量类型和表达式类型不同
    fprintf(ERR, TYPEMIXED2,lineNum,type_string(variableType),type_string(expressionType));
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
  //printf("%s\n",getNodeKindString(expression->nodekind));
  if(get_expression_type(expression) == Boolean){
    //printf("a\n");
    look_stmt(stmt);
  }
  else{
    fprintf(ERR, TYPEMIXED2, lineNum, "boolean",type_string(expression->type));
    //look_stmt(stmt);
    return -1;
  }
  return 0;
}

int look_if_stmt(TreeNode* subStmt){
  TreeNode* expression = subStmt -> child;
  TreeNode* stmt1 = expression -> sibling;
  TreeNode* stmt2 = stmt1 -> sibling;
  expression->type = get_expression_type(expression);//表达式
  if(expression -> type != Boolean){
    fprintf(ERR, TYPEMIXED2, lineNum, "boolean", type_string(expression->type));
    return -1;
  }
  look_stmt(stmt1);//if语句
  look_stmt(stmt2);//else语句
  return 0;
}

int look_for_stmt(TreeNode* subStmt){
  //printf("c\n");
  TreeNode* id = subStmt->child;
  TreeNode* expression1 = id->sibling;
  TreeNode* expression2 = expression1 -> sibling -> sibling;
  TreeNode* stmt = expression2 -> sibling;
  symbolNode loopVar = st_lookup(now, id->tokenString);
  int varType = loopVar -> type;
  id->type = loopVar -> type;
  //printf("c\n");
  int exp1Type = get_expression_type(expression1);
  int exp2Type = get_expression_type(expression2);
  //printf("c\n");
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
    //printf("b\n");
    look_stmt(stmt);
    return 0;
  }
  return 0;
}
int look_repeat_stmt(TreeNode* subStmt){
  TreeNode* stmtList = subStmt -> child;
  TreeNode* expression = stmtList -> sibling;

  look_stmt_list_part(stmtList);
  int type = get_expression_type(expression);
  if(type != Boolean){
    fprintf(ERR,TYPEMIXED2,lineNum,"boolean",type_string(type));
  }
  return 0;
}
int look_goto_stmt(TreeNode* subStmt){//文法中没有label part的文法，所以自然goto语句也不能用
	fprintf(ERR, NO_GOTO);
  return -1;
}
int look_case_stmt(TreeNode* subStmt){
	TreeNode* expression;
	TreeNode* exprList;
	TreeNode* caseExpr;
	expression = subStmt -> child;
	exprList = expression ->sibling;
	caseExpr = exprList ->child;
	//printf("%s,%s\n",getNodeKindString(expression->nodekind),getNodeKindString(exprList->nodekind));
	int expressionType = get_expression_type(expression);
	while(caseExpr != NULL){
		TreeNode* left = caseExpr ->child;
		TreeNode* right = left -> sibling;
		int leftType = get_sonex_type(left);
		look_stmt(right);//冒号右面
		if(leftType != expressionType){
			fprintf(ERR, TYPEMIXED2, left->lineno, type_string(expression->type), type_string(leftType) );
		}
		caseExpr = caseExpr -> sibling;
	}
  return 0;
}
int look_compound_stmt(TreeNode* subStmt){
  //printf("a\n");
  look_stmt_list_part(subStmt);
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
		which = which -> nextNode;
	}
  if(beforeWhich == NULL)
    (*(now + hashValue)) = node;
  else
	  beforeWhich -> nextNode = node;
	return 0;
}

symbolNode st_lookup(symbolNode* node, char* name){
  int hashValue = hash(name);
  layerNum = 0;
  symbolNode thisLine;

  while(node != NULL){
		thisLine = *(node + hashValue);
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
	return look_stmt_list_part(routineStmt);
}

int semantic_routine(TreeNode* routine){
  TreeNode* routineHead = routine -> child;
	TreeNode* routineStmt = routineHead -> sibling;
	semantic_routine_head(routineHead);
	semantic_routine_stmt_list(routineStmt);
	return 0;
}

int semantic_analysis(TreeNode* root){
  now = &buckets[0];
  init_bucket(buckets);
	TreeNode* routine = root -> child -> sibling;
	semantic_routine(routine);
  return 0;
}

