/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_TOKENS_H_INCLUDED
# define YY_YY_TOKENS_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_ID = 258,
    TK_LIT_FLOAT = 259,
    TK_LIT_INT = 260,
    TK_LINE_COMMENT = 261,
    TK_BLOCK_COMMENT = 262,
    TK_INCREMENT = 263,
    TK_DECREMENT = 264,
    TK_AND = 265,
    TK_OR = 266,
    TK_EQUAL = 267,
    TK_NOT_EQUAL = 268,
    TK_LESS_EQUAL = 269,
    TK_GT_EQUAL = 270,
    TK_RANGE = 271,
    KW_BREAK = 272,
    KW_DO = 273,
    KW_ELSE = 274,
    KW_FALSE = 275,
    KW_TRUE = 276,
    KW_FOR = 277,
    KW_FUN = 278,
    KW_IF = 279,
    KW_IN = 280,
    KW_RETURN = 281,
    KW_VAR = 282,
    KW_CONTINUE = 283,
    KW_ARRAY = 284,
    KW_WHEN = 285,
    KW_IS = 286,
    KW_NULL = 287,
    KW_VAL = 288,
    KW_WHILE = 289,
    KW_CONST = 290,
    KW_INT = 291,
    KW_FLOAT = 292,
    KW_CHAR = 293,
    KW_BOOLEAN = 294,
    KW_STRING = 295,
    KW_PRINTLN = 296,
    KW_READLINE = 297,
    KW_PRINT = 298,
    TK_LIT_CHAR = 299,
    TK_LIT_STRING = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKENS_H_INCLUDED  */
