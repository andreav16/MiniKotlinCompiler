/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "mini-kotlin.y"

    #include <cstdio>
    extern int yylineno;
    int yylex();
    extern int line;
    extern int column;
    void yyerror(const char * message){
        fprintf(stderr, "Error: %s in line: %d and column %d\n", message, line, column);
    }

#line 82 "mini-kotlin_parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "tokens.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_ID = 3,                      /* TK_ID  */
  YYSYMBOL_TK_LIT_FLOAT = 4,               /* TK_LIT_FLOAT  */
  YYSYMBOL_TK_LIT_INT = 5,                 /* TK_LIT_INT  */
  YYSYMBOL_TK_LINE_COMMENT = 6,            /* TK_LINE_COMMENT  */
  YYSYMBOL_TK_BLOCK_COMMENT = 7,           /* TK_BLOCK_COMMENT  */
  YYSYMBOL_TK_INCREMENT = 8,               /* TK_INCREMENT  */
  YYSYMBOL_TK_DECREMENT = 9,               /* TK_DECREMENT  */
  YYSYMBOL_TK_AND = 10,                    /* TK_AND  */
  YYSYMBOL_TK_OR = 11,                     /* TK_OR  */
  YYSYMBOL_TK_EQUAL = 12,                  /* TK_EQUAL  */
  YYSYMBOL_TK_NOT_EQUAL = 13,              /* TK_NOT_EQUAL  */
  YYSYMBOL_TK_LESS_EQUAL = 14,             /* TK_LESS_EQUAL  */
  YYSYMBOL_TK_GT_EQUAL = 15,               /* TK_GT_EQUAL  */
  YYSYMBOL_TK_RANGE = 16,                  /* TK_RANGE  */
  YYSYMBOL_KW_BREAK = 17,                  /* KW_BREAK  */
  YYSYMBOL_KW_DO = 18,                     /* KW_DO  */
  YYSYMBOL_KW_ELSE = 19,                   /* KW_ELSE  */
  YYSYMBOL_KW_FALSE = 20,                  /* KW_FALSE  */
  YYSYMBOL_KW_TRUE = 21,                   /* KW_TRUE  */
  YYSYMBOL_KW_FOR = 22,                    /* KW_FOR  */
  YYSYMBOL_KW_FUN = 23,                    /* KW_FUN  */
  YYSYMBOL_KW_IF = 24,                     /* KW_IF  */
  YYSYMBOL_KW_IN = 25,                     /* KW_IN  */
  YYSYMBOL_KW_RETURN = 26,                 /* KW_RETURN  */
  YYSYMBOL_KW_VAR = 27,                    /* KW_VAR  */
  YYSYMBOL_KW_CONTINUE = 28,               /* KW_CONTINUE  */
  YYSYMBOL_KW_ARRAYOF = 29,                /* KW_ARRAYOF  */
  YYSYMBOL_KW_ARRAY = 30,                  /* KW_ARRAY  */
  YYSYMBOL_KW_WHEN = 31,                   /* KW_WHEN  */
  YYSYMBOL_KW_IS = 32,                     /* KW_IS  */
  YYSYMBOL_KW_NULL = 33,                   /* KW_NULL  */
  YYSYMBOL_KW_VAL = 34,                    /* KW_VAL  */
  YYSYMBOL_KW_WHILE = 35,                  /* KW_WHILE  */
  YYSYMBOL_KW_CONST = 36,                  /* KW_CONST  */
  YYSYMBOL_KW_INT = 37,                    /* KW_INT  */
  YYSYMBOL_KW_FLOAT = 38,                  /* KW_FLOAT  */
  YYSYMBOL_KW_CHAR = 39,                   /* KW_CHAR  */
  YYSYMBOL_KW_BOOLEAN = 40,                /* KW_BOOLEAN  */
  YYSYMBOL_KW_STRING = 41,                 /* KW_STRING  */
  YYSYMBOL_KW_UNTIL = 42,                  /* KW_UNTIL  */
  YYSYMBOL_KW_PRINTLN = 43,                /* KW_PRINTLN  */
  YYSYMBOL_KW_READLINE = 44,               /* KW_READLINE  */
  YYSYMBOL_KW_PRINT = 45,                  /* KW_PRINT  */
  YYSYMBOL_TK_LIT_CHAR = 46,               /* TK_LIT_CHAR  */
  YYSYMBOL_TK_LIT_STRING = 47,             /* TK_LIT_STRING  */
  YYSYMBOL_KW_MAIN = 48,                   /* KW_MAIN  */
  YYSYMBOL_KW_ARGS = 49,                   /* KW_ARGS  */
  YYSYMBOL_50_ = 50,                       /* '('  */
  YYSYMBOL_51_ = 51,                       /* ')'  */
  YYSYMBOL_52_ = 52,                       /* ':'  */
  YYSYMBOL_53_ = 53,                       /* '<'  */
  YYSYMBOL_54_ = 54,                       /* '>'  */
  YYSYMBOL_55_ = 55,                       /* '{'  */
  YYSYMBOL_56_ = 56,                       /* '}'  */
  YYSYMBOL_57_ = 57,                       /* ';'  */
  YYSYMBOL_58_ = 58,                       /* '='  */
  YYSYMBOL_59_ = 59,                       /* ','  */
  YYSYMBOL_60_ = 60,                       /* '['  */
  YYSYMBOL_61_ = 61,                       /* ']'  */
  YYSYMBOL_62_ = 62,                       /* '+'  */
  YYSYMBOL_63_ = 63,                       /* '-'  */
  YYSYMBOL_64_ = 64,                       /* '*'  */
  YYSYMBOL_65_ = 65,                       /* '/'  */
  YYSYMBOL_66_ = 66,                       /* '%'  */
  YYSYMBOL_67_ = 67,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 68,                  /* $accept  */
  YYSYMBOL_program = 69,                   /* program  */
  YYSYMBOL_functions = 70,                 /* functions  */
  YYSYMBOL_func = 71,                      /* func  */
  YYSYMBOL_block = 72,                     /* block  */
  YYSYMBOL_decls_stmts = 73,               /* decls_stmts  */
  YYSYMBOL_decls_or_stmts = 74,            /* decls_or_stmts  */
  YYSYMBOL_decl = 75,                      /* decl  */
  YYSYMBOL_decl_inline = 76,               /* decl_inline  */
  YYSYMBOL_array_decl = 77,                /* array_decl  */
  YYSYMBOL_params = 78,                    /* params  */
  YYSYMBOL_array_params = 79,              /* array_params  */
  YYSYMBOL_paramsCall = 80,                /* paramsCall  */
  YYSYMBOL_arrayFuncCall_params = 81,      /* arrayFuncCall_params  */
  YYSYMBOL_variable_decl = 82,             /* variable_decl  */
  YYSYMBOL_stmt = 83,                      /* stmt  */
  YYSYMBOL_incre_decre_stmt = 84,          /* incre_decre_stmt  */
  YYSYMBOL_assignation_stmt = 85,          /* assignation_stmt  */
  YYSYMBOL_array_assignation = 86,         /* array_assignation  */
  YYSYMBOL_if_stmt = 87,                   /* if_stmt  */
  YYSYMBOL_print_stmt = 88,                /* print_stmt  */
  YYSYMBOL_loop_stmt = 89,                 /* loop_stmt  */
  YYSYMBOL_while_stmt = 90,                /* while_stmt  */
  YYSYMBOL_do_while_stmt = 91,             /* do_while_stmt  */
  YYSYMBOL_for_stmt = 92,                  /* for_stmt  */
  YYSYMBOL_comment_stmt = 93,              /* comment_stmt  */
  YYSYMBOL_returnORbreak_stmt = 94,        /* returnORbreak_stmt  */
  YYSYMBOL_methodcall_stmt = 95,           /* methodcall_stmt  */
  YYSYMBOL_expression = 96,                /* expression  */
  YYSYMBOL_comparison_expression = 97,     /* comparison_expression  */
  YYSYMBOL_arithmetic_expression = 98,     /* arithmetic_expression  */
  YYSYMBOL_term = 99,                      /* term  */
  YYSYMBOL_unary_expression = 100,         /* unary_expression  */
  YYSYMBOL_incre_decre_expression = 101,   /* incre_decre_expression  */
  YYSYMBOL_factor = 102,                   /* factor  */
  YYSYMBOL_literal = 103,                  /* literal  */
  YYSYMBOL_func_CallLiterals = 104,        /* func_CallLiterals  */
  YYSYMBOL_type = 105,                     /* type  */
  YYSYMBOL_func_type = 106                 /* func_type  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   347

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  247

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,     2,     2,     2,    66,     2,     2,
      50,    51,    64,    62,    59,    63,     2,    65,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    57,
      53,    58,    54,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    27,    27,    30,    31,    34,    35,    36,    37,    40,
      42,    43,    46,    47,    50,    51,    54,    55,    56,    57,
      58,    59,    62,    63,    66,    67,    68,    71,    72,    75,
      76,    77,    78,    79,    82,    83,    86,    87,    90,    91,
      92,    93,    94,    95,    96,    97,   100,   101,   102,   103,
     106,   107,   108,   111,   112,   115,   116,   117,   120,   121,
     122,   123,   126,   127,   128,   131,   132,   135,   136,   137,
     138,   141,   142,   143,   144,   147,   147,   149,   150,   151,
     152,   155,   160,   161,   162,   163,   164,   167,   168,   169,
     170,   171,   174,   175,   176,   177,   180,   181,   182,   183,
     186,   187,   188,   189,   192,   193,   194,   195,   197,   198,
     199,   200,   203,   204,   205,   206,   207,   208,   211,   212,
     215,   216,   217,   218,   219,   222,   223
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_ID",
  "TK_LIT_FLOAT", "TK_LIT_INT", "TK_LINE_COMMENT", "TK_BLOCK_COMMENT",
  "TK_INCREMENT", "TK_DECREMENT", "TK_AND", "TK_OR", "TK_EQUAL",
  "TK_NOT_EQUAL", "TK_LESS_EQUAL", "TK_GT_EQUAL", "TK_RANGE", "KW_BREAK",
  "KW_DO", "KW_ELSE", "KW_FALSE", "KW_TRUE", "KW_FOR", "KW_FUN", "KW_IF",
  "KW_IN", "KW_RETURN", "KW_VAR", "KW_CONTINUE", "KW_ARRAYOF", "KW_ARRAY",
  "KW_WHEN", "KW_IS", "KW_NULL", "KW_VAL", "KW_WHILE", "KW_CONST",
  "KW_INT", "KW_FLOAT", "KW_CHAR", "KW_BOOLEAN", "KW_STRING", "KW_UNTIL",
  "KW_PRINTLN", "KW_READLINE", "KW_PRINT", "TK_LIT_CHAR", "TK_LIT_STRING",
  "KW_MAIN", "KW_ARGS", "'('", "')'", "':'", "'<'", "'>'", "'{'", "'}'",
  "';'", "'='", "','", "'['", "']'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "$accept", "program", "functions", "func", "block", "decls_stmts",
  "decls_or_stmts", "decl", "decl_inline", "array_decl", "params",
  "array_params", "paramsCall", "arrayFuncCall_params", "variable_decl",
  "stmt", "incre_decre_stmt", "assignation_stmt", "array_assignation",
  "if_stmt", "print_stmt", "loop_stmt", "while_stmt", "do_while_stmt",
  "for_stmt", "comment_stmt", "returnORbreak_stmt", "methodcall_stmt",
  "expression", "comparison_expression", "arithmetic_expression", "term",
  "unary_expression", "incre_decre_expression", "factor", "literal",
  "func_CallLiterals", "type", "func_type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-109)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -18,     9,    22,  -109,   -18,   -11,    -7,  -109,  -109,    30,
      -3,     2,     7,    30,     4,   -10,   276,   -20,  -109,    41,
     235,  -109,    -1,  -109,  -109,  -109,  -109,  -109,    25,   281,
    -109,    33,     1,  -109,  -109,    40,   167,    29,    51,   100,
      99,    99,    65,    66,    78,    92,   235,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
     302,    30,   103,  -109,   -10,   111,    97,   102,   203,    20,
     100,  -109,  -109,   122,   130,    99,   100,   106,  -109,  -109,
     114,   114,  -109,  -109,  -109,  -109,   100,   114,   114,     5,
     222,    26,    28,  -109,  -109,    18,  -109,   116,  -109,   -44,
    -109,   100,   100,   100,  -109,  -109,   118,  -109,   302,  -109,
     121,  -109,  -109,   119,   127,   132,   203,   128,  -109,   297,
      15,   131,   138,   165,   207,   100,  -109,  -109,   233,  -109,
    -109,   100,   100,   100,   100,  -109,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,  -109,  -109,   302,  -109,
      60,   253,   261,   275,   133,   149,   158,   203,   302,  -109,
    -109,   203,   153,   100,   100,   100,   167,   101,  -109,   222,
     222,   222,   222,    26,    26,    26,    26,    28,    28,    28,
    -109,  -109,  -109,  -109,   -30,   162,  -109,   129,   167,   164,
     168,  -109,  -109,   -10,  -109,   173,  -109,   100,   279,   283,
     184,   212,  -109,  -109,   203,   302,  -109,  -109,  -109,  -109,
    -109,  -109,   178,   142,   176,   177,   100,   167,   -10,   188,
     186,   209,  -109,  -109,  -109,   287,  -109,  -109,  -109,  -109,
     197,   189,   200,   167,   249,   209,   201,  -109,  -109,   216,
    -109,  -109,   224,   209,   221,   211,  -109
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     2,     4,     0,     0,     1,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      11,     8,     0,   120,   121,   123,   122,   124,    25,     0,
       6,     0,     0,    75,    76,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,    13,    45,
      40,    39,    38,    42,    63,    64,    62,    41,    43,    44,
       0,     0,     0,   125,     0,     0,    46,    48,     0,     0,
       0,    52,    79,     0,     0,     0,     0,   110,   115,   114,
       0,     0,   117,   116,   112,   113,     0,     0,     0,    78,
      86,    91,    95,    99,   102,   103,   109,    37,    15,    16,
      14,     0,     0,     0,     9,    10,     0,    24,     0,     5,
       0,    47,    49,    30,     0,     0,     0,    32,    51,    50,
       0,     0,     0,     0,     0,     0,   104,   105,     0,   101,
     100,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   106,   107,     0,    17,
       0,     0,     0,     0,    28,     0,     0,     0,     0,    81,
      33,     0,     0,     0,     0,     0,     0,     0,   108,    83,
      82,    84,    85,    89,    90,    88,    87,    94,    92,    93,
      96,    97,    98,    36,   110,     0,    20,    18,     0,    59,
      58,    27,   126,     0,    29,     0,    31,     0,     0,     0,
       0,    55,    56,   111,     0,     0,    19,    65,    66,    61,
      60,     7,     0,    53,    67,    68,     0,     0,     0,     0,
       0,     0,    54,    69,    70,     0,    73,    74,    57,    21,
       0,   119,     0,     0,     0,     0,    35,    71,    72,     0,
     118,    34,     0,     0,     0,    22,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,   277,  -109,   -17,   236,  -109,  -109,   242,  -109,
      -6,  -109,  -108,  -109,   226,   -35,  -109,  -109,  -109,   234,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,   -65,   213,
     -64,   -16,     0,  -109,    49,   -66,    67,   -26,  -109
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    21,    45,    46,    47,    98,   186,
      12,    13,   115,   116,    99,    48,    49,    50,    71,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    89,    90,
      91,    92,    93,    94,    95,    96,   232,    28,    64
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      30,    74,   117,    63,   119,     1,   120,    18,   160,    66,
      67,   124,     5,   149,   150,   131,   132,   133,   134,    73,
     204,   128,     7,    77,    78,    79,   146,   147,    80,    81,
     125,   140,    29,    11,   106,    20,   151,   152,   153,     9,
      82,    83,   140,    10,    38,    20,    14,   109,    15,   194,
     117,    68,    60,   196,    16,   107,    19,     6,    17,    69,
     167,    70,   135,   184,    78,    79,    84,    85,    80,    81,
      86,    31,   173,   174,   175,   176,   162,   141,   142,    75,
      82,    83,   155,    87,    61,   187,    65,    88,   141,   142,
     185,   117,   143,   144,   145,   117,   219,    72,   198,   199,
     200,    76,    97,    77,    78,    79,    84,    85,    80,    81,
      86,   131,   132,   133,   134,   101,   102,    77,    78,    79,
      82,    83,   183,    87,   177,   178,   179,    88,   103,   126,
     127,   202,   195,   213,    82,    83,   129,   130,   117,   131,
     132,   133,   134,   180,   181,   182,    84,    85,   104,   201,
      86,   225,   110,   208,   111,   231,   108,   121,   140,   112,
      84,    85,   203,    87,    86,   122,   125,    88,   148,   231,
      32,   207,   154,    33,    34,   156,   211,   244,   157,   220,
     158,   163,   227,   159,    35,    36,   206,   161,   164,    37,
     165,    38,   191,    39,   131,   132,   133,   134,   238,   222,
     226,   228,    42,   192,   141,   142,   113,    78,    79,   193,
      43,   197,    44,    78,    79,   205,   237,   131,   132,   133,
     134,   209,    20,    82,    83,   210,   216,   212,   221,    82,
      83,   218,   114,   223,   224,   217,   136,   137,    32,   229,
     230,    33,    34,   131,   132,   133,   134,   234,   235,    84,
      85,   236,    35,    36,   239,    84,    85,    37,   166,    38,
     241,    39,    40,   131,   132,   133,   134,   242,   246,    41,
      42,   131,   132,   133,   134,   138,   139,   245,    43,   243,
      44,     8,   105,   100,   168,   131,   132,   133,   134,   131,
     132,   133,   134,   131,   132,   133,   134,   131,   132,   133,
     134,   123,   240,   118,   188,     0,    22,   131,   132,   133,
     134,    62,   189,    23,    24,    25,    26,    27,    23,    24,
      25,    26,    27,     0,     0,     0,   190,     0,     0,     0,
     214,     0,     0,     0,   215,     0,     0,     0,   233,    23,
      24,    25,    26,    27,   169,   170,   171,   172
};

static const yytype_int16 yycheck[] =
{
      17,    36,    68,    29,    69,    23,    70,    13,   116,     8,
       9,    76,     3,    57,    58,    10,    11,    12,    13,    36,
      50,    86,     0,     3,     4,     5,     8,     9,     8,     9,
      60,    16,    52,     3,    60,    55,   101,   102,   103,    50,
      20,    21,    16,    50,    24,    55,    49,    64,    51,   157,
     116,    50,    53,   161,    52,    61,    52,    48,    51,    58,
     125,    60,    57,     3,     4,     5,    46,    47,     8,     9,
      50,    30,   136,   137,   138,   139,    61,    62,    63,    50,
      20,    21,   108,    63,    59,   150,    53,    67,    62,    63,
      30,   157,    64,    65,    66,   161,   204,    57,   163,   164,
     165,    50,     3,     3,     4,     5,    46,    47,     8,     9,
      50,    10,    11,    12,    13,    50,    50,     3,     4,     5,
      20,    21,   148,    63,   140,   141,   142,    67,    50,    80,
      81,   166,   158,   197,    20,    21,    87,    88,   204,    10,
      11,    12,    13,   143,   144,   145,    46,    47,    56,   166,
      50,   216,    41,   188,    57,   221,    53,    35,    16,    57,
      46,    47,    61,    63,    50,    35,    60,    67,    52,   235,
       3,   188,    54,     6,     7,    54,   193,   243,    59,   205,
      53,    50,   217,    51,    17,    18,    57,    59,    50,    22,
      25,    24,    59,    26,    10,    11,    12,    13,   233,    57,
     217,   218,    35,    54,    62,    63,     3,     4,     5,    51,
      43,    58,    45,     4,     5,    53,   233,    10,    11,    12,
      13,    57,    55,    20,    21,    57,    42,    54,    50,    20,
      21,    19,    29,    57,    57,    51,    14,    15,     3,    51,
      54,     6,     7,    10,    11,    12,    13,    50,    59,    46,
      47,    51,    17,    18,     5,    46,    47,    22,    51,    24,
      59,    26,    27,    10,    11,    12,    13,    51,    57,    34,
      35,    10,    11,    12,    13,    53,    54,    56,    43,    55,
      45,     4,    46,    41,    51,    10,    11,    12,    13,    10,
      11,    12,    13,    10,    11,    12,    13,    10,    11,    12,
      13,    75,   235,    69,    51,    -1,    30,    10,    11,    12,
      13,    30,    51,    37,    38,    39,    40,    41,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    51,    -1,    -1,    -1,    51,    37,
      38,    39,    40,    41,   131,   132,   133,   134
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    23,    69,    70,    71,     3,    48,     0,    70,    50,
      50,     3,    78,    79,    49,    51,    52,    51,    78,    52,
      55,    72,    30,    37,    38,    39,    40,    41,   105,    52,
      72,    30,     3,     6,     7,    17,    18,    22,    24,    26,
      27,    34,    35,    43,    45,    73,    74,    75,    83,    84,
      85,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      53,    59,    30,   105,   106,    53,     8,     9,    50,    58,
      60,    86,    57,    72,    83,    50,    50,     3,     4,     5,
       8,     9,    20,    21,    46,    47,    50,    63,    67,    96,
      97,    98,    99,   100,   101,   102,   103,     3,    76,    82,
      76,    50,    50,    50,    56,    73,   105,    78,    53,    72,
      41,    57,    57,     3,    29,    80,    81,   103,    87,    96,
      98,    35,    35,    82,    96,    60,   102,   102,    96,   102,
     102,    10,    11,    12,    13,    57,    14,    15,    53,    54,
      16,    62,    63,    64,    65,    66,     8,     9,    52,    57,
      58,    96,    96,    96,    54,   105,    54,    59,    53,    51,
      80,    59,    61,    50,    50,    25,    51,    96,    51,    97,
      97,    97,    97,    98,    98,    98,    98,    99,    99,    99,
     100,   100,   100,   105,     3,    30,    77,    96,    51,    51,
      51,    59,    54,    51,    80,   105,    80,    58,    96,    96,
      96,    72,    83,    61,    50,    53,    57,    72,    83,    57,
      57,    72,    54,    98,    51,    51,    42,    51,    19,    80,
     105,    50,    57,    57,    57,    96,    72,    83,    72,    51,
      54,   103,   104,    51,    50,    59,    51,    72,    83,     5,
     104,    59,    51,    55,   103,    56,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    68,    69,    70,    70,    71,    71,    71,    71,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    76,    76,
      76,    76,    77,    77,    78,    78,    78,    79,    79,    80,
      80,    80,    80,    80,    81,    81,    82,    82,    83,    83,
      83,    83,    83,    83,    83,    83,    84,    84,    84,    84,
      85,    85,    85,    86,    86,    87,    87,    87,    88,    88,
      88,    88,    89,    89,    89,    90,    90,    91,    91,    91,
      91,    92,    92,    92,    92,    93,    93,    94,    94,    94,
      94,    95,    96,    96,    96,    96,    96,    97,    97,    97,
      97,    97,    98,    98,    98,    98,    99,    99,    99,    99,
     100,   100,   100,   100,   101,   101,   101,   101,   102,   102,
     102,   102,   103,   103,   103,   103,   103,   103,   104,   104,
     105,   105,   105,   105,   105,   106,   106
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     8,     6,    11,     5,     3,
       2,     0,     1,     1,     2,     2,     1,     2,     3,     4,
       3,     6,    10,    11,     5,     3,     2,     7,     6,     3,
       1,     3,     1,     2,     8,     7,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     2,     3,
       3,     3,     2,     5,     6,     5,     5,     7,     4,     4,
       5,     5,     1,     1,     1,     5,     5,     6,     6,     7,
       7,     9,     9,     7,     7,     1,     1,     3,     2,     2,
       1,     4,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     3,     1,     3,     3,     3,     1,
       2,     2,     1,     1,     2,     2,     2,     2,     3,     1,
       1,     4,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {

#line 1364 "mini-kotlin_parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 226 "mini-kotlin.y"
