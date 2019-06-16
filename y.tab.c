/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw3.y" /* yacc.c:339  */

//#include "xxxx.h" // include header if needed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
void yyerror(char *s);
extern char *error_type;
char *error_target;

typedef struct _symbol_table_entry {
	char name[32];
	char entry_type[32];
	char data_type[16];
	int scope_level;
	char formal_para[16][16];
}symbol_table_entry;

symbol_table_entry *symbol_table = NULL;
int table_pointer = 0;
extern int curr_scope;
char curr_formal_para[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
int curr_formal_para_index = 0;
int dump_on = -1;
int isGlobal = 1;
int hasError = 0;
FILE *deleteFile;

FILE *file; // To generate .j file for Jasmin

/* symbol table functions */
/*
int lookup_symbol();
void create_symbol_table();
void free_symbol_table();
void insert_symbol();
void dump_symbol();
*/

int lookup_symbol(char name[32]);
int notype_lookup_symbol(char name[32], int scope_level);
int deep_lookup_symbol(char name[32], int scope_level, char data_type[16]);
void create_symbol();
void insert_symbol(char name[32], char entry_type[32], char data_type[16], int scope_level, char formal_para[16][16]);
void dump_symbol();

char *takeID(char name[32]);

/* code generation functions, just an example! */
void gencode_function(char *cmd);


#line 123 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    PRINT = 258,
    IF = 259,
    ELSE = 260,
    FOR = 261,
    WHILE = 262,
    SEMICOLON = 263,
    LB = 264,
    RB = 265,
    LCB = 266,
    RCB = 267,
    LSB = 268,
    RSB = 269,
    COMMA = 270,
    RET = 271,
    CONTINUE = 272,
    BREAK = 273,
    C_COMMENT = 274,
    CPP_COMMENT = 275,
    NL = 276,
    I_CONST = 277,
    F_CONST = 278,
    TRUE_RESULT = 279,
    FALSE_RESULT = 280,
    INT = 281,
    FLOAT = 282,
    BOOL = 283,
    STRING = 284,
    VOID = 285,
    STR_CONST = 286,
    ID = 287,
    ASGN = 288,
    AND = 289,
    OR = 290,
    NOT = 291,
    ADDASGN = 292,
    SUBASGN = 293,
    MULASGN = 294,
    DIVASGN = 295,
    MODASGN = 296,
    MT = 297,
    LT = 298,
    MTE = 299,
    LTE = 300,
    EQ = 301,
    NE = 302,
    ADD = 303,
    SUB = 304,
    MUL = 305,
    DIV = 306,
    MOD = 307,
    INC = 308,
    DEC = 309
  };
#endif
/* Tokens.  */
#define PRINT 258
#define IF 259
#define ELSE 260
#define FOR 261
#define WHILE 262
#define SEMICOLON 263
#define LB 264
#define RB 265
#define LCB 266
#define RCB 267
#define LSB 268
#define RSB 269
#define COMMA 270
#define RET 271
#define CONTINUE 272
#define BREAK 273
#define C_COMMENT 274
#define CPP_COMMENT 275
#define NL 276
#define I_CONST 277
#define F_CONST 278
#define TRUE_RESULT 279
#define FALSE_RESULT 280
#define INT 281
#define FLOAT 282
#define BOOL 283
#define STRING 284
#define VOID 285
#define STR_CONST 286
#define ID 287
#define ASGN 288
#define AND 289
#define OR 290
#define NOT 291
#define ADDASGN 292
#define SUBASGN 293
#define MULASGN 294
#define DIVASGN 295
#define MODASGN 296
#define MT 297
#define LT 298
#define MTE 299
#define LTE 300
#define EQ 301
#define NE 302
#define ADD 303
#define SUB 304
#define MUL 305
#define DIV 306
#define MOD 307
#define INC 308
#define DEC 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 59 "compiler_hw3.y" /* yacc.c:355  */

	int i_val;
    double f_val;
    char* string;
    int bool_val;

#line 278 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 295 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   261

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   106,   106,   107,   111,   112,   113,   117,   118,   122,
     164,   165,   169,   337,   477,   643,   791,   900,   901,   905,
     906,   910,   939,   940,   941,   942,   943,   947,   948,   949,
     950,   951,   955,   956,   963,   964,   968,   973,   978,   979,
     995,   999,  1004,  1009,  1025,  1029,  1032,  1035,  1038,  1041,
    1044,  1047,  1050,  1053,  1056,  1059,  1062,  1065,  1068,  1071,
    1074,  1075,  1076,  1091,  1109,  1116,  1167,  1168,  1172,  1176,
    1177,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,
    1190,  1194,  1209,  1224,  1239,  1254,  1269,  1284,  1299,  1317,
    1347,  1363,  1367,  1371,  1390,  1391,  1395,  1396,  1400,  1401,
    1405,  1406,  1410,  1414,  1415
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINT", "IF", "ELSE", "FOR", "WHILE",
  "SEMICOLON", "LB", "RB", "LCB", "RCB", "LSB", "RSB", "COMMA", "RET",
  "CONTINUE", "BREAK", "C_COMMENT", "CPP_COMMENT", "NL", "I_CONST",
  "F_CONST", "TRUE_RESULT", "FALSE_RESULT", "INT", "FLOAT", "BOOL",
  "STRING", "VOID", "STR_CONST", "ID", "ASGN", "AND", "OR", "NOT",
  "ADDASGN", "SUBASGN", "MULASGN", "DIVASGN", "MODASGN", "MT", "LT", "MTE",
  "LTE", "EQ", "NE", "ADD", "SUB", "MUL", "DIV", "MOD", "INC", "DEC",
  "$accept", "program", "global_decl_or_functions",
  "global_decl_or_function", "new_line", "global_decl", "var_decl_global",
  "var_decl", "function_decl", "para_area", "paras", "para", "type",
  "global_initializer", "initializer", "logic_initializer",
  "number_initializer", "tf_initializer", "count_expr", "function_define",
  "function_define_head", "function_combound", "combound_area",
  "combound_area_inner", "stat", "asgn_stat", "print_stat", "print_target",
  "function_using", "para_area_using", "paras_using", "select_stat",
  "else_stat", "while_stat", "return_stat", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF -124

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-124)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -124,    13,  -124,  -124,  -124,  -124,  -124,  -124,  -124,   231,
    -124,  -124,  -124,  -124,  -124,   -18,  -124,     4,  -124,     0,
    -124,     4,  -124,  -124,  -124,   191,   225,    21,   115,  -124,
    -124,    17,  -124,     3,  -124,  -124,  -124,  -124,  -124,    23,
    -124,    36,    46,    48,  -124,  -124,   156,    76,  -124,  -124,
      55,  -124,  -124,    38,    80,    82,  -124,  -124,    83,  -124,
     231,  -124,  -124,   173,   190,   190,   190,  -124,  -124,  -124,
    -124,  -124,    -3,   190,  -124,   -17,   189,  -124,  -124,  -124,
      50,   156,   190,   190,   190,   190,   190,  -124,  -124,  -124,
      11,  -124,  -124,  -124,  -124,  -124,  -124,    -3,   -17,   189,
      96,    14,    18,   101,  -124,  -124,   -17,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,  -124,  -124,    61,  -124,   189,   189,   189,   189,
     189,  -124,   156,  -124,   145,   145,  -124,   -17,   -17,   189,
     189,   194,   194,   194,   194,   194,   194,    28,    28,    49,
      49,    49,  -124,   156,    84,     2,  -124,  -124,  -124,   145,
       2,  -124,  -124,  -124
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     9,    22,    23,    24,    25,    26,     2,
       5,     6,     7,    10,    11,     0,     8,     0,     4,     0,
      70,     0,    64,    66,    13,     0,     0,    65,     0,    67,
      18,     0,    20,     0,    27,    28,    30,    31,    29,     0,
      16,     0,     0,     0,    78,    68,   104,     0,    80,    72,
       0,    79,    69,     0,     0,     0,    75,    76,     0,    17,
       0,    21,    12,     0,     0,     0,     0,    36,    37,    41,
      42,    33,    39,     0,   103,    32,    34,    35,    38,    40,
       0,     0,     0,     0,     0,     0,     0,    87,    88,    93,
       0,    71,    73,    74,    77,    19,    91,    39,     0,    92,
       0,     0,     0,    38,    62,    63,    61,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,    97,     0,    81,    82,    83,    84,    85,
      86,    15,     0,    89,     0,     0,    60,    58,    59,    56,
      57,    50,    51,    52,    53,    54,    55,    45,    46,    47,
      48,    49,    94,     0,     0,    99,   102,    96,    14,     0,
       0,    98,   100,   101
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -124,  -124,  -124,   103,    -1,  -124,  -124,  -124,  -124,  -124,
    -124,    60,     1,  -124,   -76,   -43,   -16,  -124,    58,  -124,
    -124,   100,    37,  -124,  -123,  -124,  -124,  -124,   -27,  -124,
    -124,  -124,   -35,  -124,  -124
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     9,    10,    48,    12,    13,    49,    14,    27,
      31,    32,    50,    39,    74,    98,    76,    77,    78,    16,
      17,    22,    51,    28,    52,    53,    54,   100,    79,    89,
     124,    56,   161,    57,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      11,    55,    15,    75,   123,   125,    80,   159,    24,    25,
      15,   155,   156,     2,    19,    20,    21,   107,   108,   131,
      21,   101,   102,     3,   134,     3,    33,    59,   135,    40,
     106,    62,    60,    26,     3,    61,   162,    75,    75,     4,
       5,     6,     7,     8,   132,    63,    91,    99,   107,   108,
     104,   105,   107,   108,    23,    64,   154,    65,    23,    66,
     122,    33,   109,   110,   137,   138,   126,   127,   128,   129,
     130,   152,    67,    68,    69,    70,   153,   157,   119,   120,
     121,    71,    72,   109,   110,    80,    73,    90,    92,    75,
      93,    94,   158,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   133,    55,    55,    81,
      75,   136,    18,    82,    83,    84,    85,    86,    41,    42,
      95,    29,    43,    44,   103,   163,    20,    45,     0,    87,
      88,    46,    55,     0,     0,     0,     3,     0,     0,     0,
       0,     4,     5,     6,     7,     8,     0,    47,    41,    42,
       0,     0,    43,    44,   160,     0,    20,     0,     0,   160,
       0,    46,     0,     0,     0,    66,     3,     0,     0,     0,
       0,     4,     5,     6,     7,     8,     0,    47,    67,    68,
      69,    70,    66,     0,     0,     0,     0,    71,    72,     0,
       0,     0,    73,     0,     0,    67,    68,    69,    70,    66,
       0,    30,     0,     0,    96,    97,     0,     0,     0,    73,
       0,     0,    67,    68,    69,    70,     0,     4,     5,     6,
       7,     8,    72,   109,   110,     0,    73,     0,   109,   110,
       0,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   117,   118,   119,   120,   121,    34,    35,    36,
      37,     0,     0,     0,     0,     0,    38,     4,     5,     6,
       7,     8
};

static const yytype_int16 yycheck[] =
{
       1,    28,     1,    46,    80,    81,     9,     5,     8,     9,
       9,   134,   135,     0,    32,    11,    17,    34,    35,     8,
      21,    64,    65,    21,    10,    21,    25,    10,    10,     8,
      73,     8,    15,    33,    21,    32,   159,    80,    81,    26,
      27,    28,    29,    30,    33,     9,     8,    63,    34,    35,
      53,    54,    34,    35,    17,     9,   132,     9,    21,     9,
      10,    60,    34,    35,   107,   108,    82,    83,    84,    85,
      86,    10,    22,    23,    24,    25,    15,   153,    50,    51,
      52,    31,    32,    34,    35,     9,    36,    32,     8,   132,
       8,     8,     8,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    10,   134,   135,    33,
     153,    10,     9,    37,    38,    39,    40,    41,     3,     4,
      60,    21,     7,     8,    66,   160,    11,    12,    -1,    53,
      54,    16,   159,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,     3,     4,
      -1,    -1,     7,     8,   155,    -1,    11,    -1,    -1,   160,
      -1,    16,    -1,    -1,    -1,     9,    21,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    22,    23,
      24,    25,     9,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    36,    -1,    -1,    22,    23,    24,    25,     9,
      -1,    10,    -1,    -1,    31,    32,    -1,    -1,    -1,    36,
      -1,    -1,    22,    23,    24,    25,    -1,    26,    27,    28,
      29,    30,    32,    34,    35,    -1,    36,    -1,    34,    35,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    48,    49,    50,    51,    52,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    31,    26,    27,    28,
      29,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    56,     0,    21,    26,    27,    28,    29,    30,    57,
      58,    59,    60,    61,    63,    67,    74,    75,    58,    32,
      11,    59,    76,    77,     8,     9,    33,    64,    78,    76,
      10,    65,    66,    67,    22,    23,    24,    25,    31,    68,
       8,     3,     4,     7,     8,    12,    16,    32,    59,    62,
      67,    77,    79,    80,    81,    83,    86,    88,    89,    10,
      15,    32,     8,     9,     9,     9,     9,    22,    23,    24,
      25,    31,    32,    36,    69,    70,    71,    72,    73,    83,
       9,    33,    37,    38,    39,    40,    41,    53,    54,    84,
      32,     8,     8,     8,     8,    66,    31,    32,    70,    71,
      82,    70,    70,    73,    53,    54,    70,    34,    35,    34,
      35,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    10,    69,    85,    69,    71,    71,    71,    71,
      71,     8,    33,    10,    10,    10,    10,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    10,    15,    69,    79,    79,    69,     8,     5,
      59,    87,    79,    87
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    57,    58,    58,    59,
      60,    60,    61,    61,    62,    62,    63,    64,    64,    65,
      65,    66,    67,    67,    67,    67,    67,    68,    68,    68,
      68,    68,    69,    69,    70,    70,    71,    71,    71,    71,
      71,    72,    72,    72,    72,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    74,    75,    76,    76,    77,    78,
      78,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    80,    80,    80,    80,    80,    80,    80,    80,    81,
      82,    82,    82,    83,    84,    84,    85,    85,    86,    86,
      87,    87,    88,    89,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     5,     3,     5,     3,     4,     3,     2,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     3,     1,     2,     3,     2,
       0,     2,     1,     2,     2,     1,     1,     2,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     2,     2,     4,
       1,     1,     1,     2,     3,     2,     3,     1,     6,     5,
       2,     2,     5,     2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 9:
#line 122 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		if(strcmp(error_type, "") == 0)
			(strcmp(buf, "\n") == 0)?printf("%d:%s", yylineno, buf):printf("%d: %s", yylineno, buf); 
		else
			(strcmp(buf, "\n") == 0)?printf("%d:%s\n", yylineno, buf):printf("%d: %s\n", yylineno, buf);
		if(strcmp(error_type, "Redeclared variable") == 0)
		{
			printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno, buf);
			printf("| Redeclared variable %s", error_target);
			printf("\n|-----------------------------------------------|\n\n");
		}
		else if(strcmp(error_type, "Redeclared function") == 0)
		{
			printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno, buf);
			printf("| Redeclared function %s", error_target);
			printf("\n|-----------------------------------------------|\n\n");
		}
		else if(strcmp(error_type, "Undeclared variable") == 0)
		{
			printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno, buf);
			printf("| Undeclared variable %s", error_target);
			printf("\n|-----------------------------------------------|\n\n");
		}
		else if(strcmp(error_type, "Undeclared function") == 0)
		{
			printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno, buf);
			printf("| Undeclared function %s", error_target);
			printf("\n|-----------------------------------------------|\n\n");
		}
		else;
		error_type = strdup("");
		error_target = strdup("");
		memset(buf, '\0', sizeof(buf)); 
		if(dump_on == 0){dump_symbol(); curr_scope--; dump_on = -1;}
	}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 169 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	if(strcmp((yyvsp[-4].string), "int") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-3].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "int", curr_scope, temp);
    			if(isGlobal)
    			{
					gencode_function(".field public static ");
					gencode_function((yyvsp[-3].string)); 
					gencode_function(" I = ");
					gencode_function((yyvsp[-1].string));
					gencode_function("\n");
				}
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "int", curr_scope, temp);
    			if(isGlobal)
    			{
					gencode_function(".field public static ");
					gencode_function((yyvsp[-3].string)); 
					gencode_function(" I = ");
					gencode_function((yyvsp[-1].string));
					gencode_function("\n");
				}
    		}
    		else
    		{
    			// semantic error
    			hasError = 1;
				error_type = strdup("Redeclared variable");
				error_target = strdup((yyvsp[-3].string));
    		}
    	}
    	else if(strcmp((yyvsp[-4].string), "float") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-3].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "float", curr_scope, temp);
    			if(isGlobal)
    			{
					if(atof((yyvsp[-1].string)) == 0)
					{
						gencode_function(".field public static ");
						gencode_function((yyvsp[-3].string)); 
						gencode_function(" F\n");
					}
					else
					{
						gencode_function(".field public static ");
						gencode_function((yyvsp[-3].string)); 
						gencode_function(" F = ");
						gencode_function((yyvsp[-1].string));
						gencode_function("\n");
					}
				}
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "float", curr_scope, temp);
    			if(isGlobal)
    			{
					if(atof((yyvsp[-1].string)) == 0)
					{
						gencode_function(".field public static ");
						gencode_function((yyvsp[-3].string)); 
						gencode_function(" F\n");
					}
					else
					{
						gencode_function(".field public static ");
						gencode_function((yyvsp[-3].string)); 
						gencode_function(" F = ");
						gencode_function((yyvsp[-1].string));
						gencode_function("\n");
					}
				}
    		}
    		else
    		{
    			// semantic error
    			hasError = 1;
				error_type = strdup("Redeclared variable");
				error_target = strdup((yyvsp[-3].string));
    		}
    	}
    	else if(strcmp((yyvsp[-4].string), "bool") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-3].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "bool", curr_scope, temp);
    			if(isGlobal)
    			{
					gencode_function(".field public static ");
					gencode_function((yyvsp[-3].string)); 
					gencode_function(" Z = ");
					gencode_function((yyvsp[-1].string));
					gencode_function("\n");
				}
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "bool", curr_scope, temp);
    			if(isGlobal)
    			{
					gencode_function(".field public static ");
					gencode_function((yyvsp[-3].string)); 
					gencode_function(" Z = ");
					gencode_function((yyvsp[-1].string));
					gencode_function("\n");
				}
    		}
    		else
    		{
    			hasError = 1;
    			error_type = strdup("Redeclared variable");
				error_target = strdup((yyvsp[-3].string));
    		}
    	}
    	else if(strcmp((yyvsp[-4].string), "string") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-3].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "string", curr_scope, temp);
    			if(isGlobal)
    			{
					gencode_function(".field public static ");
					gencode_function((yyvsp[-3].string)); 
					gencode_function(" Ljava/lang/String; = \"");
					gencode_function((yyvsp[-1].string));
					gencode_function("\"\n");
				}
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "string", curr_scope, temp);
    			if(isGlobal)
    			{
					gencode_function(".field public static ");
					gencode_function((yyvsp[-3].string)); 
					gencode_function(" Ljava/lang/String; = \"");
					gencode_function((yyvsp[-1].string));
					gencode_function("\"\n");
				}
    		}
    		else
    		{
    			hasError = 1;
    			error_type = strdup("Redeclared variable");
				error_target = strdup((yyvsp[-3].string));
    		}
    	}
    	else
    	{
    		hasError = 1;
    		error_type = strdup("Redeclared variable");
			error_target = strdup((yyvsp[-3].string));
    	}
    }
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 337 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	if(strcmp((yyvsp[-2].string), "int") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-1].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "int", curr_scope, temp);
    			if(isGlobal)
    			{
					gencode_function(".field public static ");
					gencode_function((yyvsp[-1].string)); 
					gencode_function(" I = 0\n");
				}
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "int", curr_scope, temp);
    			if(isGlobal)
    			{
					gencode_function(".field public static ");
					gencode_function((yyvsp[-1].string)); 
					gencode_function(" I = 0\n");
				}
    		}
    		else
    		{
    			// semantic error
    			hasError = 1;
				error_type = strdup("Redeclared variable");
				error_target = strdup((yyvsp[-1].string));
    		}
    	}
    	else if(strcmp((yyvsp[-2].string), "float") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-1].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "float", curr_scope, temp);
    			if(isGlobal)
    			{
					gencode_function(".field public static ");
					gencode_function((yyvsp[-1].string)); 
					gencode_function(" F\n");
				}
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "float", curr_scope, temp);
    			if(isGlobal)
    			{
					gencode_function(".field public static ");
					gencode_function((yyvsp[-1].string)); 
					gencode_function(" F\n");
				}
    		}
    		else
    		{
    			// semantic error
    			hasError = 1;
				error_type = strdup("Redeclared variable");
				error_target = strdup((yyvsp[-1].string));
    		}
    	}
    	else if(strcmp((yyvsp[-2].string), "bool") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-1].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "bool", curr_scope, temp);
    			if(isGlobal)
    			{
					gencode_function(".field public static ");
					gencode_function((yyvsp[-1].string)); 
					gencode_function(" Z = 0\n");
				}
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "bool", curr_scope, temp);
    			if(isGlobal)
    			{
					gencode_function(".field public static ");
					gencode_function((yyvsp[-1].string)); 
					gencode_function(" Z = 0\n");
				}
    		}
    		else
    		{
    			// semantic error
    			hasError = 1;
				error_type = strdup("Redeclared variable");
				error_target = strdup((yyvsp[-1].string));
    		}
    	}
    	else if(strcmp((yyvsp[-2].string), "string") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-1].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "string", curr_scope, temp);
    			if(isGlobal)
    			{
					gencode_function(".field public static ");
					gencode_function((yyvsp[-1].string)); 
					gencode_function(" Ljava/lang/String; = \"\\0\"\n");
				}
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "string", curr_scope, temp);
    			if(isGlobal)
    			{
					gencode_function(".field public static ");
					gencode_function((yyvsp[-1].string)); 
					gencode_function(" Ljava/lang/String; = \"\\0\"\n");
				}
    		}
    		else
    		{
    			// semantic error
    			hasError = 1;
				error_type = strdup("Redeclared variable");
				error_target = strdup((yyvsp[-1].string));
    		}
    	}
    	else
    	{
    		// semantic error
    		hasError = 1;
    		error_type = strdup("Redeclared variable");
			error_target = strdup((yyvsp[-1].string));
    	}
    }
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 477 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	if(strcmp((yyvsp[-4].string), "int") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-3].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "int", curr_scope, temp);
    			// gencode -------------------------------------------
    			int var_index = deep_lookup_symbol((yyvsp[-3].string), curr_scope, (yyvsp[-4].string));
    			char s[16]; sprintf(s, "%d", var_index); 
    			gencode_function("\t");
    			gencode_function((yyvsp[-1].string));
    			if(NULL != strstr((yyvsp[-1].string), "."))
    			{
    				gencode_function("\tf2i\n");
    			}
    			gencode_function("\tistore ");
    			gencode_function(s);
    			gencode_function("\n");
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "int", curr_scope, temp);
    			// gencode -------------------------------------------
    			int var_index = deep_lookup_symbol((yyvsp[-3].string), curr_scope, (yyvsp[-4].string));
    			char s[16]; sprintf(s, "%d", var_index);
    			gencode_function("\t");
    			gencode_function((yyvsp[-1].string));
    			if(NULL != strstr((yyvsp[-1].string), "."))
    			{
    				gencode_function("\tf2i\n");
    			}
    			gencode_function("\tistore ");
    			gencode_function(s);
    			gencode_function("\n");
    		}
    		else
    		{
    			// semantic error
    			hasError = 1;
				error_type = strdup("Redeclared variable");
				error_target = strdup((yyvsp[-3].string));
    		}
    	}
    	else if(strcmp((yyvsp[-4].string), "float") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-3].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "float", curr_scope, temp);
    			// gencode -------------------------------------------
    			int var_index = deep_lookup_symbol((yyvsp[-3].string), curr_scope, (yyvsp[-4].string));
    			char s[16]; sprintf(s, "%d", var_index);
    			gencode_function("\t");
    			gencode_function((yyvsp[-1].string));
    			if(NULL == strstr((yyvsp[-1].string), "."))
    			{
    				gencode_function("\ti2f\n");
    			}
    			gencode_function("\tfstore ");
    			gencode_function(s);
    			gencode_function("\n");
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "float", curr_scope, temp);
    			// gencode -------------------------------------------
    			int var_index = deep_lookup_symbol((yyvsp[-3].string), curr_scope, (yyvsp[-4].string));
    			char s[16]; sprintf(s, "%d", var_index);
    			gencode_function("\t");
    			gencode_function((yyvsp[-1].string));
    			if(NULL == strstr((yyvsp[-1].string), "."))
    			{
    				gencode_function("\ti2f\n");
    			}
    			gencode_function("\tfstore ");
    			gencode_function(s);
    			gencode_function("\n");
    		}
    		else
    		{
    			// semantic error
    			hasError = 1;
				error_type = strdup("Redeclared variable");
				error_target = strdup((yyvsp[-3].string));
    		}
    	}
    	else if(strcmp((yyvsp[-4].string), "bool") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-3].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "bool", curr_scope, temp);
    			// gencode -------------------------------------------
    			int var_index = deep_lookup_symbol((yyvsp[-3].string), curr_scope, (yyvsp[-4].string));
    			char s[16]; sprintf(s, "%d", var_index);
    			gencode_function("\t");
    			gencode_function((yyvsp[-1].string));
    			gencode_function("\tistore ");
    			gencode_function(s);
    			gencode_function("\n");
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "bool", curr_scope, temp);
    			// gencode -------------------------------------------
    			int var_index = deep_lookup_symbol((yyvsp[-3].string), curr_scope, (yyvsp[-4].string));
    			char s[16]; sprintf(s, "%d", var_index);
    			gencode_function("\t");
    			gencode_function((yyvsp[-1].string));
    			gencode_function("\tistore ");
    			gencode_function(s);
    			gencode_function("\n");
    		}
    		else
    		{
    			hasError = 1;
    			error_type = strdup("Redeclared variable");
				error_target = strdup((yyvsp[-3].string));
    		}
    	}
    	else if(strcmp((yyvsp[-4].string), "string") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-3].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "string", curr_scope, temp);
    			// gencode -------------------------------------------
    			int var_index = deep_lookup_symbol((yyvsp[-3].string), curr_scope, (yyvsp[-4].string));
    			char s[16]; sprintf(s, "%d", var_index);
    			gencode_function("\t");
    			gencode_function((yyvsp[-1].string));
    			gencode_function("\tastore ");
    			gencode_function(s);
    			gencode_function("\n");
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "string", curr_scope, temp);
    			// gencode -------------------------------------------
    			int var_index = deep_lookup_symbol((yyvsp[-3].string), curr_scope, (yyvsp[-4].string));
    			char s[16]; sprintf(s, "%d", var_index);
    			gencode_function("\t");
    			gencode_function((yyvsp[-1].string));
    			gencode_function("\tastore ");
    			gencode_function(s);
    			gencode_function("\n");
    		}
    		else
    		{
    			hasError = 1;
    			error_type = strdup("Redeclared variable");
				error_target = strdup((yyvsp[-3].string));
    		}
    	}
    	else
    	{
    		hasError = 1;
    		error_type = strdup("Redeclared variable");
			error_target = strdup((yyvsp[-3].string));
    	}
    }
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 643 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	if(strcmp((yyvsp[-2].string), "int") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-1].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "int", curr_scope, temp);
    			// gencode -------------------------------------------
    			int var_index = deep_lookup_symbol((yyvsp[-1].string), curr_scope, (yyvsp[-2].string));
    			char s[16]; sprintf(s, "%d", var_index);
    			gencode_function("\tldc 0\n");
    			gencode_function("\tistore ");
    			gencode_function(s);
    			gencode_function("\n");
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "int", curr_scope, temp);
    			// gencode -------------------------------------------
    			int var_index = deep_lookup_symbol((yyvsp[-1].string), curr_scope, (yyvsp[-2].string));
    			char s[16]; sprintf(s, "%d", var_index);
    			gencode_function("\tldc 0\n");
    			gencode_function("\tistore ");
    			gencode_function(s);
    			gencode_function("\n");
    		}
    		else
    		{
    			// semantic error
    			hasError = 1;
				error_type = strdup("Redeclared variable");
				error_target = strdup((yyvsp[-1].string));
    		}
    	}
    	else if(strcmp((yyvsp[-2].string), "float") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-1].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "float", curr_scope, temp);
    			// gencode -------------------------------------------
    			int var_index = deep_lookup_symbol((yyvsp[-1].string), curr_scope, (yyvsp[-2].string));
    			char s[16]; sprintf(s, "%d", var_index);
    			gencode_function("\tldc 0.000000\n");
    			gencode_function("\tfstore ");
    			gencode_function(s);
    			gencode_function("\n");
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "float", curr_scope, temp);
    			// gencode -------------------------------------------
    			int var_index = deep_lookup_symbol((yyvsp[-1].string), curr_scope, (yyvsp[-2].string));
    			char s[16]; sprintf(s, "%d", var_index);
    			gencode_function("\tldc 0.000000\n");
    			gencode_function("\tfstore ");
    			gencode_function(s);
    			gencode_function("\n");
    		}
    		else
    		{
    			// semantic error
    			hasError = 1;
				error_type = strdup("Redeclared variable");
				error_target = strdup((yyvsp[-1].string));
    		}
    	}
    	else if(strcmp((yyvsp[-2].string), "bool") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-1].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "bool", curr_scope, temp);
    			// gencode -------------------------------------------
    			int var_index = deep_lookup_symbol((yyvsp[-1].string), curr_scope, (yyvsp[-2].string));
    			char s[16]; sprintf(s, "%d", var_index);
    			gencode_function("\tldc 0\n");
    			gencode_function("\tistore ");
    			gencode_function(s);
    			gencode_function("\n");
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "bool", curr_scope, temp);
    			// gencode -------------------------------------------
    			int var_index = deep_lookup_symbol((yyvsp[-1].string), curr_scope, (yyvsp[-2].string));
    			char s[16]; sprintf(s, "%d", var_index);
    			gencode_function("\tldc 0\n");
    			gencode_function("\tistore ");
    			gencode_function(s);
    			gencode_function("\n");
    		}
    		else
    		{
    			// semantic error
    			hasError = 1;
				error_type = strdup("Redeclared variable");
				error_target = strdup((yyvsp[-1].string));
    		}
    	}
    	else if(strcmp((yyvsp[-2].string), "string") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-1].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "string", curr_scope, temp);
    			// gencode -------------------------------------------
    			int var_index = deep_lookup_symbol((yyvsp[-1].string), curr_scope, (yyvsp[-2].string));
    			char s[16]; sprintf(s, "%d", var_index);
    			gencode_function("\tldc \"\\0\"\n");
    			gencode_function("\tastore ");
    			gencode_function(s);
    			gencode_function("\n");
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "string", curr_scope, temp);
    			// gencode -------------------------------------------
    			int var_index = deep_lookup_symbol((yyvsp[-1].string), curr_scope, (yyvsp[-2].string));
    			char s[16]; sprintf(s, "%d", var_index);
    			gencode_function("\tldc \"\\0\"\n");
    			gencode_function("\tastore ");
    			gencode_function(s);
    			gencode_function("\n");
    		}
    		else
    		{
    			// semantic error
    			hasError = 1;
				error_type = strdup("Redeclared variable");
				error_target = strdup((yyvsp[-1].string));
    		}
    	}
    	else
    	{
    		// semantic error
    		hasError = 1;
    		error_type = strdup("Redeclared variable");
			error_target = strdup((yyvsp[-1].string));
    	}
    }
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 791 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(strcmp((yyvsp[-3].string), "int") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
    		int targetIndex = lookup_symbol((yyvsp[-2].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-2].string), "function", "int", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-2].string), "function", "int", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
    			hasError = 1;
				error_type = strdup("Redeclared function");
				error_target = strdup((yyvsp[-2].string));
    		}
    	}
    	else if(strcmp((yyvsp[-3].string), "float") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
    		int targetIndex = lookup_symbol((yyvsp[-2].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-2].string), "function", "float", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-2].string), "function", "float", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
    			hasError = 1;
				error_type = strdup("Redeclared function");
				error_target = strdup((yyvsp[-2].string));
    		}
    	}
    	else if(strcmp((yyvsp[-3].string), "bool") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
    		int targetIndex = lookup_symbol((yyvsp[-2].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-2].string), "function", "bool", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-2].string), "function", "bool", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
    			hasError = 1;
				error_type = strdup("Redeclared function");
				error_target = strdup((yyvsp[-2].string));
    		}
    	}
    	else if(strcmp((yyvsp[-3].string), "string") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
    		int targetIndex = lookup_symbol((yyvsp[-2].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-2].string), "function", "string", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-2].string), "function", "string", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
    			hasError = 1;
				error_type = strdup("Redeclared function");
				error_target = strdup((yyvsp[-2].string));
    		}
    	}
    	else if(strcmp((yyvsp[-3].string), "void") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
    		int targetIndex = lookup_symbol((yyvsp[-2].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-2].string), "function", "void", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-2].string), "function", "void", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
    			hasError = 1;
				error_type = strdup("Redeclared function");
				error_target = strdup((yyvsp[-2].string));
    		}
    	}
    	else
    	{
    		
    	}
	}
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 910 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
		int targetIndex = lookup_symbol((yyvsp[0].string));
		if(targetIndex == -1)
		{
			insert_symbol((yyvsp[0].string), "parameter", (yyvsp[-1].string), curr_scope+1, temp);
		}
		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope+1)
		{
			insert_symbol((yyvsp[0].string), "parameter", (yyvsp[-1].string), curr_scope+1, temp);
		}
		else
		{
			// semantic error
			hasError = 1;
			error_type = strdup("Redeclared variable");
			error_target = strdup((yyvsp[0].string));
		}
	/*
		strcat(curr_formal_para[curr_formal_para_index], $1); 
		strcat(curr_formal_para[curr_formal_para_index], " "); 
		strcat(curr_formal_para[curr_formal_para_index], $2); 
		if(curr_formal_para_index <= 14) curr_formal_para_index++; 
	*/
	}
#line 2335 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 939 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 2341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 940 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 2347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 941 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 2353 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 942 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 2359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 943 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 2365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 947 "compiler_hw3.y" /* yacc.c:1646  */
    { char s[16]; sprintf(s, "%d", (yyvsp[0].i_val)); (yyval.string) = strdup(s); }
#line 2371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 948 "compiler_hw3.y" /* yacc.c:1646  */
    { char s[16]; sprintf(s, "%f", (yyvsp[0].f_val)); (yyval.string) = strdup(s); }
#line 2377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 949 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = strdup((yyvsp[0].string)); }
#line 2383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 950 "compiler_hw3.y" /* yacc.c:1646  */
    { char s[16]; sprintf(s, "%d", (yyvsp[0].bool_val)); (yyval.string) = strdup(s); }
#line 2389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 951 "compiler_hw3.y" /* yacc.c:1646  */
    { char s[16]; sprintf(s, "%d", (yyvsp[0].bool_val)); (yyval.string) = strdup(s); }
#line 2395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 955 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = strdup((yyvsp[0].string)); }
#line 2401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 956 "compiler_hw3.y" /* yacc.c:1646  */
    { char *s = strdup("ldc \"");
				  strcat(s, strdup((yyvsp[0].string)));
				  strcat(s, strdup("\"\n"));
				  (yyval.string) = strdup(s);}
#line 2410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 963 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = strdup((yyvsp[0].string)); }
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 964 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = strdup((yyvsp[0].string)); }
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 968 "compiler_hw3.y" /* yacc.c:1646  */
    { char s[16]; sprintf(s, "%d", (yyvsp[0].i_val)); 
			    char *s2 = strdup("ldc ");
				strcat(s2, strdup(s));
				strcat(s2, strdup("\n"));
				(yyval.string) = strdup(s2); }
#line 2432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 973 "compiler_hw3.y" /* yacc.c:1646  */
    { char s[16]; sprintf(s, "%f", (yyvsp[0].f_val)); 
				char *s2 = strdup("ldc ");
				strcat(s2, strdup(s));
				strcat(s2, strdup("\n"));
				(yyval.string) = strdup(s2); }
#line 2442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 978 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = strdup("brabrabra\n"); }
#line 2448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 979 "compiler_hw3.y" /* yacc.c:1646  */
    { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol((yyvsp[0].string));
			if(targetIndex == -1)
			{
				// semantic error
				hasError = 1;
				error_type = strdup("Undeclared variable");
				error_target = strdup((yyvsp[0].string));
				(yyval.string) = strdup("\n");
			}
			else
			{
				(yyval.string) = strdup(takeID((yyvsp[0].string)));
			} 
		}
#line 2469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 995 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = strdup("brabrabra\n"); }
#line 2475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 999 "compiler_hw3.y" /* yacc.c:1646  */
    { char s[16]; sprintf(s, "%d", (yyvsp[0].bool_val)); 
			    	char *s2 = strdup("ldc ");
					strcat(s2, strdup(s));
					strcat(s2, strdup("\n"));
					(yyval.string) = strdup(s2); }
#line 2485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 1004 "compiler_hw3.y" /* yacc.c:1646  */
    { char s[16]; sprintf(s, "%d", (yyvsp[0].bool_val)); 
			    	 char *s2 = strdup("ldc ");
					 strcat(s2, strdup(s));
					 strcat(s2, strdup("\n"));
					 (yyval.string) = strdup(s2); }
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1009 "compiler_hw3.y" /* yacc.c:1646  */
    { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol((yyvsp[0].string));
			if(targetIndex == -1)
			{
				// semantic error
				hasError = 1;
				error_type = strdup("Undeclared variable");
				error_target = strdup((yyvsp[0].string));
				(yyval.string) = strdup("\n");
			}
			else
			{
				(yyval.string) = strdup(takeID((yyvsp[0].string)));
			} 
		}
#line 2516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1025 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = strdup("brabrabra\n"); }
#line 2522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1029 "compiler_hw3.y" /* yacc.c:1646  */
    {
		printf("+\n");
	}
#line 2530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1032 "compiler_hw3.y" /* yacc.c:1646  */
    {
		printf("-\n");
	}
#line 2538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1035 "compiler_hw3.y" /* yacc.c:1646  */
    {
		printf("*\n");
	}
#line 2546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1038 "compiler_hw3.y" /* yacc.c:1646  */
    {
		printf("/\n");
	}
#line 2554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1041 "compiler_hw3.y" /* yacc.c:1646  */
    {
		printf("%%\n");
	}
#line 2562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1044 "compiler_hw3.y" /* yacc.c:1646  */
    {
		printf(">\n");
	}
#line 2570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1047 "compiler_hw3.y" /* yacc.c:1646  */
    {
		printf("<\n");
	}
#line 2578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1050 "compiler_hw3.y" /* yacc.c:1646  */
    {
		printf(">=\n");
	}
#line 2586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1053 "compiler_hw3.y" /* yacc.c:1646  */
    {
		printf("<=\n");
	}
#line 2594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1056 "compiler_hw3.y" /* yacc.c:1646  */
    {
		printf("==\n");
	}
#line 2602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1059 "compiler_hw3.y" /* yacc.c:1646  */
    {
		printf("!=\n");
	}
#line 2610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1062 "compiler_hw3.y" /* yacc.c:1646  */
    {
		printf("&&\n");
	}
#line 2618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1065 "compiler_hw3.y" /* yacc.c:1646  */
    {
		printf("||\n");
	}
#line 2626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1068 "compiler_hw3.y" /* yacc.c:1646  */
    {
		
	}
#line 2634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1071 "compiler_hw3.y" /* yacc.c:1646  */
    {
		
	}
#line 2642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1076 "compiler_hw3.y" /* yacc.c:1646  */
    { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol((yyvsp[-1].string));
			if(targetIndex == -1)
			{
				// semantic error
				hasError = 1;
				error_type = strdup("Undeclared variable");
				error_target = strdup((yyvsp[-1].string));
			}
			else
			{
				
			} 
		}
#line 2662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1091 "compiler_hw3.y" /* yacc.c:1646  */
    { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol((yyvsp[-1].string));
			if(targetIndex == -1)
			{
				// semantic error
				hasError = 1;
				error_type = strdup("Undeclared variable");
				error_target = strdup((yyvsp[-1].string));
			}
			else
			{
				
			} 
		}
#line 2682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1109 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		fprintf(file, ".end method\n");
		isGlobal = 1;
	}
#line 2691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1116 "compiler_hw3.y" /* yacc.c:1646  */
    {
		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "def"};
		for(int i=0; i<30; i++)
		{
			if(strcmp(symbol_table[i].entry_type, "parameter") == 0)
			{
				strcpy(temp[i], symbol_table[i].data_type);
			}
		}
		int targetIndex = lookup_symbol((yyvsp[-1].string));
		if(targetIndex == -1)
		{
			insert_symbol((yyvsp[-1].string), "function", (yyvsp[-2].string), curr_scope, temp);
			gencode_function(".method public static ");
			gencode_function((yyvsp[-1].string));
			gencode_function("([Ljava/lang/String;)V\n");
    		gencode_function(".limit stack 50\n");
    		gencode_function(".limit locals 50\n");
    		isGlobal = 0;
		}
		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
		{
			insert_symbol((yyvsp[-1].string), "function", (yyvsp[-2].string), curr_scope, temp);
			gencode_function(".method public static ");
			gencode_function((yyvsp[-1].string));
			gencode_function("([Ljava/lang/String;)V\n");
    		gencode_function(".limit stack 50\n");
    		gencode_function(".limit locals 50\n");
    		isGlobal = 0;
		}
		else if(targetIndex != -1 && strcmp(symbol_table[targetIndex].formal_para[15], "decl") == 0)
		{
			insert_symbol((yyvsp[-1].string), "function", (yyvsp[-2].string), curr_scope, temp);
			gencode_function(".method public static ");
			gencode_function((yyvsp[-1].string));
			gencode_function("([Ljava/lang/String;)V\n");
    		gencode_function(".limit stack 50\n");
    		gencode_function(".limit locals 50\n");
    		isGlobal = 0;
		}
		else
		{
			// semantic error
			hasError = 1;
			error_type = strdup("Redeclared function");
			error_target = strdup((yyvsp[-1].string));
		}
	}
#line 2744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1172 "compiler_hw3.y" /* yacc.c:1646  */
    { dump_on = 0; }
#line 2750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1194 "compiler_hw3.y" /* yacc.c:1646  */
    { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol((yyvsp[-2].string));
			if(targetIndex == -1)
			{
				// semantic error
				hasError = 1;
				error_type = strdup("Undeclared variable");
				error_target = strdup((yyvsp[-2].string));
			}
			else
			{
				
			} 
		}
#line 2770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1209 "compiler_hw3.y" /* yacc.c:1646  */
    { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol((yyvsp[-2].string));
			if(targetIndex == -1)
			{
				// semantic error
				hasError = 1;
				error_type = strdup("Undeclared variable");
				error_target = strdup((yyvsp[-2].string));
			}
			else
			{
				
			} 
		}
#line 2790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1224 "compiler_hw3.y" /* yacc.c:1646  */
    { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol((yyvsp[-2].string));
			if(targetIndex == -1)
			{
				// semantic error
				hasError = 1;
				error_type = strdup("Undeclared variable");
				error_target = strdup((yyvsp[-2].string));
			}
			else
			{
				
			} 
		}
#line 2810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1239 "compiler_hw3.y" /* yacc.c:1646  */
    { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol((yyvsp[-2].string));
			if(targetIndex == -1)
			{
				// semantic error
				hasError = 1;
				error_type = strdup("Undeclared variable");
				error_target = strdup((yyvsp[-2].string));
			}
			else
			{
				
			} 
		}
#line 2830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1254 "compiler_hw3.y" /* yacc.c:1646  */
    { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol((yyvsp[-2].string));
			if(targetIndex == -1)
			{
				// semantic error
				hasError = 1;
				error_type = strdup("Undeclared variable");
				error_target = strdup((yyvsp[-2].string));
			}
			else
			{
				
			} 
		}
#line 2850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1269 "compiler_hw3.y" /* yacc.c:1646  */
    { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol((yyvsp[-2].string));
			if(targetIndex == -1)
			{
				// semantic error
				hasError = 1;
				error_type = strdup("Undeclared variable");
				error_target = strdup((yyvsp[-2].string));
			}
			else
			{
				
			} 
		}
#line 2870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1284 "compiler_hw3.y" /* yacc.c:1646  */
    { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol((yyvsp[-1].string));
			if(targetIndex == -1)
			{
				// semantic error
				hasError = 1;
				error_type = strdup("Undeclared variable");
				error_target = strdup((yyvsp[-1].string));
			}
			else
			{
				
			} 
		}
#line 2890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1299 "compiler_hw3.y" /* yacc.c:1646  */
    { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol((yyvsp[-1].string));
			if(targetIndex == -1)
			{
				// semantic error
				hasError = 1;
				error_type = strdup("Undeclared variable");
				error_target = strdup((yyvsp[-1].string));
			}
			else
			{
				
			} 
		}
#line 2910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1317 "compiler_hw3.y" /* yacc.c:1646  */
    {
		gencode_function("\t");
		gencode_function((yyvsp[-1].string));
		gencode_function("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
		gencode_function("\tswap\n");
		if((yyvsp[-1].string)[0] == 'i' || (yyvsp[-1].string)[strlen((yyvsp[-1].string))-2] == 'I')
		{
			gencode_function("\tinvokevirtual java/io/PrintStream/println(I)V\n");
		}
		else if((yyvsp[-1].string)[0] == 'f' || (yyvsp[-1].string)[strlen((yyvsp[-1].string))-2] == 'F')
		{
			gencode_function("\tinvokevirtual java/io/PrintStream/println(F)V\n");
		}
		else if((yyvsp[-1].string)[0] == 'a' || (yyvsp[-1].string)[strlen((yyvsp[-1].string))-2] == ';')
		{
			gencode_function("\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
		}
		else
		{
			if(NULL != strstr((yyvsp[-1].string), "\""))
				gencode_function("\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
			else if(NULL != strstr((yyvsp[-1].string), "."))
				gencode_function("\tinvokevirtual java/io/PrintStream/println(F)V\n");
			else
				gencode_function("\tinvokevirtual java/io/PrintStream/println(I)V\n");
		}
	}
#line 2942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1347 "compiler_hw3.y" /* yacc.c:1646  */
    { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol((yyvsp[0].string));
			if(targetIndex == -1)
			{
				// semantic error
				hasError = 1;
				error_type = strdup("Undeclared variable");
				error_target = strdup((yyvsp[0].string));
				(yyval.string) = strdup("\n");
			}
			else
			{
				(yyval.string) = strdup(takeID((yyvsp[0].string)));
			} 
		}
#line 2963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1363 "compiler_hw3.y" /* yacc.c:1646  */
    { char *s2 = strdup("ldc \"");
				  strcat(s2, strdup((yyvsp[0].string)));
				  strcat(s2, strdup("\"\n"));
				  (yyval.string) = strdup(s2); }
#line 2972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1367 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = strdup((yyvsp[0].string)); }
#line 2978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1371 "compiler_hw3.y" /* yacc.c:1646  */
    { 
			char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
			int targetIndex = lookup_symbol((yyvsp[-1].string));
			if(targetIndex == -1)
			{
				// semantic error
				hasError = 1;
				error_type = strdup("Undeclared function");
				error_target = strdup((yyvsp[-1].string));
				(yyval.string) = "\n";
			}
			else
			{
				(yyval.string) = strdup("brabrabra\n");
			} 
		}
#line 2999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1415 "compiler_hw3.y" /* yacc.c:1646  */
    { gencode_function("\treturn\n"); }
#line 3005 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3009 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1418 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;
    create_symbol();
    curr_scope = 0;
    int result = 0;
    error_type = strdup("");
    error_target = strdup("");

    file = fopen("compiler_hw3.j","w");

    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n");

    result = yyparse();
	if(result == 0) 
	{
		dump_symbol();
		printf("\nTotal lines: %d \n",yylineno);
	}
	
	if(symbol_table != NULL)
	{
		free(symbol_table);
	}

    fclose(file);
    
    if(hasError)
	{
		remove("compiler_hw3.j");
	}

    return 0;
}

void yyerror(char *s)
{
	hasError = 1;
	if(strcmp(s, "syntax error") == 0)
	{
		(strcmp(buf, "\n") == 0)?printf("%d:%s\n", yylineno + 1, buf):printf("%d: %s\n", yylineno + 1, buf); 
		if(strcmp(error_type, "Redeclared variable") == 0)
		{
			printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno+1, buf);
			printf("| Redeclared variable %s", error_target);
			printf("\n|-----------------------------------------------|\n\n");
		}
		else if(strcmp(error_type, "Redeclared function") == 0)
		{
			printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno+1, buf);
			printf("| Redeclared function %s", error_target);
			printf("\n|-----------------------------------------------|\n\n");
		}
		else if(strcmp(error_type, "Undeclared variable") == 0)
		{
			printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno+1, buf);
			printf("| Undeclared variable %s", error_target);
			printf("\n|-----------------------------------------------|\n\n");
		}
		else if(strcmp(error_type, "Undeclared function") == 0)
		{
			printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno+1, buf);
			printf("| Undeclared function %s", error_target);
			printf("\n|-----------------------------------------------|\n\n");
		}
		else;
		error_type = strdup("");
		error_target = strdup("");
		
		error_type = strdup("syntax error");
		printf("\n|-----------------------------------------------|\n");
    	printf("| Error found in line %d: %s\n", yylineno + 1, buf);
    	printf("| %s", s);
    	printf("\n|-----------------------------------------------|\n\n");
    	memset(buf, '\0', sizeof(buf)); 
	}
    /*printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");*/
}

/* stmbol table functions */
void create_symbol() {
	symbol_table = (symbol_table_entry *)malloc(sizeof(symbol_table_entry) * 30);
	for(int i=0; i<30; i++)
	{
		strcpy(symbol_table[i].name, "\0");
		strcpy(symbol_table[i].entry_type, "\0");
		strcpy(symbol_table[i].data_type, "\0");
		symbol_table[i].scope_level = -1;
		for(int j=0; j<16; j++)
			strcpy(symbol_table[i].formal_para[i], "\0");
	}
}
void insert_symbol(char name[32], char entry_type[32], char data_type[16], int scope_level, char formal_para[16][16]) {
	if(lookup_symbol(name) != -1 && scope_level == symbol_table[lookup_symbol(name)].scope_level)
	{
		//semantic error.
	}
	else
	{
		strcpy(symbol_table[table_pointer].name, name);
		strcpy(symbol_table[table_pointer].entry_type, entry_type);
		strcpy(symbol_table[table_pointer].data_type, data_type);
		symbol_table[table_pointer].scope_level = scope_level;
		for(int i=0; i<16; i++)
			strcpy(symbol_table[table_pointer].formal_para[i], formal_para[i]);
		
		if(table_pointer != 29) table_pointer++;
	}
}
int lookup_symbol(char name[32]) {
	for(int i=0; i<30; i++)
	{
		if(strcmp(symbol_table[i].name, name) == 0)
		{
			return i;  //used
		}
	}
	return -1;
}

int notype_lookup_symbol(char name[32], int scope_level)
{
	int result = -1;
	for(int i=0; i<30; i++)
	{
		if((symbol_table[i].scope_level <= scope_level && symbol_table[i].scope_level != 0) && (strcmp(symbol_table[i].entry_type, "variable") == 0 || strcmp(symbol_table[i].entry_type, "parameter") == 0))
		{
			result++;
		}
		if(strcmp(symbol_table[i].name, name) == 0 && symbol_table[i].scope_level == scope_level)
		{
			return result;  //used
		}
	}
	return -1;
}

int deep_lookup_symbol(char name[32], int scope_level, char data_type[16]) {
	int result = -1;
	for(int i=0; i<30; i++)
	{
		if(symbol_table[i].scope_level == scope_level && (strcmp(symbol_table[i].entry_type, "variable") == 0 || strcmp(symbol_table[i].entry_type, "parameter") == 0))
		{
			result++;
		}
		if(strcmp(symbol_table[i].name, name) == 0 && symbol_table[i].scope_level == scope_level && strcmp(symbol_table[i].data_type, data_type) == 0)
		{
			return result;  //used
		}
	}
	return -1;
}
void dump_symbol() {
	int myFlag = 0;
	for(int i=0; i<30; i++)
	{
		if(symbol_table[i].scope_level == curr_scope && strcmp(symbol_table[i].name, "\0") != 0)
		{
			myFlag = 1;
		}
	}
	if(myFlag)
	{
		printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
	}
    int dump_index = 0;
    int isPrinted = -1;
           
    for(int i=0; i<30; i++)
    {
    	char *attribute;
    	attribute = strdup("\0");
    	char index_str[10] = "\0";
    	char scope_str[10] = "\0";
    	
    	if(symbol_table[i].scope_level == curr_scope && strcmp(symbol_table[i].name, "\0") != 0)
    	{
    		for(int j=0; j<15; j++)
    		{
    			strcat(attribute, symbol_table[i].formal_para[j]);
    			if(strcmp(attribute, "\0") != 0 && j != 14 && strcmp(symbol_table[i].formal_para[j+1], "\0") != 0 && strcmp(symbol_table[i].formal_para[j+1], "decl") != 0) strcat(attribute, ", ");
    		}
    		sprintf(index_str, "%d", dump_index);
    		sprintf(scope_str, "%d", symbol_table[i].scope_level);
    		isPrinted = 0;
    		if(strcmp(attribute, "\0") != 0)
    		{
    			printf("%-10s%-10s%-12s%-10s%-10s",
           index_str, symbol_table[i].name, symbol_table[i].entry_type, symbol_table[i].data_type, scope_str);
           		for(int k=0; k<10; k++)
           		{
           			(attribute[k] == '\0')?:printf("%c", attribute[k]);
				}
				printf("\n");
           }
           else
           {
           		printf("%-10s%-10s%-12s%-10s%-10s\n",
           index_str, symbol_table[i].name, symbol_table[i].entry_type, symbol_table[i].data_type, scope_str);
           }
           
           strcpy(symbol_table[i].name, "\0");
		   strcpy(symbol_table[i].entry_type, "\0");
		   strcpy(symbol_table[i].data_type, "\0");
		   symbol_table[i].scope_level = -1;
		   for(int j=0; j<16; j++)
			   strcpy(symbol_table[i].formal_para[i], "\0");
           
           dump_index++;
    	}
    }
    if(isPrinted == 0)
    {
    	printf("\n");
    }
}

char *takeID(char name[32])
{
	char thisCode[256] = "\0";
	int idIndex = notype_lookup_symbol(name, curr_scope);
	if(strcmp(symbol_table[lookup_symbol(name)].data_type, "int") == 0)
	{
		if(symbol_table[lookup_symbol(name)].scope_level == 0)
		{
			strcat(thisCode, "getstatic compiler_hw3/");
			strcat(thisCode, name);
			strcat(thisCode, " I\n");
		}
		else
		{
			strcat(thisCode, "iload ");
			char s[16]; sprintf(s, "%d", idIndex);
			strcat(thisCode, s);
			strcat(thisCode, "\n");
		}
	}
	else if(strcmp(symbol_table[lookup_symbol(name)].data_type, "float") == 0)
	{
		if(symbol_table[lookup_symbol(name)].scope_level == 0)
		{
			strcat(thisCode, "getstatic compiler_hw3/");
			strcat(thisCode, name);
			strcat(thisCode, " F\n");
		}
		else
		{
			strcat(thisCode, "fload ");
			char s[16]; sprintf(s, "%d", idIndex);
			strcat(thisCode, s);
			strcat(thisCode, "\n");
		}
	}
	else if(strcmp(symbol_table[lookup_symbol(name)].data_type, "bool") == 0)
	{
		if(symbol_table[lookup_symbol(name)].scope_level == 0)
		{
			strcat(thisCode, "getstatic compiler_hw3/");
			strcat(thisCode, name);
			strcat(thisCode, " Z\n");
		}
		else
		{
			strcat(thisCode, "iload ");
			char s[16]; sprintf(s, "%d", idIndex);
			strcat(thisCode, s);
			strcat(thisCode, "\n");
		}
	}
	else if(strcmp(symbol_table[lookup_symbol(name)].data_type, "string") == 0)
	{
		if(symbol_table[lookup_symbol(name)].scope_level == 0)
		{
			strcat(thisCode, "getstatic compiler_hw3/");
			strcat(thisCode, name);
			strcat(thisCode, " Ljava/lang/String;\n");
		}
		else
		{
			strcat(thisCode, "aload ");
			char s[16]; sprintf(s, "%d", idIndex);
			strcat(thisCode, s);
			strcat(thisCode, "\n");
		}
	}
	return strdup(thisCode);
}

/* code generation functions */
void gencode_function(char *cmd) 
{
	fprintf(file, "%s", cmd);
}
