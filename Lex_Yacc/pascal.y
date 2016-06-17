%{
	#include <stdio.h>
	#include <ctype.h>
	#include <stdlib.h>
	#include "util.h"
	#include "globals.h"
	#define YYSTYPE TreeNode*

	int totalLine;
	TreeNode * root;
	int hasError;
%}

%token AND
%token ARRAY
%token ASSIGN
%token BEGINN
%token CASE
%token CHAR
%token COLON
%token COMMA
%token CONST
%token DIV
%token DO
%token DOT
%token DOTDOT
%token DOWNTO
%token ELSE
%token END
%token EQUAL
%token FOR
%token FUNCTION
%token GE
%token GOTO
%token GT
%token ID
%token IF
%token INTEGER
%token LB
%token LE
%token LP
%token LT
%token MINUS
%token MOD
%token MUL
%token NOT
%token OF
%token OR
%token PLUS
%token PROCEDURE
%token PROGRAM
%token RB
%token READ
%token REAL
%token RECORD
%token REPEAT
%token RP
%token SEMI
%token STRING
%token SYS_CON
%token SYS_FUNCT
%token SYS_PROC
%token SYS_TYPE
%token THEN
%token TO
%token TYPE
%token UNEQUAL
%token UNTIL
%token VAR
%token WHILE

%%

program : program_head routine DOT {
			$$ = newTreeNode(N_PROGRAM);
			appendChild($$, $1);
			appendChild($$, $2);

			/*          N_PROGRAM
			 *			/		\
			 *			N_ID  	N_ROUTINE
			 */

			if (!hasError) hasError = 0;
			root = $$;
			totalLine = lineno;
		}
		| program_head routine error{
			printError("missing the <DOT> of the end of program");
		}
		| error {
			printError("syntax error");
		};

program_head : PROGRAM ID SEMI {
				$$ = $2;
				}
          	 | PROGRAM error SEMI{
			 	printError("missing <RPOGRAM NAME>");
			 }
			 | PROGRAM ID error{
			 	printError("missing ';'");
			 };

routine : routine_head routine_body {
			$$ = newTreeNode(N_ROUTINE);
			appendChild($$, $1);
			appendChild($$, $2);
			/*          	N_ROUTINE
			 *			/				\
			 *			N_ROUTINE_HEAD  	N_STMT_LIST
			 */

		}
        | routine_head error{
			printError("missing program body");
		};

sub_routine : routine_head routine_body {
				$$ = newTreeNode(N_ROUTINE);
				appendChild($$, $1);
				appendChild($$, $2);
			/*          	N_ROUTINE	  //the same as N_ROUTINE
			 *			/				\
			 *			N_ROUTINE_HEAD  	N_STMT_LIST
			 */

			}
            | routine_head error{
				printError("missing function body");
			};

routine_head : label_part const_part type_part var_part routine_part {
				 $$ = newTreeNode(N_ROUTINE_HEAD);
				 appendChild($$, $1);
				 appendChild($$, $2);
				 appendChild($$, $3);
				 appendChild($$, $4);
				 appendChild($$, $5);

				/*          								N_ROUTINE_HEAD
				 *			/				|				|	        |                 |           	\
				 *			N_LABEL_PART   N_CONST_PART  N_TYPE_PART  N_VAR_PART  N_ROUTINE_PART N_ROUTINE_PART
				 */
			 }
             ;

label_part : {
		   		$$ = newTreeNode(N_LABEL_PART);
           }
           ;

const_part : CONST const_expr_list {
			   $$ = $2;
		   }
		   | {
           		$$ = newTreeNode(N_CONST_PART);  //an N_CONST_PART with empty child
		   }
		   | CONST error{
				printError("missing const expr list");
			}
		   ;

const_expr_list : const_expr_list ID EQUAL const_value SEMI {
					 $$ = $1;  					//eliminate left recursion
					 TreeNode* exp = newTreeNode(N_CONST_PART_EXP);
					 appendChild(exp, $2);
					 appendChild(exp, $4);
					 appendChild($$, exp);
				/*          					    N_CONST_PART
				 *			/				      |				   |           	\
				 *			N_CONST_PART_EXP   N_CONST_PART_EXP  ......  N_CONST_PART_EXP
				 */
				}
                | ID EQUAL const_value SEMI {
					 $$ = newTreeNode(N_CONST_PART);
					 TreeNode* exp = newTreeNode(N_CONST_PART_EXP);
					 appendChild(exp, $1);
					 appendChild(exp, $3);
					 appendChild($$, exp);

				/*          				N_CONST_PART_EXP
				 *							/	     	\
				 *			               N_ID       (N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)
				 */
				}
                | ID EQUAL const_value error{
				printError("missing ';'");
				}
		   		;

const_value : INTEGER {
				 $$ = $1;
			}
            | REAL {
				$$ = $1;
			}
            | CHAR {
				 $$ = $1;
			}
            | STRING {
				 $$ = $1;
			}
            | SYS_CON {
				 $$ = $1;
			}
            | error{
				printError("illegal const value");
			}
		   ;

type_part : TYPE type_decl_list {
				 $$ = $2;
		  }
          | {
				 $$ = newTreeNode(N_TYPE_PART);	 //an N_TYPE_PART with empty child
		  }
		  | TYPE error{
				printError("missing type decl list");
			}
		   
		  ;

type_decl_list : type_decl_list type_definition {
	 		     	$$ = $1;   //eliminate left recursion
				 	appendChild($$, $2);
		  	   }
               | type_definition {
					 $$ = newTreeNode(N_TYPE_PART);
					 appendChild($$, $1);

				/*          					    N_TYPE_PART
				 *			/				      |				   |           	\
				 *			N_TYPE_DEFINITION   N_TYPE_DEFINITION  ......  N_TYPE_DEFINITION
				 */
				}
               ;

type_definition : ID EQUAL type_decl SEMI {
	 			 $$ = newTreeNode(N_TYPE_DEFINITION);
				 appendChild($$, $1);
				 appendChild($$, $3);
				/*          				N_TYPE_DEFINITION
				 *							/	     	\
				 *			               N_ID      (N_SIMPLE_TYPE_DECL|N_ARRAY_TYPE_DECL|N_RECORD_TYPE_DECL)
				 */
		        }
				| ID EQUAL type_decl error{
					printError("missing ';'");
				}
                ;

type_decl : simple_type_decl {
	 			$$ = $1;
		  }
          | array_type_decl {
				 $$ = $1;
		  }
          | record_type_decl {
				 $$ = $1;
		  }
		  ;

simple_type_decl : SYS_TYPE {
				 	$$ = newTreeNode(N_SIMPLE_TYPE_DECL);
				 	appendChild($$, $1);
				/*          N_SIMPLE_TYPE_DECL
				 *					|
				 *			    N_SYS_TYPE
				 */
				 }
                 | ID {
					$$ = newTreeNode(N_SIMPLE_TYPE_DECL);
				 	appendChild($$, $1);
				/*          N_SIMPLE_TYPE_DECL
				 *					|
				 *			       N_ID
				 */
				 }
                 | LP name_list RP {
					$$ = newTreeNode(N_SIMPLE_TYPE_DECL);
					appendChild($$, $2);
				/*          N_SIMPLE_TYPE_DECL
				 *					|
				 *			    N_NAME_LIST
				 */
				 }
                 | const_value DOTDOT const_value {
					$$ = newTreeNode(N_SIMPLE_TYPE_DECL);
				 	appendChild($$, $1);
					appendChild($$, $3);
				/*          								N_SIMPLE_TYPE_DECL
				 *			                                  /	     	 \
				 *	    (N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)  	(N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)
				 */
				 }
                 | MINUS const_value DOTDOT const_value {
					$$ = newTreeNode(N_SIMPLE_TYPE_DECL);
				 	appendChild($$, $1);
					appendChild($$, $2);
					appendChild($$, $4);
				/*          									N_SIMPLE_TYPE_DECL
				 *		/	    		                              |	     	 \
				 *	N_MINUS    (N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)  	(N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)
				 */
				 }
                 | MINUS const_value DOTDOT MINUS const_value {
                   	$$ = newTreeNode(N_SIMPLE_TYPE_DECL);
				 	appendChild($$, $1);
					appendChild($$, $2);
					appendChild($$, $4);
					appendChild($$, $5);

				/*          									N_SIMPLE_TYPE_DECL
				 *		/	    		                              |	     	|			 \
				 *	N_MINUS    (N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)  	N_MINUS		(N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)
				 */
				 }
                 | ID DOTDOT ID {
				  	$$ = newTreeNode(N_SIMPLE_TYPE_DECL);
				 	appendChild($$, $1);
					appendChild($$, $3);
				/*     N_SIMPLE_TYPE_DECL
				 *		/    	 \
				 *	  N_ID   	N_ID
				 */
				 }
				 | LP name_list error {
					printError("missing right parenthness");
				}
				 | ID DOTDOT error {
				printError("missing identifier after ..");
				}
		   		;

array_type_decl : ARRAY LB simple_type_decl RB OF type_decl {
					$$ = newTreeNode(N_ARRAY_TYPE_DECL);
				 	appendChild($$, $3);
					appendChild($$, $6);
				/*    		N_ARRAY_TYPE_DECL
				 *		/    	 				\
				 *	  N_SIMPLE_TYPE_DECL   		(N_SIMPLE_TYPE_DECL|N_ARRAY_TYPE_DECL|N_RECORD_TYPE_DECL)
				 */
				}
				| ARRAY error simple_type_decl RB OF type_decl{
					printError("missing left barcket");
				}
				| ARRAY LB simple_type_decl error OF type_decl{
					printError("missing right barcket");
				}
				| ARRAY LB simple_type_decl RB error type_decl{
					printError("missing 'OF' after right barcket");
				}
				| ARRAY LB simple_type_decl RB OF error{
					printError("missing type declarations");
				}
				;

record_type_decl : RECORD field_decl_list END {
				 	$$ = $2;
				 } 
				 | RECORD field_decl_list error {
					 printError("missing closing 'end'");
				}
                 ;

field_decl_list : field_decl_list field_decl {
					$$ = $1;
					appendChild($$, $2);
				}
                | field_decl {
					$$ = newTreeNode(N_RECORD_TYPE_DECL);
				 	appendChild($$, $1);
				/*          					 N_RECORD_TYPE_DECL
				 *			/				      |				   |           	\
				 *			N_FIELD_DECL   N_FIELD_DECL        ......  N_FIELD_DECL
				 */
				}
                ;

field_decl : name_list COLON type_decl SEMI {
	 			$$ = newTreeNode(N_FIELD_DECL);
			 	appendChild($$, $1);
				appendChild($$, $3);
				/*          	N_FILED_DECL
				 *			/				\
				 *			N_NAME_LIST   (N_SIMPLE_TYPE_DECL|N_ARRAY_TYPE_DECL|N_RECORD_TYPE_DECL)
				 */
		   }
			| name_list COLON type_decl error{
				printError("missing ';'");
			}
			| name_list error type_decl SEMI{
				printError("missing ':'");
			}
           ;

name_list : name_list COMMA ID {
			$$ = $1;
			appendChild($$, $3);
			/*          	N_NAME_LIST
			 *			/		 |	   |   	\
			 *			N_ID   N_ID  ......  N_ID
			 */
          }
          | ID {
			$$ = newTreeNode(N_NAME_LIST);
		 	appendChild($$, $1);
		  }
		  | name_list error ID {
				printError("missing ','");
			}
		  | name_list COMMA error {
				printError("missing identifier");
		  }			
          ;

var_part : VAR var_decl_list {
			$$ = $2;
		 }
         | {
			$$ = newTreeNode(N_VAR_PART); //empty var part
		 }
		 | VAR error{
				printError("missing var declaration list");
		}
			;

var_decl_list : var_decl_list var_decl {
				  $$ = $1;
				  appendChild($$, $2);
			/*          	N_VAR_PART
			 *			/		       |	        |   	\
			 *			N_VAR_DECL   N_VAR_DECL  ......  N_VAR_DECL
			 */
			  }
              | var_decl {
					$$ = newTreeNode(N_VAR_PART);
		 			appendChild($$, $1);
			  }
              ;
var_decl : name_list COLON type_decl SEMI {
		 	$$ = newTreeNode(N_VAR_DECL);
		 	appendChild($$, $1);
			appendChild($$, $3);
			/*          	N_VAR_DECL
			 *			/	     		\
			 *			N_NAME_LIST   	(N_SIMPLE_TYPE_DECL|N_ARRAY_TYPE_DECL|N_RECORD_TYPE_DECL)
			 */
		 } 
		| name_list error type_decl SEMI{
			printError("missing ':'");
		}
		| name_list COLON type_decl error{
			printError("missing ';'");
		}
         ;

routine_part : routine_part function_decl {
			 		$$ = $1;
					appendChild($$, $2);
			/*          											N_ROUTINE_PART
			 *			/	     								|								|			\
			 *			(N_FUNCTION_DECL|N_PROCEDURE_DECL)  (N_FUNCTION_DECL|N_PROCEDURE_DECL) .... (N_FUNCTION_DECL|N_PROCEDURE_DECL)
			 */
				}
             | routine_part procedure_decl {
			 		$$ = $1;
					appendChild($$, $2);
			 }
             | function_decl {
			 		$$ = newTreeNode(N_ROUTINE_PART);
		 			appendChild($$, $1);
			 }
             | procedure_decl {
			 		$$ = newTreeNode(N_ROUTINE_PART);
		 			appendChild($$, $1);
			 }
             | {
			 		$$ = newTreeNode(N_ROUTINE_PART); //EMPTY ROUTINE PART
		     }
             ;

function_decl : function_head SEMI sub_routine SEMI {
			  		$$ = newTreeNode(N_FUNCTION_DECL);
		 			appendChild($$, $1);
					appendChild($$, $3);
			/*          N_FUNCTION_DECL
			 *			/	     		\
			 *		N_FUNCTION_HEAD 	N_ROUTINE
			 */
			  }
			| function_head error sub_routine SEMI{
				printError("missing ';'");		
			}
			| function_head SEMI sub_routine error{
				printError("missing ';'");		
			}
              ;

function_head : FUNCTION ID parameters COLON simple_type_decl {
			  		$$ = newTreeNode(N_FUNCTION_HEAD);
					appendChild($$, $2);
					appendChild($$, $3);
					appendChild($$, $5);
			/*          N_FUNCTION_HEAD
			 *			/	   |  				\
			 *		  N_ID	 N_PARAMETERS	N_SIMPLE_TYPE_DECL
			 */
			  } 
			  | FUNCTION error parameters COLON simple_type_decl{
					printError("missing function name");				  
			  }
			  | FUNCTION ID parameters error simple_type_decl{
					printError("missing ':'");				  
			  }
			  | FUNCTION ID parameters COLON error{
					printError("missing function type declaration");				  
			  }
              ;

procedure_decl : procedure_head SEMI sub_routine SEMI {
			   		$$ = newTreeNode(N_PROCEDURE_DECL);
		 			appendChild($$, $1);
					appendChild($$, $3);
			/*         N_PROCEDURE_DECL
			 *			/	     		\
			 *		N_PROCEDURE_HEAD	N_ROUTINE
			 */
			   }
			| procedure_head error sub_routine SEMI{
				printError("missing ';'");		
			}
			| procedure_head SEMI sub_routine error{
				printError("missing ';'");		
			}
               ;

procedure_head : PROCEDURE ID parameters {
					$$ = newTreeNode(N_PROCEDURE_HEAD);
		 			appendChild($$, $1);
					appendChild($$, $2);
					appendChild($$, $3);
			/*          N_PROCEDURE_HEAD
			 *			/	   \
			 *		  N_ID	 N_PARAMETERS
			 */
			   }
				| PROCEDURE error parameters{
					printError("missing procedure name");	
				}
               ;

parameters : LP para_decl_list RP {
				$$ = $2;
		   }
           | {
				$$ = newTreeNode(N_PARAMETERS);
			/*          				N_PARAMETERS
			 *			/	     		|	    	|			\
			 *			N_PARA_TYPE  N_PARA_TYPE ....    N_PARA_TYPE
			 */
		   }
			| LP para_decl_list error{
					printError("missing right paretheses");	
			}
           ;

para_decl_list : para_decl_list SEMI para_type_list {
					$$ = $1;
					appendChild($$, $3);
			   }
               | para_type_list {
					$$ = newTreeNode(N_PARAMETERS);
		 			appendChild($$, $1);
			   }
			   | para_decl_list error para_type_list{
					printError("missing ';'");	
				}
               ;

para_type_list : var_para_list COLON simple_type_decl {
					$$ = newTreeNode(N_PARA_TYPE);
		 			appendChild($$, $1);
					appendChild($$, $3);
			/*          	N_PARA_TYPE
			 *			/	     		\
			 *			N_NAME_LIST   N_SIMPLE_TYPE_DECL
			 */
			   }
			   | val_para_list COLON simple_type_decl {
					$$ = newTreeNode(N_PARA_TYPE);
		 			appendChild($$, $1);
					appendChild($$, $3);
			   }
               ;

var_para_list : VAR name_list {
					$$ = $2;
   			  }
              ;

val_para_list : name_list {
					$$ = $1;
			  }
              ;

routine_body : compound_stmt {
					$$ = $1;
			 }
             ;

compound_stmt : BEGINN stmt_list END {
					$$ = $2;
			  };

stmt_list : stmt_list  stmt  SEMI {
			$$ = $1;
			appendChild($$, $2);
			/*          				N_STMT_LIST
			 *			/	     		|	    	|			\
			 *			N_STMT          N_STMT     ....        N_STMT
			 */
		  }
          | {
			$$ = newTreeNode(N_STMT_LIST);
		  }
		  | stmt_list stmt error{
		  	printError("expected an ';' after an statement");
		  };

stmt : INTEGER COLON non_label_stmt {
		$$ = newTreeNode(N_STMT);
		appendChild($$, $1);
		appendChild($$, $3);
			/*          	N_STMT
			 *			/			\
			 *		N_INTEGER     (N_ASSIGN_STMT|N_PROC_STMT|N_COMPOUND_STMT|N_IF_STMT|N_REPEAT_STMT|N_WHILE_STMT|N_FOR_STMT|N_CASE_STMT|N_GOTO_STMT)
			 */
     }
     | non_label_stmt {
		$$ = newTreeNode(N_STMT);
		appendChild($$, $1);

			/*          	N_STMT
			 *				 |
			 *		(N_ASSIGN_STMT|N_PROC_STMT|N_COMPOUND_STMT|N_IF_STMT|N_REPEAT_STMT|N_WHILE_STMT|N_FOR_STMT|N_CASE_STMT|N_GOTO_STMT)
			 */
     }
	 ;

non_label_stmt : assign_stmt {
					$$ = $1;
			   }
               | proc_stmt {
					$$ = $1;
			   }
               | compound_stmt {
					$$ = $1;
			   }
               | if_stmt {
					$$ = $1;
			   }
               | repeat_stmt {
					$$ = $1;
			   }
               | while_stmt {
					$$ = $1;
			   }
               | for_stmt {
					$$ = $1;
   			   }
               | case_stmt {
					$$ = $1;
			   }
               | goto_stmt {
					$$ = $1;
			   }
			   | error{
			   	 printError("illegal statement");
			   }
               ;

assign_stmt : ID ASSIGN expression {
					$$ = newTreeNode(N_ASSIGN_STMT);
					appendChild($$, $1);
					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, $3);
					appendChild($$, exp);
			/*          	N_ASSIGN_STMT
			 *			/			  \
			 *		N_ID         N_EXPRESSION
			 */
			}
            | ID LB expression RB ASSIGN expression {
					$$ = newTreeNode(N_ASSIGN_STMT);
					appendChild($$, $1);
					TreeNode* exp1 = newTreeNode(N_EXPRESSION);
					appendChild(exp1, $3);
					TreeNode* exp2 = newTreeNode(N_EXPRESSION);
					appendChild(exp2, $6);
					appendChild($$, exp1);
					appendChild($$, exp2);
			/*          	N_ASSIGN_STMT
			 *			/		|			  \
			 *		N_ID   N_EXPRESSION       N_EXPRESSION
			 */
			}
            | ID DOT ID ASSIGN expression {
					$$ = newTreeNode(N_ASSIGN_STMT);
					appendChild($$, $1);
					appendChild($$, $3);
					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, $5);
					appendChild($$, exp);
			/*          	N_ASSIGN_STMT
			 *			/		|			  \
			 *		N_ID   		N_ID       N_EXPRESSION
			 */
			};

proc_stmt : ID {
				$$ = newTreeNode(N_PROC_STMT);
				appendChild($$, $1);
			/*          	N_PROC_STMT
			 *					|
			 *		       		N_ID
			 */
		  }
          | ID LP args_list RP {
				$$ = newTreeNode(N_PROC_STMT);
				appendChild($$, $1);
				appendChild($$, $3);
			/*         N_PROC_STMT
			 *			/		 \
			 *		N_ID   		N_ARGS_LIST
			 */
		  }
          | SYS_PROC {
				$$ = newTreeNode(N_PROC_STMT);
				appendChild($$, $1);
			/*          	N_PROC_STMT
			 *					|
			 *		       		N_SYS_PROC
			 */
		  }
          | SYS_PROC LP expression_list RP {
				$$ = newTreeNode(N_PROC_STMT);
				appendChild($$, $1);
				appendChild($$, $3);
			/*         N_PROC_STMT
			 *			/		 \
			 *		N_SYS_PROC   N_EXPRESSION_LIST
			 */
		  }
          | READ LP factor RP {
				$$ = newTreeNode(N_PROC_STMT);
				appendChild($$, $1);
				appendChild($$, $3);
			/*          N_PROC_STMT
			 *				|
			 *			 N_FACTOR
			 */
		  }
		  | ID LP args_list error{
				printError("missing right paretheses");
			}
		  | READ LP factor error{
				printError("missing right paretheses");	  
		  }
		  | SYS_PROC LP expression_list error {

				printError("missing right paretheses");	
		  }
		  | READ error factor RP{
				printError("missing left paretheses");	  
		  }
          ;

if_stmt : IF expression THEN stmt else_clause {
				$$ = newTreeNode(N_IF_STMT);
				TreeNode* exp = newTreeNode(N_EXPRESSION);
				appendChild(exp, $2);
				appendChild($$, exp);
				appendChild($$, $4);
				appendChild($$, $5);

			/*          	N_IF_STMT
			 *		/			|		 \
			 *	  N_EXPRESSION  N_STMT  N_STMT
			 */
		}
        ;

else_clause : ELSE stmt {
				$$ = $2;
			}
            | {
				$$ = newTreeNode(N_STMT); //an stmt with empty child
			}
            ;

repeat_stmt : REPEAT stmt_list UNTIL expression {
				$$ = newTreeNode(N_REPEAT_STMT);
				appendChild($$, $2);
				TreeNode* exp = newTreeNode(N_EXPRESSION);
				appendChild(exp, $4);
				appendChild($$, exp);
			/*          	N_REPEAT_STMT
			 *		/					 \
			 *	  N_STMT_LIST    		N_EXPRESSION
			 */
			}
            ;

while_stmt : WHILE expression DO stmt {
				$$ = newTreeNode(N_WHILE_STMT);
				TreeNode* exp = newTreeNode(N_EXPRESSION);
				appendChild(exp, $2);
				appendChild($$, exp);
				appendChild($$, $4);

			/*          	N_WHILE_STMT
			 *				/			 \
			 *	  N_EXPRESSION    		N_STMT
			 */
		   }
           ;

for_stmt : FOR ID ASSIGN expression direction expression DO stmt {
				$$ = newTreeNode(N_FOR_STMT);
				appendChild($$, $2);
				TreeNode* exp1 = newTreeNode(N_EXPRESSION);
				appendChild(exp1, $4);
				appendChild($$, exp1);
				appendChild($$, $5);
				TreeNode* exp2 = newTreeNode(N_EXPRESSION);
				appendChild(exp2, $6);
				appendChild($$, exp2);
				appendChild($$, $8);
			/*          	N_FOR_STMT
			 *		/		|           |               |       	 \
			 *	  N_ID  N_EXPRESSION (N_TO|N_DOWNTO) N_EXPRESSION N_STMT
			 */
		 }
         ;

direction : TO {
			$$ = $1;
		  }
          | DOWNTO {
			$$ = $1;
		  }
          ;

case_stmt : CASE expression OF case_expr_list END {
			$$ = newTreeNode(N_CASE_STMT);
			TreeNode* exp = newTreeNode(N_EXPRESSION);
			appendChild(exp, $2);
			appendChild($$, exp);
			appendChild($$, $4);
			/*       N_CASE_STMT
			 *		/      	 \
			 * N_EXPRESSION N_CASE_EXPR_LIST
			 */
		  } 
		  | CASE expression OF case_expr_list error{
					printError("missing 'end'");		  
			}
			| CASE expression error case_expr_list END{
					printError("missing 'of'");		  
			}
          ;

case_expr_list : case_expr_list case_expr {
					$$ = $1;
					appendChild($$, $2);
			/*       N_CASE_EXPR_LIST
			 *		/      	 |           |   \
			 * N_CASE_EXPR N_CASE_EXPR ... N_CASE_EXPR
			 */

			   }
               | case_expr {
					$$ = newTreeNode(N_CASE_EXPR_LIST);
					appendChild($$, $1);
			   }
               ;
case_expr : const_value COLON stmt SEMI {
			$$ = newTreeNode(N_CASE_EXPR);
			appendChild($$, $1);
			appendChild($$, $3);
			/*      								 N_CASE_STMT
			 *										/      	     \
			 * 	  (N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)   N_STMT
			 */
		  }
          | ID COLON stmt SEMI {
			$$ = newTreeNode(N_CASE_EXPR);
			appendChild($$, $1);
			appendChild($$, $3);

			/*      N_CASE_STMT
			 *		/	     \
			 * 	  N_ID   N_STMT
			 */
		  } 
		  | const_value COLON stmt error{
				printError("missing ';'");	
			}
          ;

goto_stmt : GOTO INTEGER {
			$$ = newTreeNode(N_GOTO_STMT);
			appendChild($$, $1);

			/*      N_GOTO_STMT
			 *		   |
			 * 	     N_INTEGER
			 */
		  }
          ;

expression_list : expression_list COMMA expression {
					$$ = $1;

					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, $3);
					appendChild($$, exp);
			    }
                | expression {
					$$ = newTreeNode(N_EXPRESSION_LIST);
					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, $1);
					appendChild($$, exp);
			/*       N_EXPRESSION_LIST
			 *		/      	 |           |   \
			 * N_EXPRESSION N_EXPRESSION ... N_EXPRESSION
			 */
				}
                ;

expression : expression GE expr {
					$$ = newTreeNode(N_EXP_GE);
					appendChild($$, $1);
					appendChild($$, $3);
		   }
           | expression GT expr {
					$$ = newTreeNode(N_EXP_GT);
					appendChild($$, $1);
					appendChild($$, $3);
		   }
           | expression LE expr {
					$$ = newTreeNode(N_EXP_LE);
					appendChild($$, $1);
					appendChild($$, $3);
		   }
           | expression LT expr {
					$$ = newTreeNode(N_EXP_LT);
					appendChild($$, $1);
					appendChild($$, $3);
		   }
           | expression EQUAL expr {
					$$ = newTreeNode(N_EXP_EQUAL);
					appendChild($$, $1);
					appendChild($$, $3);
		   }
           | expression UNEQUAL expr {
					$$ = newTreeNode(N_EXP_UNEQUAL);
					appendChild($$, $1);
					appendChild($$, $3);
		   }
           | expr {
					$$ = $1;
		   }
           ;

expr : expr PLUS term {
					$$ = newTreeNode(N_EXP_PLUS);
					appendChild($$, $1);
					appendChild($$, $3);
     }
     | expr MINUS term {
					$$ = newTreeNode(N_EXP_MINUS);
					appendChild($$, $1);
					appendChild($$, $3);
	 }
     | expr OR term {
					$$ = newTreeNode(N_EXP_OR);
					appendChild($$, $1);
					appendChild($$, $3);
	 }
     | term {
					$$ = $1;
	 }
     ;

term : term MUL factor {
					$$ = newTreeNode(N_EXP_MUL);
					appendChild($$, $1);
					appendChild($$, $3);
	 }
     | term DIV factor {
					$$ = newTreeNode(N_EXP_DIV);
					appendChild($$, $1);
					appendChild($$, $3);
	 }
     | term MOD factor {
					$$ = newTreeNode(N_EXP_MOD);
					appendChild($$, $1);
					appendChild($$, $3);
	 }
     | term AND factor {
					$$ = newTreeNode(N_EXP_AND);
					appendChild($$, $1);
					appendChild($$, $3);
	 }
     | factor {
					$$ = $1;
	 }
     ;

factor : ID {
					$$ = $1;
	   }
       | ID LP args_list RP {
					$$ = newTreeNode(N_FACTOR);
					appendChild($$, $1);
					appendChild($$, $3);
			/*      N_FACTOR
			 *		/		\
			 * 	   N_ID      N_ARGS_LIST
			 */
	   }
       | SYS_FUNCT {
					$$ = newTreeNode(N_FACTOR);
					appendChild($$, $1);
			/*      N_FACTOR
			 *			|
			 * 	   N_SYS_FUNCT
			 */
       }
       | SYS_FUNCT LP args_list RP {
					$$ = newTreeNode(N_FACTOR);
					appendChild($$, $1);
					appendChild($$, $3);
			/*      		N_FACTOR
			 *			/			\
			 * 	   N_SYS_FUNCT   	N_ARGS_LIST
			 */
	   }
       | const_value {
					$$ = $1;
	   }
       | LP expression RP {
					$$ = $2;
	   }
       | NOT factor {
					$$ = newTreeNode(N_FACTOR);
					appendChild($$, $1);
					appendChild($$, $2);
			/*      N_FACTOR
			 *		/		\
			 * N_NOT		N_FACTOR
			 */
	   }
       | MINUS factor {
					$$ = newTreeNode(N_FACTOR);
					appendChild($$, $1);
					appendChild($$, $2);
			/*      N_FACTOR
			 *		/		\
			 * N_MINUS		N_FACTOR
			 */
	   }
       | ID LB expression RB {
					$$ = newTreeNode(N_FACTOR);
					appendChild($$, $1);
					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, $3);
					appendChild($$, exp);

			/*      N_FACTOR
			 *		/		\
			 * N_ID			N_EXPRESSION
			 */
	   }
       | ID DOT ID {
					$$ = newTreeNode(N_FACTOR);
					appendChild($$, $1);
					appendChild($$, $3);
			/*      N_FACTOR
			 *		/		\
			 * N_ID			N_ID
			 */
	   }
       ;

args_list : args_list COMMA expression {
					$$ = $1;
					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, $3);
					appendChild($$, exp);
		  }
          | expression {
					$$ = newTreeNode(N_ARGS_LIST);
					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, $1);
					appendChild($$, exp);
		  }
          ;

%%
int yyerror(char *a){
	hasError = 1;
	return 0;
}


int printError(char *a){
	fprintf(stderr, "line %d: %s\n", lineno, a);
}

