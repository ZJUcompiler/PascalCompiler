%{
	#include <stdio.h>
	#include "globals.h"
	#include "util.h"
	#include "y.tab.h"
	int lineno = 1;
%}
AND [Aa][Nn][Dd]
ARRAY [Aa][Rr][Rr][Aa][Yy]
ASSIGN ":="
BEGINN [Bb][Ee][Gg][Ii][Nn]
CASE [Cc][Aa][Ss][Ee]
CHAR '[^']'
COLON ":"
COMMA ","
CONST [Cc][Oo][Nn][Ss][Tt]
DIV [Dd][Ii][Vv]
DO [Dd][Oo]
DOT "."
DOTDOT ".."
DOWNTO [Dd][Oo][Ww][Nn][Tt][Oo]
ELSE [Ee][Ll][Ss][Ee]
END [Ee][Nn][Dd]
EQUAL "="
FOR [Ff][Oo][Rr]
FUNCTION [Ff][Uu][Nn][Cc][Tt][Ii][Oo][Nn]
GE ">="
GOTO [Gg][Oo][Tt][Oo]
GT ">"
ID [a-zA-Z]([a-zA-Z0-9])*
IF [Ii][Ff]
INTEGER [0-9]+
LB "["
LE "<="
LP "("
LT "<"
MINUS "-"
MOD [Mm][Oo][Dd]
MUL "*"
NOT [Nn][Oo][Tt]
OF [Oo][Ff]
OR [Oo][Rr]
PLUS "+"
PROCEDURE [Pp][Rr][Oo][Cc][Ee][Dd][Uu][Rr][Ee]
PROGRAM [Pp][Rr][Oo][Gg][Rr][Aa][Mm]
RB "]"
READ "read"
REAL [0-9]+"."[0-9]+
RECORD [Rr][Ee][Cc][Oo][Rr][Dd]
REPEAT [Rr][Ee][Pp][Ee][Aa][Tt]
RP ")"
SEMI ";"
STRING '[^']+'
SYS_CON "false"|"maxint"|"true"
SYS_FUNCT "abs"|"chr"|"odd"|"ord"|"pred"|"sqr"|"sqrt"|"succ"
SYS_PROC "write"|"writeln"
SYS_TYPE "boolean"|"char"|"integer"|"real"
THEN [Tt][Hh][Ee][Nn]
TO [Tt][Oo]
TYPE [Tt][Yy][Pp][Ee]
UNEQUAL "<>"
UNTIL [Uu][Nn][Tt][Ii][Ll]
VAR [Vv][Aa][Rr]
WHILE [Ww][Hh][Ii][Ll][Ee]

%%
{AND} {yylval = newTokenTreeNode(N_AND, yytext); return (AND);}
{ARRAY} {yylval = newTokenTreeNode(N_ARRAY, yytext);return (ARRAY);}
{ASSIGN} {yylval = newTokenTreeNode(N_ASSIGN, yytext);return (ASSIGN);}
{BEGINN} {yylval = newTokenTreeNode(N_BEGIN, yytext);return (BEGINN);}
{CASE} {yylval = newTokenTreeNode(N_CASE, yytext);return (CASE);}
{CHAR} {yylval = newTokenTreeNode(N_CHAR, yytext);return (CHAR);}
{COLON} {yylval = newTokenTreeNode(N_COLON, yytext);return (COLON);}
{COMMA} {yylval = newTokenTreeNode(N_COMMA, yytext);return (COMMA);}
{CONST} {yylval = newTokenTreeNode(N_CONST, yytext);return (CONST);}
{DIV} {yylval = newTokenTreeNode(N_DIV, yytext);return (DIV);}
{DO} {yylval = newTokenTreeNode(N_DO, yytext);return (DO);}
{DOT} {yylval = newTokenTreeNode(N_DOT, yytext);return (DOT);}
{DOTDOT} {yylval = newTokenTreeNode(N_DOTDOT, yytext);return (DOTDOT);}
{DOWNTO} {yylval = newTokenTreeNode(N_DOWNTO, yytext);return (DOWNTO);}
{ELSE} {yylval = newTokenTreeNode(N_ELSE, yytext);return (ELSE);}
{END} {yylval = newTokenTreeNode(N_END, yytext);return (END);}
{EQUAL} {yylval = newTokenTreeNode(N_EQUAL, yytext);return (EQUAL);}
{FOR} {yylval = newTokenTreeNode(N_FOR, yytext);return (FOR);}
{FUNCTION} {yylval = newTokenTreeNode(N_FUNCTION, yytext);return (FUNCTION);}
{GE} {yylval = newTokenTreeNode(N_GE, yytext);return (GE);}
{GOTO} {yylval = newTokenTreeNode(N_GOTO, yytext);return (GOTO);}
{GT} {yylval = newTokenTreeNode(N_GT, yytext);return (GT);}
{IF} {yylval = newTokenTreeNode(N_IF, yytext);return (IF);}
{INTEGER} {yylval = newTokenTreeNode(N_INTEGER, yytext);return (INTEGER);}
{LB} {yylval = newTokenTreeNode(N_LB, yytext);return (LB);}
{LE} {yylval = newTokenTreeNode(N_LE, yytext);return (LE);}
{LP} {yylval = newTokenTreeNode(N_LP, yytext);return (LP);}
{LT} {yylval = newTokenTreeNode(N_LT, yytext);return (LT);}
{MINUS} {yylval = newTokenTreeNode(N_MINUS, yytext);return (MINUS);}
{MOD} {yylval = newTokenTreeNode(N_MOD, yytext);return (MOD);}
{MUL} {yylval = newTokenTreeNode(N_MUL, yytext);return (MUL);}
{NOT} {yylval = newTokenTreeNode(N_NOT, yytext);return (NOT);}
{OF} {yylval = newTokenTreeNode(N_OF, yytext);return (OF);}
{OR} {yylval = newTokenTreeNode(N_OR, yytext);return (OR);}
{PLUS} {yylval = newTokenTreeNode(N_PLUS, yytext);return (PLUS);}
{PROCEDURE} {yylval = newTokenTreeNode(N_PROCEDURE, yytext);return (PROCEDURE);}
{PROGRAM} {yylval = newTokenTreeNode(N_PROGRAM, yytext);return (PROGRAM);}
{RB} {yylval = newTokenTreeNode(N_RB, yytext);return (RB);}
{READ} {yylval = newTokenTreeNode(N_READ, yytext);return (READ);}
{REAL} {yylval = newTokenTreeNode(N_REAL, yytext);return (REAL);}
{RECORD} {yylval = newTokenTreeNode(N_RECORD, yytext);return (RECORD);}
{REPEAT} {yylval = newTokenTreeNode(N_REPEAT, yytext);return (REPEAT);}
{RP} {yylval = newTokenTreeNode(N_RP, yytext);return (RP);}
{SEMI} {yylval = newTokenTreeNode(N_SEMI, yytext);return (SEMI);}
{STRING} {yylval = newTokenTreeNode(N_STRING, yytext);return (STRING);}
{SYS_CON} {yylval = newTokenTreeNode(N_SYS_CON, yytext);return (SYS_CON);}
{SYS_FUNCT} {yylval = newTokenTreeNode(N_SYS_FUNCT, yytext);return (SYS_FUNCT);}
{SYS_PROC} {yylval = newTokenTreeNode(N_SYS_PROC, yytext);return (SYS_PROC);}
{SYS_TYPE} {yylval = newTokenTreeNode(N_SYS_TYPE, yytext);return (SYS_TYPE);}
{THEN} {yylval = newTokenTreeNode(N_THEN, yytext);return (THEN);}
{TO} {yylval = newTokenTreeNode(N_TO, yytext);return (TO);}
{TYPE} {yylval = newTokenTreeNode(N_TYPE, yytext);return (TYPE);}
{UNEQUAL} {yylval = newTokenTreeNode(N_UNEQUAL, yytext);return (UNEQUAL);}
{UNTIL} {yylval = newTokenTreeNode(N_UNTIL, yytext);return (UNTIL);}
{VAR} {yylval = newTokenTreeNode(N_VAR, yytext);return (VAR);}
{WHILE} {yylval = newTokenTreeNode(N_WHILE, yytext);return (WHILE);}
{ID} {yylval = newTokenTreeNode(N_ID, yytext);return (ID);}

"(*"|"{" {
	int flag = 0;
	while (1){
		char ch = input();
		if (ch == EOF) commentEOF();
		if (yytext[0] == '(' && ch == '*') flag = 1;
		if (yytext[0] == '(' && ch == ')' && flag == 1) break;
		flag = 0;
		if (yytext[0] == '{' && ch == '}') break;
		if (ch == '\n') lineno++;
	}
}

[ \t\f]+ {};

\n {lineno++;};

. {
	fprintf(stderr, "%c (0%o): illegal character at line %d\n", yytext[0], yytext[0], lineno);
}

%%
commentEOF(){
	fprintf(stderr, "unexpected EOF inside comment at line %d\n", lineno);
	exit(1);
}

yywrap(){
	return (1);
}
