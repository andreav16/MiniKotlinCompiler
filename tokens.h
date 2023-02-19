/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_TOKENS_H_INCLUDED
# define YY_YY_TOKENS_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TK_ID = 258,                   /* TK_ID  */
    TK_LIT_FLOAT = 259,            /* TK_LIT_FLOAT  */
    TK_LIT_INT = 260,              /* TK_LIT_INT  */
    TK_LINE_COMMENT = 261,         /* TK_LINE_COMMENT  */
    TK_BLOCK_COMMENT = 262,        /* TK_BLOCK_COMMENT  */
    TK_INCREMENT = 263,            /* TK_INCREMENT  */
    TK_DECREMENT = 264,            /* TK_DECREMENT  */
    TK_AND = 265,                  /* TK_AND  */
    TK_OR = 266,                   /* TK_OR  */
    TK_EQUAL = 267,                /* TK_EQUAL  */
    TK_NOT_EQUAL = 268,            /* TK_NOT_EQUAL  */
    TK_LESS_EQUAL = 269,           /* TK_LESS_EQUAL  */
    TK_GT_EQUAL = 270,             /* TK_GT_EQUAL  */
    TK_RANGE = 271,                /* TK_RANGE  */
    KW_BREAK = 272,                /* KW_BREAK  */
    KW_DO = 273,                   /* KW_DO  */
    KW_ELSE = 274,                 /* KW_ELSE  */
    KW_FALSE = 275,                /* KW_FALSE  */
    KW_TRUE = 276,                 /* KW_TRUE  */
    KW_FOR = 277,                  /* KW_FOR  */
    KW_FUN = 278,                  /* KW_FUN  */
    KW_IF = 279,                   /* KW_IF  */
    KW_IN = 280,                   /* KW_IN  */
    KW_RETURN = 281,               /* KW_RETURN  */
    KW_VAR = 282,                  /* KW_VAR  */
    KW_CONTINUE = 283,             /* KW_CONTINUE  */
    KW_ARRAY = 284,                /* KW_ARRAY  */
    KW_WHEN = 285,                 /* KW_WHEN  */
    KW_IS = 286,                   /* KW_IS  */
    KW_NULL = 287,                 /* KW_NULL  */
    KW_VAL = 288,                  /* KW_VAL  */
    KW_WHILE = 289,                /* KW_WHILE  */
    KW_CONST = 290,                /* KW_CONST  */
    KW_INT = 291,                  /* KW_INT  */
    KW_FLOAT = 292,                /* KW_FLOAT  */
    KW_CHAR = 293,                 /* KW_CHAR  */
    KW_BOOLEAN = 294,              /* KW_BOOLEAN  */
    KW_STRING = 295,               /* KW_STRING  */
    KW_UNTIL = 296,                /* KW_UNTIL  */
    KW_PRINTLN = 297,              /* KW_PRINTLN  */
    KW_READLINE = 298,             /* KW_READLINE  */
    KW_PRINT = 299,                /* KW_PRINT  */
    TK_LIT_CHAR = 300,             /* TK_LIT_CHAR  */
    TK_LIT_STRING = 301,           /* TK_LIT_STRING  */
    KW_MAIN = 302,                 /* KW_MAIN  */
    KW_ARGS = 303                  /* KW_ARGS  */
  };
  typedef enum yytokentype yytoken_kind_t;
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
