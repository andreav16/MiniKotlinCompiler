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
/* "%code requires" blocks.  */
#line 1 "mini-kotlin.y"

    #include "ast.h"

#line 53 "tokens.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TK_INCREMENT = 258,            /* TK_INCREMENT  */
    TK_DECREMENT = 259,            /* TK_DECREMENT  */
    TK_AND = 260,                  /* TK_AND  */
    TK_OR = 261,                   /* TK_OR  */
    TK_EQUAL = 262,                /* TK_EQUAL  */
    TK_NOT_EQUAL = 263,            /* TK_NOT_EQUAL  */
    TK_LESS_EQUAL = 264,           /* TK_LESS_EQUAL  */
    TK_GT_EQUAL = 265,             /* TK_GT_EQUAL  */
    TK_RANGE = 266,                /* TK_RANGE  */
    KW_BREAK = 267,                /* KW_BREAK  */
    KW_DO = 268,                   /* KW_DO  */
    KW_ELSE = 269,                 /* KW_ELSE  */
    KW_FOR = 270,                  /* KW_FOR  */
    KW_FUN = 271,                  /* KW_FUN  */
    KW_IF = 272,                   /* KW_IF  */
    KW_IN = 273,                   /* KW_IN  */
    KW_RETURN = 274,               /* KW_RETURN  */
    KW_VAR = 275,                  /* KW_VAR  */
    KW_CONTINUE = 276,             /* KW_CONTINUE  */
    KW_ARRAYOF = 277,              /* KW_ARRAYOF  */
    KW_ARRAY = 278,                /* KW_ARRAY  */
    KW_WHEN = 279,                 /* KW_WHEN  */
    KW_IS = 280,                   /* KW_IS  */
    KW_NULL = 281,                 /* KW_NULL  */
    KW_VAL = 282,                  /* KW_VAL  */
    KW_WHILE = 283,                /* KW_WHILE  */
    KW_CONST = 284,                /* KW_CONST  */
    KW_INT = 285,                  /* KW_INT  */
    KW_FLOAT = 286,                /* KW_FLOAT  */
    KW_CHAR = 287,                 /* KW_CHAR  */
    KW_BOOLEAN = 288,              /* KW_BOOLEAN  */
    KW_STRING = 289,               /* KW_STRING  */
    KW_UNTIL = 290,                /* KW_UNTIL  */
    KW_PRINTLN = 291,              /* KW_PRINTLN  */
    KW_READLINE = 292,             /* KW_READLINE  */
    KW_PRINT = 293,                /* KW_PRINT  */
    KW_MAIN = 294,                 /* KW_MAIN  */
    KW_ARGS = 295,                 /* KW_ARGS  */
    TK_ID = 296,                   /* TK_ID  */
    TK_LIT_STRING = 297,           /* TK_LIT_STRING  */
    TK_LINE_COMMENT = 298,         /* TK_LINE_COMMENT  */
    TK_BLOCK_COMMENT = 299,        /* TK_BLOCK_COMMENT  */
    TK_LIT_FLOAT = 300,            /* TK_LIT_FLOAT  */
    TK_LIT_INT = 301,              /* TK_LIT_INT  */
    TK_LIT_CHAR = 302,             /* TK_LIT_CHAR  */
    KW_TRUE = 303,                 /* KW_TRUE  */
    KW_FALSE = 304                 /* KW_FALSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "mini-kotlin.y"

        int int_t;
        char * string_t;
        float float_t;
        bool boolean_t;
        char char_t;
        Statement * statement_t;
        Expression * expr_t;
        Declaration * decl_t;
        VarDeclarationStatement * var_declaration_t;
        list<Expression *> * expr_list_t;
        list<VarDeclarationStatement *> * var_declaration_list_t;
        list<Statement *> * stmt_list_t;
        ComplexType * type_t;

#line 135 "tokens.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TOKENS_H_INCLUDED  */
