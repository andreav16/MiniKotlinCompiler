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
#line 5 "mini-kotlin.y"

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
  YYSYMBOL_TK_INCREMENT = 3,               /* TK_INCREMENT  */
  YYSYMBOL_TK_DECREMENT = 4,               /* TK_DECREMENT  */
  YYSYMBOL_TK_AND = 5,                     /* TK_AND  */
  YYSYMBOL_TK_OR = 6,                      /* TK_OR  */
  YYSYMBOL_TK_EQUAL = 7,                   /* TK_EQUAL  */
  YYSYMBOL_TK_NOT_EQUAL = 8,               /* TK_NOT_EQUAL  */
  YYSYMBOL_TK_LESS_EQUAL = 9,              /* TK_LESS_EQUAL  */
  YYSYMBOL_TK_GT_EQUAL = 10,               /* TK_GT_EQUAL  */
  YYSYMBOL_TK_RANGE = 11,                  /* TK_RANGE  */
  YYSYMBOL_KW_BREAK = 12,                  /* KW_BREAK  */
  YYSYMBOL_KW_DO = 13,                     /* KW_DO  */
  YYSYMBOL_KW_ELSE = 14,                   /* KW_ELSE  */
  YYSYMBOL_KW_FOR = 15,                    /* KW_FOR  */
  YYSYMBOL_KW_FUN = 16,                    /* KW_FUN  */
  YYSYMBOL_KW_IF = 17,                     /* KW_IF  */
  YYSYMBOL_KW_IN = 18,                     /* KW_IN  */
  YYSYMBOL_KW_RETURN = 19,                 /* KW_RETURN  */
  YYSYMBOL_KW_VAR = 20,                    /* KW_VAR  */
  YYSYMBOL_KW_CONTINUE = 21,               /* KW_CONTINUE  */
  YYSYMBOL_KW_ARRAYOF = 22,                /* KW_ARRAYOF  */
  YYSYMBOL_KW_ARRAY = 23,                  /* KW_ARRAY  */
  YYSYMBOL_KW_WHEN = 24,                   /* KW_WHEN  */
  YYSYMBOL_KW_IS = 25,                     /* KW_IS  */
  YYSYMBOL_KW_NULL = 26,                   /* KW_NULL  */
  YYSYMBOL_KW_VAL = 27,                    /* KW_VAL  */
  YYSYMBOL_KW_WHILE = 28,                  /* KW_WHILE  */
  YYSYMBOL_KW_CONST = 29,                  /* KW_CONST  */
  YYSYMBOL_KW_INT = 30,                    /* KW_INT  */
  YYSYMBOL_KW_FLOAT = 31,                  /* KW_FLOAT  */
  YYSYMBOL_KW_CHAR = 32,                   /* KW_CHAR  */
  YYSYMBOL_KW_BOOLEAN = 33,                /* KW_BOOLEAN  */
  YYSYMBOL_KW_STRING = 34,                 /* KW_STRING  */
  YYSYMBOL_KW_UNTIL = 35,                  /* KW_UNTIL  */
  YYSYMBOL_KW_PRINTLN = 36,                /* KW_PRINTLN  */
  YYSYMBOL_KW_READLINE = 37,               /* KW_READLINE  */
  YYSYMBOL_KW_PRINT = 38,                  /* KW_PRINT  */
  YYSYMBOL_KW_MAIN = 39,                   /* KW_MAIN  */
  YYSYMBOL_KW_ARGS = 40,                   /* KW_ARGS  */
  YYSYMBOL_TK_ID = 41,                     /* TK_ID  */
  YYSYMBOL_TK_LIT_STRING = 42,             /* TK_LIT_STRING  */
  YYSYMBOL_TK_LINE_COMMENT = 43,           /* TK_LINE_COMMENT  */
  YYSYMBOL_TK_BLOCK_COMMENT = 44,          /* TK_BLOCK_COMMENT  */
  YYSYMBOL_TK_LIT_FLOAT = 45,              /* TK_LIT_FLOAT  */
  YYSYMBOL_TK_LIT_INT = 46,                /* TK_LIT_INT  */
  YYSYMBOL_TK_LIT_CHAR = 47,               /* TK_LIT_CHAR  */
  YYSYMBOL_KW_TRUE = 48,                   /* KW_TRUE  */
  YYSYMBOL_KW_FALSE = 49,                  /* KW_FALSE  */
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
  YYSYMBOL_variable_decl = 77,             /* variable_decl  */
  YYSYMBOL_params = 78,                    /* params  */
  YYSYMBOL_array_param = 79,               /* array_param  */
  YYSYMBOL_args = 80,                      /* args  */
  YYSYMBOL_array_arg = 81,                 /* array_arg  */
  YYSYMBOL_stmt = 82,                      /* stmt  */
  YYSYMBOL_incre_decre_stmt = 83,          /* incre_decre_stmt  */
  YYSYMBOL_assignation_stmt = 84,          /* assignation_stmt  */
  YYSYMBOL_if_stmt = 85,                   /* if_stmt  */
  YYSYMBOL_print_stmt = 86,                /* print_stmt  */
  YYSYMBOL_loop_stmt = 87,                 /* loop_stmt  */
  YYSYMBOL_while_stmt = 88,                /* while_stmt  */
  YYSYMBOL_do_while_stmt = 89,             /* do_while_stmt  */
  YYSYMBOL_for_stmt = 90,                  /* for_stmt  */
  YYSYMBOL_comment_stmt = 91,              /* comment_stmt  */
  YYSYMBOL_returnORbreak_stmt = 92,        /* returnORbreak_stmt  */
  YYSYMBOL_methodcall_stmt = 93,           /* methodcall_stmt  */
  YYSYMBOL_expression = 94,                /* expression  */
  YYSYMBOL_comparison_expression = 95,     /* comparison_expression  */
  YYSYMBOL_arithmetic_expression = 96,     /* arithmetic_expression  */
  YYSYMBOL_term = 97,                      /* term  */
  YYSYMBOL_unary_expression = 98,          /* unary_expression  */
  YYSYMBOL_incre_decre_expression = 99,    /* incre_decre_expression  */
  YYSYMBOL_factor = 100,                   /* factor  */
  YYSYMBOL_literal = 101,                  /* literal  */
  YYSYMBOL_func_CallLiterals = 102,        /* func_CallLiterals  */
  YYSYMBOL_type = 103,                     /* type  */
  YYSYMBOL_func_type = 104,                /* func_type  */
  YYSYMBOL_type_identifier = 105           /* type_identifier  */
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
#define YYLAST   307

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  243

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
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    69,    70,    73,    74,    75,    76,    79,
      82,    83,    86,    87,    90,    91,    94,    95,    96,    97,
      98,    99,   102,   105,   106,   107,   108,   111,   112,   115,
     116,   117,   118,   119,   122,   123,   126,   127,   128,   129,
     130,   131,   132,   133,   136,   137,   138,   139,   142,   143,
     144,   145,   147,   148,   149,   152,   153,   154,   155,   158,
     159,   160,   163,   164,   167,   168,   169,   170,   173,   174,
     177,   178,   181,   182,   183,   184,   187,   192,   193,   194,
     195,   196,   199,   200,   201,   202,   203,   206,   207,   208,
     209,   212,   213,   214,   215,   218,   219,   220,   221,   224,
     225,   226,   227,   229,   230,   231,   232,   233,   236,   237,
     238,   239,   240,   241,   244,   245,   248,   251,   252,   255,
     256,   257,   258,   259
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
  "\"end of file\"", "error", "\"invalid token\"", "TK_INCREMENT",
  "TK_DECREMENT", "TK_AND", "TK_OR", "TK_EQUAL", "TK_NOT_EQUAL",
  "TK_LESS_EQUAL", "TK_GT_EQUAL", "TK_RANGE", "KW_BREAK", "KW_DO",
  "KW_ELSE", "KW_FOR", "KW_FUN", "KW_IF", "KW_IN", "KW_RETURN", "KW_VAR",
  "KW_CONTINUE", "KW_ARRAYOF", "KW_ARRAY", "KW_WHEN", "KW_IS", "KW_NULL",
  "KW_VAL", "KW_WHILE", "KW_CONST", "KW_INT", "KW_FLOAT", "KW_CHAR",
  "KW_BOOLEAN", "KW_STRING", "KW_UNTIL", "KW_PRINTLN", "KW_READLINE",
  "KW_PRINT", "KW_MAIN", "KW_ARGS", "TK_ID", "TK_LIT_STRING",
  "TK_LINE_COMMENT", "TK_BLOCK_COMMENT", "TK_LIT_FLOAT", "TK_LIT_INT",
  "TK_LIT_CHAR", "KW_TRUE", "KW_FALSE", "'('", "')'", "':'", "'<'", "'>'",
  "'{'", "'}'", "';'", "'='", "','", "'['", "']'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'!'", "$accept", "program", "functions", "func", "block",
  "decls_stmts", "decls_or_stmts", "decl", "decl_inline", "variable_decl",
  "params", "array_param", "args", "array_arg", "stmt", "incre_decre_stmt",
  "assignation_stmt", "if_stmt", "print_stmt", "loop_stmt", "while_stmt",
  "do_while_stmt", "for_stmt", "comment_stmt", "returnORbreak_stmt",
  "methodcall_stmt", "expression", "comparison_expression",
  "arithmetic_expression", "term", "unary_expression",
  "incre_decre_expression", "factor", "literal", "func_CallLiterals",
  "type", "func_type", "type_identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-108)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,    57,    39,  -108,    -5,    25,    32,  -108,  -108,   -10,
      50,    52,    72,    60,    69,    50,   105,   231,  -108,   232,
       4,  -108,    81,    78,   198,    87,   106,    16,   112,   112,
     108,   111,   120,    18,  -108,  -108,    99,   231,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,   122,  -108,  -108,  -108,  -108,  -108,   100,  -108,   247,
    -108,   137,  -108,   145,   163,   144,    16,   241,   241,   -18,
    -108,  -108,  -108,  -108,  -108,  -108,    16,   241,   241,    38,
      92,    23,    84,  -108,  -108,    20,  -108,   -27,  -108,    -9,
    -108,    16,    16,    16,   138,   146,   152,    16,    16,  -108,
    -108,   188,    50,   139,    72,  -108,   148,   155,   156,   191,
     103,  -108,  -108,   152,    16,   118,  -108,  -108,    16,    16,
      16,    16,  -108,    16,    16,    16,    16,    16,    16,    16,
      16,    16,    16,  -108,  -108,   247,   189,  -108,    16,   125,
     135,   157,  -108,  -108,   161,   165,   184,   152,   178,    46,
      44,   162,  -108,   188,  -108,   187,    16,    16,    16,   198,
     194,     8,  -108,    92,    92,    92,    92,    23,    23,    23,
      23,    84,    84,    84,  -108,  -108,  -108,  -108,   196,    65,
     198,   190,   195,   188,   152,  -108,  -108,   152,  -108,   199,
     181,   200,    72,   172,   176,   109,   242,  -108,  -108,  -108,
     188,  -108,  -108,  -108,  -108,  -108,   206,  -108,  -108,    16,
    -108,  -108,  -108,   204,   211,    16,    72,   217,   223,    56,
    -108,  -108,   182,  -108,   226,   183,  -108,   198,   238,   237,
     234,  -108,  -108,   246,   183,   239,   244,  -108,  -108,   183,
     245,   243,  -108
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     2,     4,     0,     0,     1,     3,     0,
      26,     0,     0,     0,     0,    26,     0,    11,     8,     0,
       0,    25,     0,    75,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,    71,     0,    11,    12,    13,
      43,    38,    37,    36,    40,    60,    61,    59,    39,    41,
      42,     0,   119,   120,   122,   121,   123,    24,   116,     0,
       6,     0,    74,     0,     0,     0,     0,     0,     0,   105,
     109,   111,   110,   108,   112,   113,     0,     0,     0,    73,
      81,    86,    90,    94,    97,    98,   104,     0,    15,    16,
      14,     0,     0,     0,    44,    46,     0,     0,     0,     9,
      10,     0,    26,     0,     0,   117,     0,     0,     0,     0,
       0,    99,   100,     0,     0,     0,    96,    95,     0,     0,
       0,     0,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   101,   102,     0,     0,    17,     0,     0,
       0,     0,    45,    47,     0,    30,     0,     0,    32,    48,
       0,     0,    23,     0,     5,     0,     0,     0,     0,     0,
       0,     0,   103,    78,    77,    79,    80,    84,    85,    83,
      82,    89,    87,    88,    91,    92,    93,    22,     0,    18,
       0,    56,    55,     0,     0,    76,    33,     0,    49,     0,
      28,     0,     0,     0,     0,     0,    52,    53,   107,   106,
       0,    19,    62,    63,    58,    57,     0,    29,    31,     0,
      27,   118,     7,    64,    65,     0,     0,     0,     0,    50,
      66,    67,     0,    54,     0,     0,    51,     0,     0,   115,
       0,    68,    69,     0,     0,    35,     0,   114,    34,     0,
       0,    20,    21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,   298,  -108,   -20,   266,  -108,  -108,   275,  -108,
     -12,  -108,  -107,  -108,   -23,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,   -64,   174,   -88,   -40,
      36,  -108,   -60,   -87,    71,   107,   171,   -54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    18,    36,    37,    38,    88,    89,
      14,    15,   146,   147,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    79,    80,    81,    82,
      83,    84,    85,    86,   230,    57,   104,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      60,    64,   110,    21,    63,   105,   160,   111,   112,   148,
     150,     1,   115,   118,   119,   120,   121,   116,   117,    67,
      68,    94,    95,   133,   134,   135,   148,   139,   140,   141,
      11,   136,   113,   149,   127,   167,   168,   169,   170,     7,
     186,    12,   114,   118,   119,   120,   121,   151,   137,   138,
     161,   118,   119,   120,   121,   127,    59,    69,    70,    17,
     148,    71,    72,    73,    74,    75,    76,   127,    96,   199,
     118,   119,   120,   121,   179,     9,    97,   207,    98,    77,
     208,   105,    10,    78,   154,   128,   129,   171,   172,   173,
     152,    13,   193,   194,   195,   122,     5,   148,     6,   191,
     148,   123,   124,   188,    16,   189,   128,   129,   118,   119,
     120,   121,    19,   226,   118,   119,   120,   121,   128,   129,
      20,   219,   201,   118,   119,   120,   121,    17,    22,   206,
     118,   119,   120,   121,    61,    62,   197,    65,   229,   196,
     118,   119,   120,   121,   215,   125,   126,   229,   130,   131,
     132,   222,   240,    87,   159,    99,    66,   203,    91,   102,
     202,    92,   118,   119,   120,   121,   174,   175,   176,   162,
      93,   106,   212,   107,   144,   101,   180,   118,   119,   120,
     121,   118,   119,   120,   121,   109,   181,   118,   119,   120,
     121,   108,   153,   145,    70,   142,   223,    71,    72,    73,
      74,    75,   155,   143,   232,   156,   157,   231,   182,   158,
      23,    24,   178,    25,   183,    26,   190,    27,    52,    53,
      54,    55,    56,   213,   184,    70,    30,   214,    71,    72,
      73,    74,    75,   227,    31,   185,    32,   187,   192,    33,
     210,    34,    35,    23,    24,   198,    25,   204,    26,   200,
      27,    28,   205,    17,   211,    51,   216,   209,    29,    30,
     218,   220,    52,    53,    54,    55,    56,    31,   221,    32,
     103,   224,    33,   225,    34,    35,   228,    52,    53,    54,
      55,    56,    69,    70,   233,   235,    71,    72,    73,    74,
      75,    76,   163,   164,   165,   166,   234,   236,   238,   239,
     242,   241,     8,   100,    90,   237,   177,   217
};

static const yytype_uint8 yycheck[] =
{
      20,    24,    66,    15,    24,    59,   113,    67,    68,    96,
      98,    16,    76,     5,     6,     7,     8,    77,    78,     3,
       4,     3,     4,     3,     4,    52,   113,    91,    92,    93,
      40,    58,    50,    97,    11,   123,   124,   125,   126,     0,
     147,    51,    60,     5,     6,     7,     8,   101,    57,    58,
     114,     5,     6,     7,     8,    11,    52,    41,    42,    55,
     147,    45,    46,    47,    48,    49,    50,    11,    50,    61,
       5,     6,     7,     8,   138,    50,    58,   184,    60,    63,
     187,   135,    50,    67,   104,    62,    63,   127,   128,   129,
     102,    41,   156,   157,   158,    57,    39,   184,    41,   153,
     187,     9,    10,    57,    52,    61,    62,    63,     5,     6,
       7,     8,    52,    57,     5,     6,     7,     8,    62,    63,
      51,   209,    57,     5,     6,     7,     8,    55,    23,   183,
       5,     6,     7,     8,    53,    57,   159,    50,   225,   159,
       5,     6,     7,     8,    35,    53,    54,   234,    64,    65,
      66,   215,   239,    41,    51,    56,    50,   180,    50,    59,
     180,    50,     5,     6,     7,     8,   130,   131,   132,    51,
      50,    34,   192,    28,    22,    53,    51,     5,     6,     7,
       8,     5,     6,     7,     8,    41,    51,     5,     6,     7,
       8,    28,    53,    41,    42,    57,   216,    45,    46,    47,
      48,    49,    54,    57,   227,    50,    50,   227,    51,    18,
      12,    13,    23,    15,    53,    17,    54,    19,    30,    31,
      32,    33,    34,    51,    59,    42,    28,    51,    45,    46,
      47,    48,    49,    51,    36,    51,    38,    59,    51,    41,
      59,    43,    44,    12,    13,    51,    15,    57,    17,    53,
      19,    20,    57,    55,    54,    23,    14,    58,    27,    28,
      54,    57,    30,    31,    32,    33,    34,    36,    57,    38,
      23,    54,    41,    50,    43,    44,    50,    30,    31,    32,
      33,    34,    41,    42,    46,    51,    45,    46,    47,    48,
      49,    50,   118,   119,   120,   121,    59,    51,    59,    55,
      57,    56,     4,    37,    29,   234,   135,   200
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,    69,    70,    71,    39,    41,     0,    70,    50,
      50,    40,    51,    41,    78,    79,    52,    55,    72,    52,
      51,    78,    23,    12,    13,    15,    17,    19,    20,    27,
      28,    36,    38,    41,    43,    44,    73,    74,    75,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    23,    30,    31,    32,    33,    34,   103,   105,    52,
      72,    53,    57,    72,    82,    50,    50,     3,     4,    41,
      42,    45,    46,    47,    48,    49,    50,    63,    67,    94,
      95,    96,    97,    98,    99,   100,   101,    41,    76,    77,
      76,    50,    50,    50,     3,     4,    50,    58,    60,    56,
      73,    53,    59,    23,   104,   105,    34,    28,    28,    41,
      94,   100,   100,    50,    60,    94,   100,   100,     5,     6,
       7,     8,    57,     9,    10,    53,    54,    11,    62,    63,
      64,    65,    66,     3,     4,    52,    58,    57,    58,    94,
      94,    94,    57,    57,    22,    41,    80,    81,   101,    94,
      96,   105,    78,    53,    72,    54,    50,    50,    18,    51,
      80,    94,    51,    95,    95,    95,    95,    96,    96,    96,
      96,    97,    97,    97,    98,    98,    98,   104,    23,    94,
      51,    51,    51,    53,    59,    51,    80,    59,    57,    61,
      54,   105,    51,    94,    94,    94,    72,    82,    51,    61,
      53,    57,    72,    82,    57,    57,   105,    80,    80,    58,
      59,    54,    72,    51,    51,    35,    14,   103,    54,    96,
      57,    57,    94,    72,    54,    50,    57,    51,    50,   101,
     102,    72,    82,    46,    59,    51,    51,   102,    59,    55,
     101,    56,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    68,    69,    70,    70,    71,    71,    71,    71,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    76,    76,
      76,    76,    77,    78,    78,    78,    78,    79,    79,    80,
      80,    80,    80,    80,    81,    81,    82,    82,    82,    82,
      82,    82,    82,    82,    83,    83,    83,    83,    84,    84,
      84,    84,    85,    85,    85,    86,    86,    86,    86,    87,
      87,    87,    88,    88,    89,    89,    89,    89,    90,    90,
      91,    91,    92,    92,    92,    92,    93,    94,    94,    94,
      94,    94,    95,    95,    95,    95,    95,    96,    96,    96,
      96,    97,    97,    97,    97,    98,    98,    98,    98,    99,
      99,    99,    99,   100,   100,   100,   100,   100,   101,   101,
     101,   101,   101,   101,   102,   102,   103,   104,   104,   105,
     105,   105,   105,   105
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     8,     6,    11,     5,     3,
       2,     0,     1,     1,     2,     2,     1,     2,     3,     4,
      12,    13,     3,     5,     3,     2,     0,     7,     6,     3,
       1,     3,     1,     2,     8,     7,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     2,     3,     3,     4,
       6,     7,     5,     5,     7,     4,     4,     5,     5,     1,
       1,     1,     5,     5,     6,     6,     7,     7,     9,     9,
       1,     1,     3,     2,     2,     1,     4,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     1,     2,     2,     1,     1,     2,
       2,     2,     2,     3,     1,     1,     4,     4,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     4,     1,
       1,     1,     1,     1
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
  case 2: /* program: functions  */
#line 63 "mini-kotlin.y"
        {
           (yyval.statement_t) = new BlockFunctionStatement((yyvsp[0].stmt_list_t), line, column);
           (yyval.statement_t)->evaluateSemantic();
        }
#line 1360 "mini-kotlin_parser.cpp"
    break;

  case 3: /* functions: func functions  */
#line 69 "mini-kotlin.y"
                          { (yyval.stmt_list_t) = (yyvsp[0].stmt_list_t); (yyval.stmt_list_t)->push_back((yyvsp[-1].statement_t)); }
#line 1366 "mini-kotlin_parser.cpp"
    break;

  case 4: /* functions: %empty  */
#line 70 "mini-kotlin.y"
                  { (yyval.stmt_list_t) = new list<Statement*>; }
#line 1372 "mini-kotlin_parser.cpp"
    break;

  case 5: /* func: KW_FUN TK_ID '(' params ')' ':' func_type block  */
#line 73 "mini-kotlin.y"
                                                      { (yyval.statement_t) = new FunctionStatement((yyvsp[-6].string_t), (yyvsp[-4].var_declaration_list_t), (yyvsp[-1].type_t), (yyvsp[0].statement_t), line, column); }
#line 1378 "mini-kotlin_parser.cpp"
    break;

  case 6: /* func: KW_FUN TK_ID '(' params ')' block  */
#line 74 "mini-kotlin.y"
                                        { (yyval.statement_t) = new FunctionStatement((yyvsp[-4].string_t), (yyvsp[-2].var_declaration_list_t), new ComplexType(VOID, false), (yyvsp[0].statement_t), line, column); }
#line 1384 "mini-kotlin_parser.cpp"
    break;

  case 7: /* func: KW_FUN KW_MAIN '(' KW_ARGS ':' KW_ARRAY '<' KW_STRING '>' ')' block  */
#line 75 "mini-kotlin.y"
                                                                          {}
#line 1390 "mini-kotlin_parser.cpp"
    break;

  case 8: /* func: KW_FUN KW_MAIN '(' ')' block  */
#line 76 "mini-kotlin.y"
                                   { (yyval.statement_t) = new FunctionStatement("main", new list<VarDeclarationStatement *>, new ComplexType(VOID, false), (yyvsp[0].statement_t), line, column);  }
#line 1396 "mini-kotlin_parser.cpp"
    break;

  case 9: /* block: '{' decls_stmts '}'  */
#line 79 "mini-kotlin.y"
                           { (yyval.statement_t) = new BlockStatement((yyvsp[-1].stmt_list_t), line, column); }
#line 1402 "mini-kotlin_parser.cpp"
    break;

  case 10: /* decls_stmts: decls_or_stmts decls_stmts  */
#line 82 "mini-kotlin.y"
                                        { (yyval.stmt_list_t) = (yyvsp[0].stmt_list_t); (yyval.stmt_list_t)->push_back((yyvsp[-1].statement_t)); }
#line 1408 "mini-kotlin_parser.cpp"
    break;

  case 11: /* decls_stmts: %empty  */
#line 83 "mini-kotlin.y"
                          { (yyval.stmt_list_t) = new list<Statement *>; }
#line 1414 "mini-kotlin_parser.cpp"
    break;

  case 12: /* decls_or_stmts: decl  */
#line 86 "mini-kotlin.y"
                     { (yyval.statement_t) = (yyvsp[0].decl_t); }
#line 1420 "mini-kotlin_parser.cpp"
    break;

  case 13: /* decls_or_stmts: stmt  */
#line 87 "mini-kotlin.y"
                     { (yyval.statement_t) = (yyvsp[0].statement_t); }
#line 1426 "mini-kotlin_parser.cpp"
    break;

  case 14: /* decl: KW_VAL decl_inline  */
#line 90 "mini-kotlin.y"
                         { (yyval.decl_t) = (yyvsp[0].decl_t); }
#line 1432 "mini-kotlin_parser.cpp"
    break;

  case 15: /* decl: KW_VAR decl_inline  */
#line 91 "mini-kotlin.y"
                         { (yyval.decl_t) = (yyvsp[0].decl_t); }
#line 1438 "mini-kotlin_parser.cpp"
    break;

  case 16: /* decl_inline: variable_decl  */
#line 94 "mini-kotlin.y"
                           { (yyval.decl_t) = (yyvsp[0].var_declaration_t); }
#line 1444 "mini-kotlin_parser.cpp"
    break;

  case 17: /* decl_inline: variable_decl ';'  */
#line 95 "mini-kotlin.y"
                              { (yyval.decl_t) = (yyvsp[-1].var_declaration_t); }
#line 1450 "mini-kotlin_parser.cpp"
    break;

  case 18: /* decl_inline: variable_decl '=' expression  */
#line 96 "mini-kotlin.y"
                                         { (yyval.decl_t) = new VarDeclAssignStatement((yyvsp[-2].var_declaration_t), (yyvsp[0].expr_t), line, column); }
#line 1456 "mini-kotlin_parser.cpp"
    break;

  case 19: /* decl_inline: variable_decl '=' expression ';'  */
#line 97 "mini-kotlin.y"
                                             { (yyval.decl_t) = new VarDeclAssignStatement((yyvsp[-3].var_declaration_t), (yyvsp[-1].expr_t), line, column); }
#line 1462 "mini-kotlin_parser.cpp"
    break;

  case 20: /* decl_inline: TK_ID '=' KW_ARRAY '<' type '>' '(' TK_LIT_INT ')' '{' literal '}'  */
#line 98 "mini-kotlin.y"
                                                                               { (yyval.decl_t) = new ArrayVarDeclAssignStatement((yyvsp[-11].string_t), (yyvsp[-7].type_t), (yyvsp[-4].int_t), (yyvsp[-1].expr_t), line, column); }
#line 1468 "mini-kotlin_parser.cpp"
    break;

  case 21: /* decl_inline: TK_ID '=' KW_ARRAY '<' type '>' '(' TK_LIT_INT ')' '{' literal '}' ';'  */
#line 99 "mini-kotlin.y"
                                                                                   { (yyval.decl_t) = new ArrayVarDeclAssignStatement((yyvsp[-12].string_t), (yyvsp[-8].type_t), (yyvsp[-5].int_t), (yyvsp[-2].expr_t), line, column); }
#line 1474 "mini-kotlin_parser.cpp"
    break;

  case 22: /* variable_decl: TK_ID ':' func_type  */
#line 102 "mini-kotlin.y"
                                   { (yyval.var_declaration_t) = new VarDeclarationStatement((yyvsp[-2].string_t),(yyvsp[0].type_t),line, column);}
#line 1480 "mini-kotlin_parser.cpp"
    break;

  case 23: /* params: TK_ID ':' type ',' params  */
#line 105 "mini-kotlin.y"
                                  { (yyval.var_declaration_list_t) = (yyvsp[0].var_declaration_list_t); (yyval.var_declaration_list_t)->push_back(new VarDeclarationStatement((yyvsp[-4].string_t), (yyvsp[-2].type_t), line, column)); }
#line 1486 "mini-kotlin_parser.cpp"
    break;

  case 24: /* params: TK_ID ':' type  */
#line 106 "mini-kotlin.y"
                         { (yyval.var_declaration_list_t) = new list<VarDeclarationStatement *>; (yyval.var_declaration_list_t)->push_back(new VarDeclarationStatement((yyvsp[-2].string_t), (yyvsp[0].type_t), line, column));}
#line 1492 "mini-kotlin_parser.cpp"
    break;

  case 25: /* params: array_param params  */
#line 107 "mini-kotlin.y"
                             { (yyval.var_declaration_list_t) = (yyvsp[0].var_declaration_list_t); (yyval.var_declaration_list_t)->push_back((yyvsp[-1].var_declaration_t)); }
#line 1498 "mini-kotlin_parser.cpp"
    break;

  case 26: /* params: %empty  */
#line 108 "mini-kotlin.y"
                      { (yyval.var_declaration_list_t) = new list<VarDeclarationStatement *>; }
#line 1504 "mini-kotlin_parser.cpp"
    break;

  case 27: /* array_param: TK_ID ':' KW_ARRAY '<' type_identifier '>' ','  */
#line 111 "mini-kotlin.y"
                                                            { (yyval.var_declaration_t) = new VarDeclarationStatement((yyvsp[-6].string_t), new ArrayType(1,(PrimitiveType)(yyvsp[-2].int_t)), line, column); }
#line 1510 "mini-kotlin_parser.cpp"
    break;

  case 28: /* array_param: TK_ID ':' KW_ARRAY '<' type_identifier '>'  */
#line 112 "mini-kotlin.y"
                                                     { (yyval.var_declaration_t) = new VarDeclarationStatement((yyvsp[-5].string_t), new ArrayType(1,(PrimitiveType)(yyvsp[-1].int_t)), line, column); }
#line 1516 "mini-kotlin_parser.cpp"
    break;

  case 29: /* args: TK_ID ',' args  */
#line 115 "mini-kotlin.y"
                     { (yyval.expr_list_t) = (yyvsp[0].expr_list_t); (yyval.expr_list_t)->push_back(new IdExpression((yyvsp[-2].string_t), line, column)); }
#line 1522 "mini-kotlin_parser.cpp"
    break;

  case 30: /* args: TK_ID  */
#line 116 "mini-kotlin.y"
                { (yyval.expr_list_t) = new list<Expression *>; (yyval.expr_list_t)->push_back(new IdExpression((yyvsp[0].string_t), line, column)); }
#line 1528 "mini-kotlin_parser.cpp"
    break;

  case 31: /* args: literal ',' args  */
#line 117 "mini-kotlin.y"
                           { (yyval.expr_list_t) = (yyvsp[0].expr_list_t); (yyval.expr_list_t)->push_back((yyvsp[-2].expr_t)); }
#line 1534 "mini-kotlin_parser.cpp"
    break;

  case 32: /* args: literal  */
#line 118 "mini-kotlin.y"
                  { (yyval.expr_list_t) = new list<Expression *>; (yyval.expr_list_t)->push_back((yyvsp[0].expr_t)); }
#line 1540 "mini-kotlin_parser.cpp"
    break;

  case 33: /* args: array_arg args  */
#line 119 "mini-kotlin.y"
                         { (yyval.expr_list_t) = (yyvsp[0].expr_list_t); (yyval.expr_list_t)->push_back((yyvsp[-1].expr_t)); }
#line 1546 "mini-kotlin_parser.cpp"
    break;

  case 34: /* array_arg: KW_ARRAYOF '<' type_identifier '>' '(' func_CallLiterals ')' ','  */
#line 122 "mini-kotlin.y"
                                                                            { (yyval.expr_t) = new ArrayArgExpression(new ArrayType(1,(PrimitiveType)(yyvsp[-5].int_t)), (yyvsp[-2].expr_list_t), line, column); }
#line 1552 "mini-kotlin_parser.cpp"
    break;

  case 35: /* array_arg: KW_ARRAYOF '<' type_identifier '>' '(' func_CallLiterals ')'  */
#line 123 "mini-kotlin.y"
                                                                       { (yyval.expr_t) = new ArrayArgExpression(new ArrayType(1,(PrimitiveType)(yyvsp[-4].int_t)), (yyvsp[-1].expr_list_t), line, column); }
#line 1558 "mini-kotlin_parser.cpp"
    break;

  case 36: /* stmt: print_stmt  */
#line 126 "mini-kotlin.y"
                 { (yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1564 "mini-kotlin_parser.cpp"
    break;

  case 37: /* stmt: if_stmt  */
#line 127 "mini-kotlin.y"
              { (yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1570 "mini-kotlin_parser.cpp"
    break;

  case 38: /* stmt: assignation_stmt  */
#line 128 "mini-kotlin.y"
                       { (yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1576 "mini-kotlin_parser.cpp"
    break;

  case 39: /* stmt: comment_stmt  */
#line 129 "mini-kotlin.y"
                   { (yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1582 "mini-kotlin_parser.cpp"
    break;

  case 40: /* stmt: loop_stmt  */
#line 130 "mini-kotlin.y"
                { (yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1588 "mini-kotlin_parser.cpp"
    break;

  case 41: /* stmt: returnORbreak_stmt  */
#line 131 "mini-kotlin.y"
                         { (yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1594 "mini-kotlin_parser.cpp"
    break;

  case 42: /* stmt: methodcall_stmt  */
#line 132 "mini-kotlin.y"
                      { (yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1600 "mini-kotlin_parser.cpp"
    break;

  case 43: /* stmt: incre_decre_stmt  */
#line 133 "mini-kotlin.y"
                       { (yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1606 "mini-kotlin_parser.cpp"
    break;

  case 44: /* incre_decre_stmt: TK_ID TK_INCREMENT  */
#line 136 "mini-kotlin.y"
                                     { (yyval.statement_t) = new IncreDecreStatement(new IncreDecreExpression(INCRE, new IdExpression((yyvsp[-1].string_t), line, column), line, column), line, column); }
#line 1612 "mini-kotlin_parser.cpp"
    break;

  case 45: /* incre_decre_stmt: TK_ID TK_INCREMENT ';'  */
#line 137 "mini-kotlin.y"
                                         { (yyval.statement_t) = new IncreDecreStatement(new IncreDecreExpression(INCRE, new IdExpression((yyvsp[-2].string_t), line, column), line, column), line, column); }
#line 1618 "mini-kotlin_parser.cpp"
    break;

  case 46: /* incre_decre_stmt: TK_ID TK_DECREMENT  */
#line 138 "mini-kotlin.y"
                                     { (yyval.statement_t) = new IncreDecreStatement(new IncreDecreExpression(DECRE, new IdExpression((yyvsp[-1].string_t), line, column), line, column), line, column); }
#line 1624 "mini-kotlin_parser.cpp"
    break;

  case 47: /* incre_decre_stmt: TK_ID TK_DECREMENT ';'  */
#line 139 "mini-kotlin.y"
                                         { (yyval.statement_t) = new IncreDecreStatement(new IncreDecreExpression(DECRE, new IdExpression((yyvsp[-2].string_t), line, column), line, column), line, column); }
#line 1630 "mini-kotlin_parser.cpp"
    break;

  case 48: /* assignation_stmt: TK_ID '=' expression  */
#line 142 "mini-kotlin.y"
                                       { (yyval.statement_t) = new AssignationStatement((yyvsp[-2].string_t), (yyvsp[0].expr_t), NULL, line, column);}
#line 1636 "mini-kotlin_parser.cpp"
    break;

  case 49: /* assignation_stmt: TK_ID '=' expression ';'  */
#line 143 "mini-kotlin.y"
                                           { (yyval.statement_t) = new AssignationStatement((yyvsp[-3].string_t), (yyvsp[-1].expr_t), NULL, line, column);}
#line 1642 "mini-kotlin_parser.cpp"
    break;

  case 50: /* assignation_stmt: TK_ID '[' arithmetic_expression ']' '=' arithmetic_expression  */
#line 144 "mini-kotlin.y"
                                                                                { (yyval.statement_t) = new AssignationStatement((yyvsp[-5].string_t), (yyvsp[0].expr_t), (yyvsp[-3].expr_t), line, column);}
#line 1648 "mini-kotlin_parser.cpp"
    break;

  case 51: /* assignation_stmt: TK_ID '[' arithmetic_expression ']' '=' arithmetic_expression ';'  */
#line 145 "mini-kotlin.y"
                                                                                    { (yyval.statement_t) = new AssignationStatement((yyvsp[-6].string_t), (yyvsp[-1].expr_t), (yyvsp[-4].expr_t), line, column);}
#line 1654 "mini-kotlin_parser.cpp"
    break;

  case 52: /* if_stmt: KW_IF '(' expression ')' block  */
#line 147 "mini-kotlin.y"
                                        { (yyval.statement_t) = new IfStatement((yyvsp[-2].expr_t), (yyvsp[0].statement_t), NULL, line, column);}
#line 1660 "mini-kotlin_parser.cpp"
    break;

  case 53: /* if_stmt: KW_IF '(' expression ')' stmt  */
#line 148 "mini-kotlin.y"
                                       { (yyval.statement_t) = new IfStatement((yyvsp[-2].expr_t), (yyvsp[0].statement_t), NULL, line, column);}
#line 1666 "mini-kotlin_parser.cpp"
    break;

  case 54: /* if_stmt: KW_IF '(' expression ')' block KW_ELSE block  */
#line 149 "mini-kotlin.y"
                                                      { (yyval.statement_t) = new IfStatement((yyvsp[-4].expr_t), (yyvsp[-2].statement_t), (yyvsp[0].statement_t), line, column);}
#line 1672 "mini-kotlin_parser.cpp"
    break;

  case 55: /* print_stmt: KW_PRINT '(' expression ')'  */
#line 152 "mini-kotlin.y"
                                        { (yyval.statement_t) = new PrintStatement((yyvsp[-1].expr_t), line, column);}
#line 1678 "mini-kotlin_parser.cpp"
    break;

  case 56: /* print_stmt: KW_PRINTLN '(' expression ')'  */
#line 153 "mini-kotlin.y"
                                          { (yyval.statement_t) = new PrintStatement((yyvsp[-1].expr_t), line, column);}
#line 1684 "mini-kotlin_parser.cpp"
    break;

  case 57: /* print_stmt: KW_PRINT '(' expression ')' ';'  */
#line 154 "mini-kotlin.y"
                                            { (yyval.statement_t) = new PrintStatement((yyvsp[-2].expr_t), line, column);}
#line 1690 "mini-kotlin_parser.cpp"
    break;

  case 58: /* print_stmt: KW_PRINTLN '(' expression ')' ';'  */
#line 155 "mini-kotlin.y"
                                              { (yyval.statement_t) = new PrintStatement((yyvsp[-2].expr_t), line, column);}
#line 1696 "mini-kotlin_parser.cpp"
    break;

  case 59: /* loop_stmt: for_stmt  */
#line 158 "mini-kotlin.y"
                    { (yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1702 "mini-kotlin_parser.cpp"
    break;

  case 60: /* loop_stmt: while_stmt  */
#line 159 "mini-kotlin.y"
                      { (yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1708 "mini-kotlin_parser.cpp"
    break;

  case 61: /* loop_stmt: do_while_stmt  */
#line 160 "mini-kotlin.y"
                         { (yyval.statement_t) = (yyvsp[0].statement_t);}
#line 1714 "mini-kotlin_parser.cpp"
    break;

  case 62: /* while_stmt: KW_WHILE '(' expression ')' block  */
#line 163 "mini-kotlin.y"
                                              { (yyval.statement_t) = new WhileStatement((yyvsp[-2].expr_t), (yyvsp[0].statement_t), line, column); }
#line 1720 "mini-kotlin_parser.cpp"
    break;

  case 63: /* while_stmt: KW_WHILE '(' expression ')' stmt  */
#line 164 "mini-kotlin.y"
                                             { (yyval.statement_t) = new WhileStatement((yyvsp[-2].expr_t), (yyvsp[0].statement_t), line, column); }
#line 1726 "mini-kotlin_parser.cpp"
    break;

  case 64: /* do_while_stmt: KW_DO block KW_WHILE '(' expression ')'  */
#line 167 "mini-kotlin.y"
                                                       { (yyval.statement_t) = new WhileStatement((yyvsp[-1].expr_t), (yyvsp[-4].statement_t), line, column); }
#line 1732 "mini-kotlin_parser.cpp"
    break;

  case 65: /* do_while_stmt: KW_DO stmt KW_WHILE '(' expression ')'  */
#line 168 "mini-kotlin.y"
                                                      { (yyval.statement_t) = new WhileStatement((yyvsp[-1].expr_t), (yyvsp[-4].statement_t), line, column); }
#line 1738 "mini-kotlin_parser.cpp"
    break;

  case 66: /* do_while_stmt: KW_DO block KW_WHILE '(' expression ')' ';'  */
#line 169 "mini-kotlin.y"
                                                           { (yyval.statement_t) = new WhileStatement((yyvsp[-2].expr_t), (yyvsp[-5].statement_t), line, column); }
#line 1744 "mini-kotlin_parser.cpp"
    break;

  case 67: /* do_while_stmt: KW_DO stmt KW_WHILE '(' expression ')' ';'  */
#line 170 "mini-kotlin.y"
                                                          { (yyval.statement_t) = new WhileStatement((yyvsp[-2].expr_t), (yyvsp[-5].statement_t), line, column); }
#line 1750 "mini-kotlin_parser.cpp"
    break;

  case 68: /* for_stmt: KW_FOR '(' TK_ID KW_IN expression KW_UNTIL expression ')' block  */
#line 173 "mini-kotlin.y"
                                                                          { (yyval.statement_t) = new ForStatement((yyvsp[-6].string_t),(yyvsp[-4].expr_t),(yyvsp[-2].expr_t),(yyvsp[0].statement_t), line, column);}
#line 1756 "mini-kotlin_parser.cpp"
    break;

  case 69: /* for_stmt: KW_FOR '(' TK_ID KW_IN expression KW_UNTIL expression ')' stmt  */
#line 174 "mini-kotlin.y"
                                                                     { (yyval.statement_t) = new ForStatement((yyvsp[-6].string_t),(yyvsp[-4].expr_t),(yyvsp[-2].expr_t),(yyvsp[0].statement_t), line, column);}
#line 1762 "mini-kotlin_parser.cpp"
    break;

  case 70: /* comment_stmt: TK_LINE_COMMENT  */
#line 177 "mini-kotlin.y"
                              { (yyval.statement_t) = new CommentStatement((yyvsp[0].string_t),line, column);}
#line 1768 "mini-kotlin_parser.cpp"
    break;

  case 71: /* comment_stmt: TK_BLOCK_COMMENT  */
#line 178 "mini-kotlin.y"
                               { (yyval.statement_t) = new CommentStatement((yyvsp[0].string_t),line, column);}
#line 1774 "mini-kotlin_parser.cpp"
    break;

  case 72: /* returnORbreak_stmt: KW_RETURN expression ';'  */
#line 181 "mini-kotlin.y"
                                             { (yyval.statement_t) = new ReturnStatement((yyvsp[-1].expr_t), line, column);}
#line 1780 "mini-kotlin_parser.cpp"
    break;

  case 73: /* returnORbreak_stmt: KW_RETURN expression  */
#line 182 "mini-kotlin.y"
                                   { (yyval.statement_t) = new ReturnStatement((yyvsp[0].expr_t), line, column);}
#line 1786 "mini-kotlin_parser.cpp"
    break;

  case 74: /* returnORbreak_stmt: KW_BREAK ';'  */
#line 183 "mini-kotlin.y"
                           { (yyval.statement_t) = new ReturnStatement(NULL, line, column);}
#line 1792 "mini-kotlin_parser.cpp"
    break;

  case 75: /* returnORbreak_stmt: KW_BREAK  */
#line 184 "mini-kotlin.y"
                       { (yyval.statement_t) = new ReturnStatement(NULL, line, column);}
#line 1798 "mini-kotlin_parser.cpp"
    break;

  case 76: /* methodcall_stmt: TK_ID '(' args ')'  */
#line 187 "mini-kotlin.y"
                                    { (yyval.statement_t) = new ExpressionStatement(new MethodCallExpression(new IdExpression((yyvsp[-3].string_t),line,column),(yyvsp[-1].expr_list_t), line,column),line,column);}
#line 1804 "mini-kotlin_parser.cpp"
    break;

  case 77: /* expression: expression TK_OR comparison_expression  */
#line 192 "mini-kotlin.y"
                                                   { (yyval.expr_t) = new OrExpression((yyvsp[-2].expr_t), (yyvsp[0].expr_t), line, column); }
#line 1810 "mini-kotlin_parser.cpp"
    break;

  case 78: /* expression: expression TK_AND comparison_expression  */
#line 193 "mini-kotlin.y"
                                                   { (yyval.expr_t) = new AndExpression((yyvsp[-2].expr_t), (yyvsp[0].expr_t), line, column); }
#line 1816 "mini-kotlin_parser.cpp"
    break;

  case 79: /* expression: expression TK_EQUAL comparison_expression  */
#line 194 "mini-kotlin.y"
                                                    { (yyval.expr_t) = new EqExpression((yyvsp[-2].expr_t), (yyvsp[0].expr_t), line, column); }
#line 1822 "mini-kotlin_parser.cpp"
    break;

  case 80: /* expression: expression TK_NOT_EQUAL comparison_expression  */
#line 195 "mini-kotlin.y"
                                                        { (yyval.expr_t) = new NeqExpression((yyvsp[-2].expr_t), (yyvsp[0].expr_t), line, column); }
#line 1828 "mini-kotlin_parser.cpp"
    break;

  case 81: /* expression: comparison_expression  */
#line 196 "mini-kotlin.y"
                                { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 1834 "mini-kotlin_parser.cpp"
    break;

  case 82: /* comparison_expression: comparison_expression '>' arithmetic_expression  */
#line 199 "mini-kotlin.y"
                                                                       { (yyval.expr_t) = new GtExpression((yyvsp[-2].expr_t), (yyvsp[0].expr_t), line, column); }
#line 1840 "mini-kotlin_parser.cpp"
    break;

  case 83: /* comparison_expression: comparison_expression '<' arithmetic_expression  */
#line 200 "mini-kotlin.y"
                                                          { (yyval.expr_t) = new LtExpression((yyvsp[-2].expr_t), (yyvsp[0].expr_t), line, column); }
#line 1846 "mini-kotlin_parser.cpp"
    break;

  case 84: /* comparison_expression: comparison_expression TK_LESS_EQUAL arithmetic_expression  */
#line 201 "mini-kotlin.y"
                                                                     { (yyval.expr_t) = new LteExpression((yyvsp[-2].expr_t), (yyvsp[0].expr_t), line, column); }
#line 1852 "mini-kotlin_parser.cpp"
    break;

  case 85: /* comparison_expression: comparison_expression TK_GT_EQUAL arithmetic_expression  */
#line 202 "mini-kotlin.y"
                                                                  { (yyval.expr_t) = new GteExpression((yyvsp[-2].expr_t), (yyvsp[0].expr_t), line, column); }
#line 1858 "mini-kotlin_parser.cpp"
    break;

  case 86: /* comparison_expression: arithmetic_expression  */
#line 203 "mini-kotlin.y"
                                { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 1864 "mini-kotlin_parser.cpp"
    break;

  case 87: /* arithmetic_expression: arithmetic_expression '+' term  */
#line 206 "mini-kotlin.y"
                                                      { (yyval.expr_t) = new AddExpression((yyvsp[-2].expr_t), (yyvsp[0].expr_t), line, column); }
#line 1870 "mini-kotlin_parser.cpp"
    break;

  case 88: /* arithmetic_expression: arithmetic_expression '-' term  */
#line 207 "mini-kotlin.y"
                                         { (yyval.expr_t) = new SubExpression((yyvsp[-2].expr_t), (yyvsp[0].expr_t), line, column); }
#line 1876 "mini-kotlin_parser.cpp"
    break;

  case 89: /* arithmetic_expression: arithmetic_expression TK_RANGE term  */
#line 208 "mini-kotlin.y"
                                              { (yyval.expr_t) = new RangeExpression((yyvsp[-2].expr_t), (yyvsp[0].expr_t), line, column); }
#line 1882 "mini-kotlin_parser.cpp"
    break;

  case 90: /* arithmetic_expression: term  */
#line 209 "mini-kotlin.y"
               { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 1888 "mini-kotlin_parser.cpp"
    break;

  case 91: /* term: term '*' unary_expression  */
#line 212 "mini-kotlin.y"
                                { (yyval.expr_t) = new MultExpression((yyvsp[-2].expr_t), (yyvsp[0].expr_t), line, column); }
#line 1894 "mini-kotlin_parser.cpp"
    break;

  case 92: /* term: term '/' unary_expression  */
#line 213 "mini-kotlin.y"
                                { (yyval.expr_t) = new DivExpression((yyvsp[-2].expr_t), (yyvsp[0].expr_t), line, column); }
#line 1900 "mini-kotlin_parser.cpp"
    break;

  case 93: /* term: term '%' unary_expression  */
#line 214 "mini-kotlin.y"
                                { (yyval.expr_t) = new ModExpression((yyvsp[-2].expr_t), (yyvsp[0].expr_t), line, column); }
#line 1906 "mini-kotlin_parser.cpp"
    break;

  case 94: /* term: unary_expression  */
#line 215 "mini-kotlin.y"
                       { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 1912 "mini-kotlin_parser.cpp"
    break;

  case 95: /* unary_expression: '!' factor  */
#line 218 "mini-kotlin.y"
                              { (yyval.expr_t) = new UnaryExpression(NOT, (yyvsp[0].expr_t), line, column); }
#line 1918 "mini-kotlin_parser.cpp"
    break;

  case 96: /* unary_expression: '-' factor  */
#line 219 "mini-kotlin.y"
                             { (yyval.expr_t) = new UnaryExpression(NEG, (yyvsp[0].expr_t), line, column); }
#line 1924 "mini-kotlin_parser.cpp"
    break;

  case 97: /* unary_expression: incre_decre_expression  */
#line 220 "mini-kotlin.y"
                                         { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 1930 "mini-kotlin_parser.cpp"
    break;

  case 98: /* unary_expression: factor  */
#line 221 "mini-kotlin.y"
                         { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 1936 "mini-kotlin_parser.cpp"
    break;

  case 99: /* incre_decre_expression: TK_INCREMENT factor  */
#line 224 "mini-kotlin.y"
                                             { (yyval.expr_t) = new IncreDecreExpression(INCRE, (yyvsp[0].expr_t), line, column); }
#line 1942 "mini-kotlin_parser.cpp"
    break;

  case 100: /* incre_decre_expression: TK_DECREMENT factor  */
#line 225 "mini-kotlin.y"
                                      { (yyval.expr_t) = new IncreDecreExpression(DECRE, (yyvsp[0].expr_t), line, column); }
#line 1948 "mini-kotlin_parser.cpp"
    break;

  case 101: /* incre_decre_expression: factor TK_INCREMENT  */
#line 226 "mini-kotlin.y"
                                      { (yyval.expr_t) = new IncreDecreExpression(INCRE, (yyvsp[-1].expr_t), line, column); }
#line 1954 "mini-kotlin_parser.cpp"
    break;

  case 102: /* incre_decre_expression: factor TK_DECREMENT  */
#line 227 "mini-kotlin.y"
                                      { (yyval.expr_t) = new IncreDecreExpression(DECRE, (yyvsp[-1].expr_t), line, column); }
#line 1960 "mini-kotlin_parser.cpp"
    break;

  case 103: /* factor: '(' expression ')'  */
#line 229 "mini-kotlin.y"
                           { (yyval.expr_t) = (yyvsp[-1].expr_t); }
#line 1966 "mini-kotlin_parser.cpp"
    break;

  case 104: /* factor: literal  */
#line 230 "mini-kotlin.y"
              { (yyval.expr_t) = (yyvsp[0].expr_t); }
#line 1972 "mini-kotlin_parser.cpp"
    break;

  case 105: /* factor: TK_ID  */
#line 231 "mini-kotlin.y"
            { (yyval.expr_t) = new IdExpression((yyvsp[0].string_t), line, column); }
#line 1978 "mini-kotlin_parser.cpp"
    break;

  case 106: /* factor: TK_ID '[' expression ']'  */
#line 232 "mini-kotlin.y"
                               { (yyval.expr_t) = new ArrayAccessExpression(new IdExpression((yyvsp[-3].string_t), line, column), (yyvsp[-1].expr_t), line, column); }
#line 1984 "mini-kotlin_parser.cpp"
    break;

  case 107: /* factor: TK_ID '(' args ')'  */
#line 233 "mini-kotlin.y"
                         { (yyval.expr_t) = new MethodCallExpression(new IdExpression((yyvsp[-3].string_t),line,column),(yyvsp[-1].expr_list_t), line,column); }
#line 1990 "mini-kotlin_parser.cpp"
    break;

  case 108: /* literal: TK_LIT_CHAR  */
#line 236 "mini-kotlin.y"
                     { (yyval.expr_t) = new CharExpression((yyvsp[0].char_t), line, column); }
#line 1996 "mini-kotlin_parser.cpp"
    break;

  case 109: /* literal: TK_LIT_STRING  */
#line 237 "mini-kotlin.y"
                       { (yyval.expr_t) = new StringExpression((yyvsp[0].string_t), line, column); }
#line 2002 "mini-kotlin_parser.cpp"
    break;

  case 110: /* literal: TK_LIT_INT  */
#line 238 "mini-kotlin.y"
                    { (yyval.expr_t) = new IntExpression((yyvsp[0].int_t), line, column); }
#line 2008 "mini-kotlin_parser.cpp"
    break;

  case 111: /* literal: TK_LIT_FLOAT  */
#line 239 "mini-kotlin.y"
                      { (yyval.expr_t) = new FloatExpression((yyvsp[0].float_t), line, column); }
#line 2014 "mini-kotlin_parser.cpp"
    break;

  case 112: /* literal: KW_TRUE  */
#line 240 "mini-kotlin.y"
                 { (yyval.expr_t) = new BooleanExpression(true, line, column); }
#line 2020 "mini-kotlin_parser.cpp"
    break;

  case 113: /* literal: KW_FALSE  */
#line 241 "mini-kotlin.y"
                  { (yyval.expr_t) = new BooleanExpression(false, line, column); }
#line 2026 "mini-kotlin_parser.cpp"
    break;

  case 114: /* func_CallLiterals: literal ',' func_CallLiterals  */
#line 244 "mini-kotlin.y"
                                                 { (yyval.expr_list_t) = (yyvsp[0].expr_list_t); (yyval.expr_list_t)->push_back((yyvsp[-2].expr_t)); }
#line 2032 "mini-kotlin_parser.cpp"
    break;

  case 115: /* func_CallLiterals: literal  */
#line 245 "mini-kotlin.y"
                          { (yyval.expr_list_t) = new list<Expression *>; (yyval.expr_list_t)->push_back((yyvsp[0].expr_t)); }
#line 2038 "mini-kotlin_parser.cpp"
    break;

  case 116: /* type: type_identifier  */
#line 248 "mini-kotlin.y"
                      { (yyval.type_t) = new ComplexType((PrimitiveType)(yyvsp[0].int_t), false); /*solo Primitive Type (non Array)*/ }
#line 2044 "mini-kotlin_parser.cpp"
    break;

  case 117: /* func_type: type_identifier  */
#line 251 "mini-kotlin.y"
                           { (yyval.type_t) = new ComplexType((PrimitiveType)(yyvsp[0].int_t), false); }
#line 2050 "mini-kotlin_parser.cpp"
    break;

  case 118: /* func_type: KW_ARRAY '<' type_identifier '>'  */
#line 252 "mini-kotlin.y"
                                       { (yyval.type_t) = new ArrayType(1,(PrimitiveType)(yyvsp[-1].int_t)); /*Si incluye Array*/}
#line 2056 "mini-kotlin_parser.cpp"
    break;

  case 119: /* type_identifier: KW_INT  */
#line 255 "mini-kotlin.y"
                        { (yyval.int_t) = INT; }
#line 2062 "mini-kotlin_parser.cpp"
    break;

  case 120: /* type_identifier: KW_FLOAT  */
#line 256 "mini-kotlin.y"
               { (yyval.int_t) = FLOAT;}
#line 2068 "mini-kotlin_parser.cpp"
    break;

  case 121: /* type_identifier: KW_BOOLEAN  */
#line 257 "mini-kotlin.y"
                 { (yyval.int_t) = BOOLEAN;}
#line 2074 "mini-kotlin_parser.cpp"
    break;

  case 122: /* type_identifier: KW_CHAR  */
#line 258 "mini-kotlin.y"
              { (yyval.int_t) = CHAR;}
#line 2080 "mini-kotlin_parser.cpp"
    break;

  case 123: /* type_identifier: KW_STRING  */
#line 259 "mini-kotlin.y"
                { (yyval.int_t) = STRING;}
#line 2086 "mini-kotlin_parser.cpp"
    break;


#line 2090 "mini-kotlin_parser.cpp"

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

#line 262 "mini-kotlin.y"
