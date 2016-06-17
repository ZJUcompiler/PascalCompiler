
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AND = 258,
     ARRAY = 259,
     ASSIGN = 260,
     BEGINN = 261,
     CASE = 262,
     CHAR = 263,
     COLON = 264,
     COMMA = 265,
     CONST = 266,
     DIV = 267,
     DO = 268,
     DOT = 269,
     DOTDOT = 270,
     DOWNTO = 271,
     ELSE = 272,
     END = 273,
     EQUAL = 274,
     FOR = 275,
     FUNCTION = 276,
     GE = 277,
     GOTO = 278,
     GT = 279,
     ID = 280,
     IF = 281,
     INTEGER = 282,
     LB = 283,
     LE = 284,
     LP = 285,
     LT = 286,
     MINUS = 287,
     MOD = 288,
     MUL = 289,
     NOT = 290,
     OF = 291,
     OR = 292,
     PLUS = 293,
     PROCEDURE = 294,
     PROGRAM = 295,
     RB = 296,
     READ = 297,
     REAL = 298,
     RECORD = 299,
     REPEAT = 300,
     RP = 301,
     SEMI = 302,
     STRING = 303,
     SYS_CON = 304,
     SYS_FUNCT = 305,
     SYS_PROC = 306,
     SYS_TYPE = 307,
     THEN = 308,
     TO = 309,
     TYPE = 310,
     UNEQUAL = 311,
     UNTIL = 312,
     VAR = 313,
     WHILE = 314
   };
#endif



// #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
// typedef int YYSTYPE;
// # define YYSTYPE_IS_TRIVIAL 1
// # define yystype YYSTYPE /* obsolescent; will be withdrawn */
// # define YYSTYPE_IS_DECLARED 1
// #endif
#define YYSTYPE TreeNode*

extern YYSTYPE yylval;


