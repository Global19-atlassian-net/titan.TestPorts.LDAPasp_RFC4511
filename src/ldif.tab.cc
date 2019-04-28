/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse ldif_parse
#define yylex   ldif_lex
#define yyerror ldif_error
#define yylval  ldif_lval
#define yychar  ldif_char
#define yydebug ldif_debug
#define yynerrs ldif_nerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SEP = 258,
     DN = 259,
     COLON = 260,
     SAFE_STRING = 261,
     SAFE_BASE64_STRING = 262,
     GREATER = 263,
     SEMICOLON = 264,
     HYPHEN = 265,
     FLOAT_VAL = 266,
     INTEGER_VAL = 267,
     BISON_CONTROL = 268,
     BISON_TRUE = 269,
     BISON_FALSE = 270,
     CHANGETYPE = 271,
     ADD = 272,
     DELETE = 273,
     MODRDN = 274,
     MODDN = 275,
     NEWRDN = 276,
     DELETEOLDRDN = 277,
     ADD_COLON = 278,
     DELETE_COLON = 279,
     NEWSUPERIOR = 280,
     MODIFY = 281,
     REPLACE = 282,
     URL_STRING = 283,
     ZERO = 284,
     ONE = 285,
     LDAP_OID = 286,
     CHAR_ATTRIBUTE_TYPE = 287
   };
#endif
/* Tokens.  */
#define SEP 258
#define DN 259
#define COLON 260
#define SAFE_STRING 261
#define SAFE_BASE64_STRING 262
#define GREATER 263
#define SEMICOLON 264
#define HYPHEN 265
#define FLOAT_VAL 266
#define INTEGER_VAL 267
#define BISON_CONTROL 268
#define BISON_TRUE 269
#define BISON_FALSE 270
#define CHANGETYPE 271
#define ADD 272
#define DELETE 273
#define MODRDN 274
#define MODDN 275
#define NEWRDN 276
#define DELETEOLDRDN 277
#define ADD_COLON 278
#define DELETE_COLON 279
#define NEWSUPERIOR 280
#define MODIFY 281
#define REPLACE 282
#define URL_STRING 283
#define ZERO 284
#define ONE 285
#define LDAP_OID 286
#define CHAR_ATTRIBUTE_TYPE 287




/* Copy the first part of user declarations.  */
#line 1 "ldif.y"

/******************************************************************************
* Copyright (c) 2000-2019 Ericsson Telecom AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v2.0
* which accompanies this distribution, and is available at
* https://www.eclipse.org/org/documents/epl-2.0/EPL-2.0.html
*
* Contributors:
* Gergely Futo
* Attila Balasko
* Csaba Feher
* Csaba Fehér
* Gabor Szalai
* Janos Kovesdi
* Szabolcs Balazs Beres
* Szabolcs Béres
* Zoltan Medve
******************************************************************************/
//
//  File:               ldif.y
//  Description:        LDIF definition file
//  Rev:                R4A
//  Prodnr:             CNL 113 513
//
#include <stdio.h>
#include <string.h>
#include "LDIF_RFC4511.hh"
#include "memory.h"

using namespace LDIF__RFC4511;

extern int ldif_lex();
extern void ldif_error(const char *s);
extern void ldif_restart(FILE* input_file);

int line_number = 0;
boolean error_recovery = false;
LDIFData temporal_data;
AttrValRecord temporal_AttrValRecord;
LDIFControl temporal_Control;
ChangeModifyData temporal_changemodifydata;
int AttrValRecord_Counter = 0;
int option_counter = 0;
int data_counter = 0;
int control_counter = 0;
int modification_counter = 0;
boolean erroneous;
boolean inner_resolve_env;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 28 "ldif.y"
{
	CHARSTRING *string_val;
}
/* Line 187 of yacc.c.  */
#line 200 "ldif.tab.cc"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 213 "ldif.tab.cc"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   252

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNRULES -- Number of states.  */
#define YYNSTATES  199

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    12,    15,    17,    21,    24,
      26,    29,    31,    35,    38,    40,    45,    48,    49,    54,
      59,    65,    68,    71,    75,    78,    82,    88,    94,   100,
     102,   104,   105,   108,   109,   111,   113,   115,   120,   124,
     129,   133,   138,   143,   145,   148,   151,   154,   156,   159,
     161,   163,   166,   169,   173,   177,   180,   183,   185,   187,
     189,   191,   195,   199,   202,   204,   207,   216,   225,   234,
     243,   252,   254,   256,   258,   261,   265,   268,   272,   275,
     279,   281,   283,   285,   289,   293,   298,   299,   303,   308,
     312,   317,   321,   324,   328,   336,   343,   349,   356,   363,
     365,   367,   369,   371,   373,   376,   379
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    41,    35,    -1,    35,    -1,    37,    36,
      35,    -1,    37,    35,    -1,    37,    -1,    39,    36,    35,
      -1,    39,    35,    -1,    39,    -1,     3,    36,    -1,     3,
      -1,    42,     3,    38,    -1,    38,    47,    -1,    47,    -1,
      42,     3,    40,    52,    -1,    40,    43,    -1,    -1,    32,
       5,     6,    36,    -1,    32,     5,     1,    36,    -1,    32,
       5,     6,     1,     3,    -1,     1,     3,    -1,     4,     6,
      -1,     4,     5,     7,    -1,     4,     1,    -1,     4,     5,
       1,    -1,    13,    46,    44,    45,     3,    -1,    13,     1,
      44,    45,     3,    -1,    13,    46,    44,    45,     1,    -1,
      14,    -1,    15,    -1,    -1,     5,    48,    -1,    -1,    11,
      -1,    12,    -1,    31,    -1,    49,     5,    48,     3,    -1,
      49,     5,     3,    -1,     1,     5,    48,     3,    -1,     1,
       5,     3,    -1,    49,     1,    48,     3,    -1,    49,     5,
       1,     3,    -1,     6,    -1,     5,     7,    -1,     8,    28,
      -1,    50,    51,    -1,    50,    -1,     1,    51,    -1,    46,
      -1,    32,    -1,     9,    32,    -1,     9,    12,    -1,    51,
       9,    12,    -1,    51,     9,    32,    -1,     9,     1,    -1,
      16,    53,    -1,    54,    -1,    56,    -1,    62,    -1,    57,
      -1,    17,     3,    55,    -1,    17,     3,     1,    -1,    55,
      47,    -1,    47,    -1,    18,     3,    -1,    58,     3,    59,
       3,    22,    60,     3,    61,    -1,    58,     1,    59,     3,
      22,    60,     3,    61,    -1,    58,     3,    59,     1,    22,
      60,     3,    61,    -1,    58,     3,    59,     3,     1,    60,
       3,    61,    -1,    58,     3,    59,     3,    22,    60,     1,
      61,    -1,    19,    -1,    20,    -1,     1,    -1,    21,     6,
      -1,    21,     5,     7,    -1,     1,     6,    -1,     1,     5,
       6,    -1,    21,     1,    -1,    21,     5,     1,    -1,    29,
      -1,    30,    -1,     1,    -1,    25,     6,     3,    -1,    25,
      32,     3,    -1,    25,     5,     7,     3,    -1,    -1,    25,
       1,     3,    -1,    25,     5,     1,     3,    -1,     1,     6,
       3,    -1,     1,     5,     7,     3,    -1,    26,     3,    63,
      -1,    26,     3,    -1,    26,     1,    63,    -1,    63,    65,
      64,     3,    66,    10,     3,    -1,    65,    64,     3,    66,
      10,     3,    -1,     1,     3,    66,    10,     3,    -1,    65,
      64,     1,    66,    10,     3,    -1,    65,    64,     3,    66,
       1,     3,    -1,    49,    -1,     1,    -1,    23,    -1,    24,
      -1,    27,    -1,     1,     5,    -1,    66,    47,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    45,    45,    46,    53,    54,    55,    56,    57,    58,
      62,    63,    67,    71,    76,    84,    88,    94,   101,   115,
     122,   130,   139,   220,   230,   242,   257,   262,   272,   285,
     289,   294,   300,   317,   323,   327,   331,   338,   339,   344,
     356,   368,   374,   385,   461,   467,   475,   480,   485,   498,
     504,   513,   518,   523,   528,   533,   546,   554,   555,   556,
     557,   561,   562,   577,   583,   593,   601,   604,   614,   624,
     637,   652,   657,   662,   677,   684,   691,   701,   711,   722,
     736,   741,   746,   760,   767,   774,   782,   787,   799,   811,
     824,   840,   841,   846,   857,   863,   869,   875,   884,   899,
     906,   922,   927,   932,   937,   953,   958
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEP", "DN", "COLON", "SAFE_STRING",
  "SAFE_BASE64_STRING", "GREATER", "SEMICOLON", "HYPHEN", "FLOAT_VAL",
  "INTEGER_VAL", "BISON_CONTROL", "BISON_TRUE", "BISON_FALSE",
  "CHANGETYPE", "ADD", "DELETE", "MODRDN", "MODDN", "NEWRDN",
  "DELETEOLDRDN", "ADD_COLON", "DELETE_COLON", "NEWSUPERIOR", "MODIFY",
  "REPLACE", "URL_STRING", "ZERO", "ONE", "LDAP_OID",
  "CHAR_ATTRIBUTE_TYPE", "$accept", "ldif_file", "ldif_end",
  "optional_separators", "ldif_attrval_record", "attrval_specs",
  "ldif_change_record", "controls", "version_spec", "dn_spec", "control",
  "control_mid", "control_end", "ldap_oid", "attrval_spec", "value_spec",
  "AttributeDescription", "AttributeType", "options", "changerecord",
  "changerecord_end", "change_add", "change_add_end", "change_delete",
  "change_moddn", "change_moddn_start", "change_moddn_middle",
  "zero_or_one", "change_moddn_end", "change_modify", "mod_spec",
  "mod_spec_middle", "mod_spec_start", "optional_attrval_spec", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    34,    35,    35,    35,    35,    35,    35,
      36,    36,    37,    38,    38,    39,    40,    40,    41,    41,
      41,    41,    42,    42,    42,    42,    43,    43,    43,    44,
      44,    44,    45,    45,    46,    46,    46,    47,    47,    47,
      47,    47,    47,    48,    48,    48,    49,    49,    49,    50,
      50,    51,    51,    51,    51,    51,    52,    53,    53,    53,
      53,    54,    54,    55,    55,    56,    57,    57,    57,    57,
      57,    58,    58,    58,    59,    59,    59,    59,    59,    59,
      60,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      61,    62,    62,    62,    63,    63,    63,    63,    63,    64,
      64,    65,    65,    65,    65,    66,    66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     3,     2,     1,     3,     2,     1,
       2,     1,     3,     2,     1,     4,     2,     0,     4,     4,
       5,     2,     2,     3,     2,     3,     5,     5,     5,     1,
       1,     0,     2,     0,     1,     1,     1,     4,     3,     4,
       3,     4,     4,     1,     2,     2,     2,     1,     2,     1,
       1,     2,     2,     3,     3,     2,     2,     1,     1,     1,
       1,     3,     3,     2,     1,     2,     8,     8,     8,     8,
       8,     1,     1,     1,     2,     3,     2,     3,     2,     3,
       1,     1,     1,     3,     3,     4,     0,     3,     4,     3,
       4,     3,     2,     3,     7,     6,     5,     6,     6,     1,
       1,     1,     1,     1,     2,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     3,     6,     9,     0,     0,
      21,    24,     0,    22,     0,     1,    11,     5,     0,     8,
       0,     2,     0,    25,    23,     0,     0,    10,     4,     7,
       0,    34,    35,    36,    50,     0,     0,    49,    14,     0,
      47,    19,     0,    18,     0,     0,    48,    13,     0,     0,
      16,    15,     0,     0,    46,    20,    40,     0,    43,     0,
       0,    55,    52,    51,     0,    31,    31,    73,     0,     0,
      71,    72,     0,    56,    57,    58,    60,     0,    59,     0,
       0,    38,     0,    44,    45,    39,    53,    54,    29,    30,
      33,    33,     0,    65,     0,     0,     0,     0,    41,    42,
      37,     0,     0,     0,    62,    64,     0,     0,   101,   102,
     103,     0,     0,     0,     0,     0,     0,     0,    32,    27,
      28,    26,    63,   106,   104,     0,     0,   100,    99,     0,
       0,    76,    78,     0,    74,     0,     0,     0,     0,     0,
     106,   106,    77,    79,    75,     0,     0,     0,     0,     0,
     105,   106,     0,     0,    82,    80,    81,     0,     0,     0,
       0,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    95,     0,     0,    67,    68,    69,
      70,    66,    94,     0,     0,     0,     0,     0,     0,     0,
      89,    87,     0,     0,    83,    84,    90,    88,    85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    18,     6,    35,     7,    36,     8,     9,
      50,    90,   102,    37,   150,    60,    39,    40,    46,    51,
      73,    74,   106,    75,    76,    77,   116,   157,   177,    78,
     111,   129,   112,   138
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -76
static const yytype_int16 yypact[] =
{
      20,    33,   170,    40,    64,   -76,   203,   203,    86,   102,
     -76,   -76,    75,   -76,    67,   -76,   153,   -76,    86,   -76,
      86,   -76,    15,   -76,   -76,   153,   143,   -76,   -76,   -76,
      24,   -76,   -76,   -76,   -76,     3,   141,   -76,   -76,    76,
     151,   -76,   171,   -76,   164,    68,   176,   -76,    84,   123,
     -76,   -76,   178,   160,   176,   -76,   -76,   208,   -76,   186,
     213,   -76,   -76,   -76,    -7,   194,   194,   -76,   214,   215,
     -76,   -76,   189,   -76,   -76,   -76,   -76,   190,   -76,   216,
     217,   -76,   218,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     219,   219,    60,   -76,    96,    98,     9,     9,   -76,   -76,
     -76,   178,   220,   193,    24,   -76,     8,   192,   -76,   -76,
     -76,   103,    82,   108,   205,   172,   222,   197,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   221,    82,   151,   -76,   198,
     223,   -76,   -76,   109,   -76,   200,   206,    16,    31,   224,
     -76,   -76,   -76,   -76,   -76,    59,    59,    59,    59,   227,
     -76,   -76,    43,    47,   -76,   -76,   -76,   228,   229,   230,
     201,   -76,    55,   231,   150,   232,   133,   133,   133,   133,
     133,   233,   -76,   -76,   -76,   207,    17,   -76,   -76,   -76,
     -76,   -76,   -76,   234,   235,   236,   138,   237,   239,   240,
     -76,   -76,   241,   242,   -76,   -76,   -76,   -76,   -76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   144,   122,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   180,   146,   199,   -22,   -51,   -75,   -76,   209,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   154,    41,    12,   -76,
     155,   126,    92,   -23
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -94
static const yytype_int16 yytable[] =
{
      38,    79,    82,   -12,    30,    86,   -12,   -12,   -61,    30,
     114,   -61,   -61,    47,    31,    32,    30,   147,   185,    31,
      32,     1,   186,   187,     2,    87,    31,    32,   -17,    44,
     115,   -17,    30,    45,    33,    34,    10,   128,   148,    33,
      34,   149,    31,    32,    30,    14,    33,    34,   164,   188,
     118,   128,     3,   163,    31,    32,    30,   165,    31,    32,
     154,   104,    33,    34,    15,   171,    31,    32,    25,    61,
     105,    31,    32,    26,    33,    34,    23,    52,    33,    34,
      62,    53,    24,   127,   122,    65,    33,    34,   155,   156,
       2,    33,    34,    31,    32,    31,    32,   107,   -92,   107,
      63,   -92,   -92,   -93,   125,    22,   -93,   -93,   -91,   125,
     143,   -91,   -91,    33,    34,    33,   144,   152,   153,   108,
     109,   108,   109,   110,    67,   110,   108,   109,   162,    20,
     110,   108,   109,   -86,   175,   110,   -86,   -86,    27,   192,
      68,    69,    70,    71,    42,   193,    16,    41,    43,    72,
      17,    19,    21,   173,    48,    44,    16,    49,   176,    45,
      45,    80,    28,    81,    29,    57,    58,    56,    59,    57,
      58,    11,    59,   132,    55,    12,    13,   133,   134,   178,
     179,   180,   181,    57,    58,    64,    59,   158,   159,   160,
      94,    96,    95,    97,   120,   123,   121,   124,   136,   140,
     137,   141,   169,   126,   170,   126,    16,     2,    88,    89,
     130,   131,   183,   184,    84,    83,    85,    92,    93,    98,
      99,   100,   145,   119,   101,   135,   124,   151,   146,   142,
     161,   166,   167,   168,   172,   174,   182,   103,   190,   191,
     194,   189,   195,   196,   197,   198,    91,    66,     0,    54,
     113,   117,   139
};

static const yytype_int16 yycheck[] =
{
      22,    52,    53,     0,     1,    12,     3,     4,     0,     1,
       1,     3,     4,    35,    11,    12,     1,     1,     1,    11,
      12,     1,     5,     6,     4,    32,    11,    12,    13,     5,
      21,    16,     1,     9,    31,    32,     3,   112,    22,    31,
      32,    10,    11,    12,     1,     5,    31,    32,     1,    32,
     101,   126,    32,    10,    11,    12,     1,    10,    11,    12,
       1,     1,    31,    32,     0,    10,    11,    12,     1,     1,
      92,    11,    12,     6,    31,    32,     1,     1,    31,    32,
      12,     5,     7,     1,   106,     1,    31,    32,    29,    30,
       4,    31,    32,    11,    12,    11,    12,     1,     0,     1,
      32,     3,     4,     0,     1,     3,     3,     4,     0,     1,
       1,     3,     4,    31,    32,    31,     7,   140,   141,    23,
      24,    23,    24,    27,     1,    27,    23,    24,   151,     7,
      27,    23,    24,     0,     1,    27,     3,     4,    16,     1,
      17,    18,    19,    20,     1,     7,     3,    25,    26,    26,
       6,     7,     8,     3,    13,     5,     3,    16,    25,     9,
       9,     1,    18,     3,    20,     5,     6,     3,     8,     5,
       6,     1,     8,     1,     3,     5,     6,     5,     6,   167,
     168,   169,   170,     5,     6,     9,     8,   146,   147,   148,
       1,     1,     3,     3,     1,     3,     3,     5,     1,     1,
       3,     3,     1,   111,     3,   113,     3,     4,    14,    15,
       5,     6,     5,     6,    28,     7,     3,     3,     3,     3,
       3,     3,    22,     3,     5,     3,     5,     3,    22,     6,
       3,     3,     3,     3,     3,     3,     3,    91,     3,     3,
       3,     7,     3,     3,     3,     3,    66,    48,    -1,    40,
      95,    97,   126
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,    32,    34,    35,    37,    39,    41,    42,
       3,     1,     5,     6,     5,     0,     3,    35,    36,    35,
      36,    35,     3,     1,     7,     1,     6,    36,    35,    35,
       1,    11,    12,    31,    32,    38,    40,    46,    47,    49,
      50,    36,     1,    36,     5,     9,    51,    47,    13,    16,
      43,    52,     1,     5,    51,     3,     3,     5,     6,     8,
      48,     1,    12,    32,     9,     1,    46,     1,    17,    18,
      19,    20,    26,    53,    54,    56,    57,    58,    62,    48,
       1,     3,    48,     7,    28,     3,    12,    32,    14,    15,
      44,    44,     3,     3,     1,     3,     1,     3,     3,     3,
       3,     5,    45,    45,     1,    47,    55,     1,    23,    24,
      27,    63,    65,    63,     1,    21,    59,    59,    48,     3,
       1,     3,    47,     3,     5,     1,    65,     1,    49,    64,
       5,     6,     1,     5,     6,     3,     1,     3,    66,    64,
       1,     3,     6,     1,     7,    22,    22,     1,    22,    10,
      47,     3,    66,    66,     1,    29,    30,    60,    60,    60,
      60,     3,    66,    10,     1,    10,     3,     3,     3,     1,
       3,    10,     3,     3,     3,     1,    25,    61,    61,    61,
      61,    61,     3,     5,     6,     1,     5,     6,    32,     7,
       3,     3,     1,     7,     3,     3,     3,     3,     3
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 47 "ldif.y"
    {
    temporal_data.version() = OPTIONAL<INTEGER>(OMIT_VALUE);
  ;}
    break;

  case 13:
#line 72 "ldif.y"
    { 
      temporal_data.datalist()[data_counter-1].data().content()
        [AttrValRecord_Counter++] = temporal_AttrValRecord;
    ;}
    break;

  case 14:
#line 77 "ldif.y"
    {
      temporal_data.datalist()[data_counter-1].data().content()
        [AttrValRecord_Counter++] = temporal_AttrValRecord;
    ;}
    break;

  case 16:
#line 89 "ldif.y"
    {
       temporal_data.datalist()[data_counter - 1].data().change()
         .controllist() [control_counter++] = temporal_Control;
    ;}
    break;

  case 17:
#line 94 "ldif.y"
    {
       temporal_data.datalist()[data_counter-1].data().change()
         .controllist().set_size(0);
    ;}
    break;

  case 18:
#line 102 "ldif.y"
    {
       if (CHARSTRING("version") == *((yyvsp[(1) - (4)].string_val)))
       {
         const char* strValue = *((yyvsp[(3) - (4)].string_val));
         int version = atoi(strValue);
         
         1 == version ? temporal_data.version() = 1 : temporal_data.version() = OPTIONAL<INTEGER>(OMIT_VALUE);
       }else{
         temporal_data.version() = OPTIONAL<INTEGER>(OMIT_VALUE);
       }
       delete (yyvsp[(1) - (4)].string_val);
       delete (yyvsp[(3) - (4)].string_val);
    ;}
    break;

  case 19:
#line 116 "ldif.y"
    {
       TTCN_warning("Version error at line %d",line_number);
       error_recovery = false;
       erroneous = true;
       delete (yyvsp[(1) - (4)].string_val);
    ;}
    break;

  case 20:
#line 123 "ldif.y"
    {
       TTCN_warning("Version error at line %d",line_number);
       erroneous = true;
       
       delete (yyvsp[(1) - (5)].string_val);
       delete (yyvsp[(3) - (5)].string_val);
    ;}
    break;

  case 21:
#line 131 "ldif.y"
    {
       TTCN_warning("Version error at line %d",line_number);
       error_recovery = false;
       erroneous = true;
    ;}
    break;

  case 22:
#line 140 "ldif.y"
    {
       AttrValRecord_Counter = 0;
       modification_counter = 0;
       control_counter = 0;
       option_counter = 0;



       if(!inner_resolve_env)
       {
         temporal_data.datalist()[data_counter++].dn__string()
           = *((yyvsp[(2) - (2)].string_val));
       }else{
         CHARSTRING temp_char = CHARSTRING(*((yyvsp[(2) - (2)].string_val)));
         int index = 0;
         int start_pos = 0;
         int char_length = temp_char.lengthof();

         /*search for the first '$'*/
         for(; index < char_length && temp_char[index] != '$'; index++){}

         /*create the charstring from string till first '$'*/
         temporal_data.datalist()[data_counter].dn__string()
            = substr(temp_char,0,index);

         /*If there is some possible environment variable*/
         while(index < char_length)
         {
           start_pos = index++;
           unsigned int temp_ascii = char2int(temp_char[index]);
           char *env_val = NULL;
           // the first character of the id shall be a letter
           if ((temp_ascii >= 65 && temp_ascii <= 90) ||     /*A..Z*/
               (temp_ascii >= 97 && temp_ascii <= 122))      /*a..z*/
           {
             do
             {/*Search the full environment variable*/
               env_val = mputc(env_val, (char)temp_ascii);
               index++;
               if(index < char_length)
                 temp_ascii = char2int(temp_char[index]);
               else
                 temp_ascii = 0;
             } while ((temp_ascii >= 65 && temp_ascii <= 90) ||  /*A..Z*/
                      (temp_ascii >= 97 && temp_ascii <= 122) || /*a..z*/
                      (temp_ascii >= 48 && temp_ascii <= 57) ||  /*0..9*/
                       temp_ascii == 95);                        /*_   */
             char* temp = getenv((const char*)env_val);
             if(temp == NULL)
             {/*Environment variable not found. store as $something*/
               TTCN_warning("%s could not be resolved",(const char*)(env_val));
               temporal_data.datalist()[data_counter].dn__string()
                 = temporal_data.datalist()[data_counter].dn__string()
                   + substr(temp_char,start_pos,index-start_pos);
             }
             else
             {/*replace environment variable with its value*/
               temporal_data.datalist()[data_counter].dn__string()
                 = temporal_data.datalist()[data_counter].dn__string()
                   + temp;
             }
             start_pos = index;
             Free(env_val);
           }
           /*search for the next '$'*/
           for(; index < char_length && temp_char[index] != '$'; index++){}

           if(start_pos < char_length)
             /*complete the charstring from string till next '$'*/
             temporal_data.datalist()[data_counter].dn__string()
               = temporal_data.datalist()[data_counter].dn__string()
                 + substr(temp_char,start_pos,index-start_pos);
         }
         data_counter++;
       }



       delete (yyvsp[(2) - (2)].string_val);
    ;}
    break;

  case 23:
#line 221 "ldif.y"
    {
       AttrValRecord_Counter = 0;
       modification_counter = 0;
       control_counter = 0;
       option_counter = 0;
       temporal_data.datalist()[data_counter++].dn__string() 
         = *((yyvsp[(3) - (3)].string_val));
       delete (yyvsp[(3) - (3)].string_val);
    ;}
    break;

  case 24:
#line 231 "ldif.y"
    {
       TTCN_warning("Wrong format for the dn at line %d",line_number);
       error_recovery = false;
       AttrValRecord_Counter = 0;
       modification_counter = 0;
       control_counter = 0;
       option_counter = 0;
       temporal_data.datalist()[data_counter++].dn__string() 
         = "ERROR";
       erroneous = true;
    ;}
    break;

  case 25:
#line 243 "ldif.y"
    {
       TTCN_warning("Wrong format for the dn at line %d",line_number);
       error_recovery = false;
       AttrValRecord_Counter = 0;
       modification_counter = 0;
       control_counter = 0;
       option_counter = 0;
       temporal_data.datalist()[data_counter++].dn__string() 
         = "ERROR";
       erroneous = true;
    ;}
    break;

  case 26:
#line 258 "ldif.y"
    {
       temporal_Control.ldapoid() = *((yyvsp[(2) - (5)].string_val));
       delete (yyvsp[(2) - (5)].string_val);
    ;}
    break;

  case 27:
#line 263 "ldif.y"
    {
       if(!error_recovery)
       {
         TTCN_warning("ldap_oid error at line %d",line_number);
         error_recovery = true;
       }
       temporal_Control.ldapoid() = "0";
       erroneous = true;
    ;}
    break;

  case 28:
#line 273 "ldif.y"
    {
       if(!error_recovery)
       {
         TTCN_warning("line number %d contains more than one data", line_number);
         error_recovery = true;
       }
       temporal_Control.ldapoid() = "0";
       erroneous = true;
    ;}
    break;

  case 29:
#line 286 "ldif.y"
    {
       temporal_Control.criticality() = true;
    ;}
    break;

  case 30:
#line 290 "ldif.y"
    {
       temporal_Control.criticality() = false;
    ;}
    break;

  case 31:
#line 313 "ldif.y"
    {
       temporal_Control.criticality() = OPTIONAL<BOOLEAN>(OMIT_VALUE);
    ;}
    break;

  case 32:
#line 301 "ldif.y"
    {
       if (temporal_AttrValRecord.attributevalue()().ischosen(ValueUnion::ALT_safe__string)){
        temporal_Control.controlvalue() = 
          OCTETSTRING(temporal_AttrValRecord.attributevalue()().safe__string().lengthof(),
                      (const unsigned char*)(const char*)temporal_AttrValRecord.attributevalue()().safe__string());
       }else if (temporal_AttrValRecord.attributevalue()().ischosen(ValueUnion::ALT_base64__string)){
        temporal_Control.controlvalue() = 
          OCTETSTRING(temporal_AttrValRecord.attributevalue()().base64__string().lengthof(),
                      (const unsigned char*)(const char*)temporal_AttrValRecord.attributevalue()().base64__string());
       }else{
        temporal_Control.controlvalue() = 
          OCTETSTRING(temporal_AttrValRecord.attributevalue()().url().lengthof(),
                      (const unsigned char*)(const char*)temporal_AttrValRecord.attributevalue()().url());
       }
    ;}
    break;

  case 33:
#line 317 "ldif.y"
    {
       temporal_Control.controlvalue() = OPTIONAL<OCTETSTRING>(OMIT_VALUE);
    ;}
    break;

  case 34:
#line 324 "ldif.y"
    {
       (yyval.string_val) = (yyvsp[(1) - (1)].string_val);
    ;}
    break;

  case 35:
#line 328 "ldif.y"
    {
       (yyval.string_val) = (yyvsp[(1) - (1)].string_val);
    ;}
    break;

  case 36:
#line 332 "ldif.y"
    {
       (yyval.string_val) = (yyvsp[(1) - (1)].string_val);
    ;}
    break;

  case 38:
#line 340 "ldif.y"
    {
      temporal_AttrValRecord.attributevalue()().safe__string()
        = "";
    ;}
    break;

  case 39:
#line 345 "ldif.y"
    {
      if(!error_recovery){
        TTCN_warning("Attribute error at line %d",line_number);
        error_recovery = true;
      }
      temporal_AttrValRecord.attributetype() = CHARSTRING("ERROR");
      temporal_AttrValRecord.optionlist().set_size(0);
      temporal_AttrValRecord.attributevalue()().safe__string()
         = CHARSTRING("ERROR");
      erroneous = true;
    ;}
    break;

  case 40:
#line 357 "ldif.y"
    {
      if(!error_recovery){
        TTCN_warning("Attribute error at line %d",line_number);
        error_recovery = true;
      }
      temporal_AttrValRecord.attributetype() = CHARSTRING("ERROR");
      temporal_AttrValRecord.optionlist().set_size(0);
      temporal_AttrValRecord.attributevalue()().safe__string()
         = CHARSTRING("ERROR");
      erroneous = true;
    ;}
    break;

  case 41:
#line 369 "ldif.y"
    {
       TTCN_warning("Attribute must be separated from value with colon at line %d",line_number);
       error_recovery = false;
       erroneous = true;
    ;}
    break;

  case 42:
#line 375 "ldif.y"
    {
       TTCN_warning("Value error at line %d",line_number);
       error_recovery = false;
       temporal_AttrValRecord.attributevalue()().safe__string() 
         = CHARSTRING("ERROR");
       erroneous = true;
    ;}
    break;

  case 43:
#line 386 "ldif.y"
    {


       if(!inner_resolve_env)
       {
         temporal_AttrValRecord.attributevalue()().safe__string()
           = CHARSTRING(*((yyvsp[(1) - (1)].string_val)));
       }else{
         CHARSTRING temp_char = CHARSTRING(*((yyvsp[(1) - (1)].string_val)));
         int index = 0;
         int start_pos = 0;
         int char_length = temp_char.lengthof();

         /*search for the first '$'*/
         for(; index < char_length && temp_char[index] != '$'; index++){}

         /*create the charstring from string till first '$'*/
         temporal_AttrValRecord.attributevalue()().safe__string()
            = substr(temp_char,0,index);

         /*If there is some possible environment variable*/
         while(index < char_length)
         {
           start_pos = index++;
           unsigned int temp_ascii = char2int(temp_char[index]);
           char *env_val = NULL;
           /*The first character of the id shall be a letter*/
           if ((temp_ascii >= 65 && temp_ascii <= 90) ||     /*A..Z*/
               (temp_ascii >= 97 && temp_ascii <= 122))      /*a..z*/
           {
             do
             {/*Search the full environment variable*/
               env_val = mputc(env_val, (char)temp_ascii);
               index++;
               if(index < char_length)
                 temp_ascii = char2int(temp_char[index]);
               else
                 temp_ascii = 0;
             } while ((temp_ascii >= 65 && temp_ascii <= 90) ||  /*A..Z*/
                      (temp_ascii >= 97 && temp_ascii <= 122) || /*a..z*/
                      (temp_ascii >= 48 && temp_ascii <= 57) ||  /*0..9*/
                       temp_ascii == 95);                        /*_   */
             char* temp = getenv((const char*)env_val);
             if(temp == NULL)
             {/*Environment variable not found. store as $something*/
               TTCN_warning("%s could not be resolved",(const char*)(env_val));
               temporal_AttrValRecord.attributevalue()().safe__string()
                 = temporal_AttrValRecord.attributevalue()().safe__string()
                   + substr(temp_char,start_pos,index-start_pos);
             }
             else
             {/*replace environment variable with its value*/
               temporal_AttrValRecord.attributevalue()().safe__string()
                 = temporal_AttrValRecord.attributevalue()().safe__string()
                   + temp;
             }
             start_pos = index;
	     Free(env_val);
           }
           /*search for the next '$'*/
           for(; index < char_length && temp_char[index] != '$'; index++){}

           if(start_pos < char_length)
             /*complete the charstring from string till next '$'*/
             temporal_AttrValRecord.attributevalue()().safe__string()
               = temporal_AttrValRecord.attributevalue()().safe__string()
                 + substr(temp_char,start_pos,index-start_pos);
         }
       }




       delete (yyvsp[(1) - (1)].string_val);
    ;}
    break;

  case 44:
#line 462 "ldif.y"
    {
       temporal_AttrValRecord.attributevalue()().base64__string() 
         = *((yyvsp[(2) - (2)].string_val));
       delete (yyvsp[(2) - (2)].string_val);
    ;}
    break;

  case 45:
#line 468 "ldif.y"
    {
       temporal_AttrValRecord.attributevalue()().url() = *((yyvsp[(2) - (2)].string_val));
       delete (yyvsp[(2) - (2)].string_val);
    ;}
    break;

  case 46:
#line 476 "ldif.y"
    {
      temporal_AttrValRecord.attributetype() = *((yyvsp[(1) - (2)].string_val));
      delete (yyvsp[(1) - (2)].string_val);
    ;}
    break;

  case 47:
#line 481 "ldif.y"
    {
      temporal_AttrValRecord.attributetype() = *((yyvsp[(1) - (1)].string_val));
      delete (yyvsp[(1) - (1)].string_val);
    ;}
    break;

  case 48:
#line 486 "ldif.y"
    {
      if(!error_recovery)
      {
        TTCN_warning("Attribute error at line %d",line_number);
        error_recovery = true;
      }
      temporal_AttrValRecord.attributetype() = CHARSTRING("ERROR");
      erroneous = true;
    ;}
    break;

  case 49:
#line 499 "ldif.y"
    {
      (yyval.string_val) = (yyvsp[(1) - (1)].string_val);
      option_counter = 0;
      temporal_AttrValRecord.optionlist().set_size(0);
    ;}
    break;

  case 50:
#line 505 "ldif.y"
    {
      (yyval.string_val) = (yyvsp[(1) - (1)].string_val);
      option_counter = 0;
      temporal_AttrValRecord.optionlist().set_size(0);
    ;}
    break;

  case 51:
#line 514 "ldif.y"
    {
      temporal_AttrValRecord.optionlist()[option_counter++] = *((yyvsp[(2) - (2)].string_val));
      delete (yyvsp[(2) - (2)].string_val);
    ;}
    break;

  case 52:
#line 519 "ldif.y"
    {
      temporal_AttrValRecord.optionlist()[option_counter++] = *((yyvsp[(2) - (2)].string_val));
      delete (yyvsp[(2) - (2)].string_val);
    ;}
    break;

  case 53:
#line 524 "ldif.y"
    {
      temporal_AttrValRecord.optionlist()[option_counter++] = *((yyvsp[(3) - (3)].string_val));
      delete (yyvsp[(3) - (3)].string_val);
    ;}
    break;

  case 54:
#line 529 "ldif.y"
    {
      temporal_AttrValRecord.optionlist()[option_counter++] = *((yyvsp[(3) - (3)].string_val));
      delete (yyvsp[(3) - (3)].string_val);
    ;}
    break;

  case 55:
#line 534 "ldif.y"
    {
      if(!error_recovery)
      {
        TTCN_warning("Wrong option syntax at line %d",line_number);
        error_recovery = true;
      }
      temporal_AttrValRecord.optionlist()[option_counter++] = "ERROR";
      erroneous = true;
    ;}
    break;

  case 56:
#line 547 "ldif.y"
    {
      if(error_recovery)
        error_recovery = false;
    ;}
    break;

  case 62:
#line 563 "ldif.y"
    {
       if(!error_recovery)
       {
         TTCN_warning("Add must be followed by at least 1 attribute:value "
           "pair at line %d",line_number);
         error_recovery = true;
       }
       temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changeadd().set_size(0);
       erroneous = true;
    ;}
    break;

  case 63:
#line 578 "ldif.y"
    {
       temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changeadd()[AttrValRecord_Counter++] 
       = temporal_AttrValRecord;
    ;}
    break;

  case 64:
#line 584 "ldif.y"
    {
        AttrValRecord_Counter = 0;
        temporal_data.datalist()[data_counter - 1].data().change()
          .changetype().changeadd()[AttrValRecord_Counter++] 
        = temporal_AttrValRecord;
    ;}
    break;

  case 65:
#line 594 "ldif.y"
    {
       temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changedelete().set_size(0);
    ;}
    break;

  case 67:
#line 606 "ldif.y"
    {
       if(!error_recovery)
       {
         TTCN_warning("line number %d contains more than one data", line_number);
         error_recovery = true;
       }
       erroneous = true;
    ;}
    break;

  case 68:
#line 616 "ldif.y"
    {
       if(!error_recovery)
       {
          TTCN_warning("line number %d contains more than one data", line_number);
          error_recovery = true;
       }
       erroneous = true;
    ;}
    break;

  case 69:
#line 626 "ldif.y"
    {
      if(!error_recovery)
      {
         TTCN_warning("deleteoldrdn missing from the change moddn structure"
         " ending on the %dth line",line_number-1);
         error_recovery = true;
      }
      temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changemoddn().deleteoldrdn() = false;
      erroneous = true;
    ;}
    break;

  case 70:
#line 639 "ldif.y"
    {
      if(!error_recovery)
      {
         TTCN_warning("line number %d contains more than one data", line_number);
         error_recovery = true;
      }
      temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changemoddn().deleteoldrdn() = false;
      erroneous = true;
    ;}
    break;

  case 71:
#line 653 "ldif.y"
    {
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().modtype() = CHARSTRING("MODRDN");
    ;}
    break;

  case 72:
#line 658 "ldif.y"
    {
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().modtype() = CHARSTRING("MODDN");
    ;}
    break;

  case 73:
#line 663 "ldif.y"
    {
      if(!error_recovery)
      {
        TTCN_warning("Wrong moddn type at line %d",
          line_number);
        error_recovery = true;
      }
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().modtype() = CHARSTRING("ERROR");
      erroneous = true;
    ;}
    break;

  case 74:
#line 678 "ldif.y"
    {
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newrdn() 
        = *((yyvsp[(1) - (2)].string_val));
      delete (yyvsp[(1) - (2)].string_val);
    ;}
    break;

  case 75:
#line 685 "ldif.y"
    {
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newrdn() 
        = *((yyvsp[(2) - (3)].string_val));
      delete (yyvsp[(2) - (3)].string_val);
    ;}
    break;

  case 76:
#line 692 "ldif.y"
    {
      if(!error_recovery)
      {
        TTCN_warning("The keyword newrdn was expected at line "
          "%d",line_number);
        error_recovery = true;
      }
      erroneous = true;
    ;}
    break;

  case 77:
#line 702 "ldif.y"
    {
      if(!error_recovery)
      {
        TTCN_warning("The keyword newrdn was expected at line "
          "%d",line_number);
        error_recovery = true;
      }
      erroneous = true;
    ;}
    break;

  case 78:
#line 712 "ldif.y"
    {
      if(!error_recovery)
      {
        TTCN_warning("Wrong newrdn value at line %d",line_number);
        error_recovery = true;
      }
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newrdn() = "ERROR";
      erroneous = true;
    ;}
    break;

  case 79:
#line 723 "ldif.y"
    {
      if(!error_recovery)
      {
        TTCN_warning("Wrong newrdn value at line %d",line_number);
        error_recovery = true;
      }
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newrdn() = "ERROR";
      erroneous = true;
    ;}
    break;

  case 80:
#line 737 "ldif.y"
    {
       temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changemoddn().deleteoldrdn() = false;
    ;}
    break;

  case 81:
#line 742 "ldif.y"
    {
       temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changemoddn().deleteoldrdn() = true;
    ;}
    break;

  case 82:
#line 747 "ldif.y"
    {
       if(!error_recovery)
       {
          TTCN_warning("Wrong deleteoldrdn value at line %d",line_number);
          error_recovery = true;
       }
       temporal_data.datalist()[data_counter - 1].data().change()
          .changetype().changemoddn().deleteoldrdn() = false;
       erroneous = true;
    ;}
    break;

  case 83:
#line 761 "ldif.y"
    {
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newsuperior()().distinguished() 
        = *((yyvsp[(2) - (3)].string_val));
      delete (yyvsp[(2) - (3)].string_val);
    ;}
    break;

  case 84:
#line 768 "ldif.y"
    {
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newsuperior()().distinguished() 
        = *((yyvsp[(2) - (3)].string_val));
      delete (yyvsp[(2) - (3)].string_val);
    ;}
    break;

  case 85:
#line 775 "ldif.y"
    {
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newsuperior()().base64__distinguished() 
        = *((yyvsp[(3) - (4)].string_val));
      delete (yyvsp[(3) - (4)].string_val);
    ;}
    break;

  case 86:
#line 782 "ldif.y"
    {
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newsuperior() 
        = OPTIONAL<NewSuperior>(OMIT_VALUE);
    ;}
    break;

  case 87:
#line 788 "ldif.y"
    {
      if(!error_recovery)
      {
        TTCN_warning("Wrong newsuperior value at line %d",line_number);
        error_recovery = true;
      }
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newsuperior()().distinguished() 
        = "ERROR";
      erroneous = true;
    ;}
    break;

  case 88:
#line 800 "ldif.y"
    {
      if(!error_recovery)
      {
        TTCN_warning("Wrong newsuperior value at line %d",line_number);
        error_recovery = true;
      }
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newsuperior()().distinguished() 
        = "ERROR";
      erroneous = true;
    ;}
    break;

  case 89:
#line 812 "ldif.y"
    {
      if(!error_recovery)
      {
        TTCN_warning("The keyword newsuperior was expected at line "
          "%d",line_number);
        error_recovery = true;
      }
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newsuperior()().distinguished() 
        = "ERROR";
      erroneous = true;      
    ;}
    break;

  case 90:
#line 825 "ldif.y"
    {
      if(!error_recovery)
      {
        TTCN_warning("The keyword newsuperior was expected at line "
          "%d",line_number);
        error_recovery = true;
      }
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newsuperior()().distinguished() 
        = "ERROR";
      erroneous = true;      
    ;}
    break;

  case 92:
#line 842 "ldif.y"
    {
       temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changemodify().set_size(0)
    ;}
    break;

  case 93:
#line 847 "ldif.y"
    {
      if(!error_recovery)
      {
        TTCN_warning("line number %d contains more than one data", line_number);
        error_recovery = true;
      }
    ;}
    break;

  case 94:
#line 858 "ldif.y"
    {
       temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changemodify()[modification_counter++] 
         = temporal_changemodifydata;
    ;}
    break;

  case 95:
#line 864 "ldif.y"
    {
       temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changemodify()[modification_counter++] 
         = temporal_changemodifydata;
    ;}
    break;

  case 96:
#line 870 "ldif.y"
    {
       temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changemodify()[modification_counter++] 
         = temporal_changemodifydata;
    ;}
    break;

  case 97:
#line 876 "ldif.y"
    {
      if(!error_recovery)
      {
        TTCN_warning("line number %d contains more than one data", line_number);
        error_recovery = true;
      }
      erroneous = true;
    ;}
    break;

  case 98:
#line 885 "ldif.y"
    {
       if(!error_recovery)
       {
         TTCN_warning("Hyphen expected at line %d",line_number);
         error_recovery = true;
       }
       temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changemodify()[modification_counter++] 
         = temporal_changemodifydata;
         erroneous = true;
    ;}
    break;

  case 99:
#line 900 "ldif.y"
    {
      temporal_AttrValRecord.attributevalue() =OPTIONAL<ValueUnion>(OMIT_VALUE);
      temporal_AttrValRecord.optionlist().set_size(0);
      temporal_changemodifydata.attrvalrecordlist()[0] = temporal_AttrValRecord;
      AttrValRecord_Counter = 1;
    ;}
    break;

  case 100:
#line 907 "ldif.y"
    {
      if(!error_recovery){
        TTCN_warning("Attribute error at line %d",line_number);
        error_recovery = true;
      }
      temporal_AttrValRecord.attributetype() = CHARSTRING("ERROR");
      temporal_AttrValRecord.optionlist().set_size(0);
      temporal_AttrValRecord.attributevalue()=OPTIONAL<ValueUnion>(OMIT_VALUE);
      temporal_changemodifydata.attrvalrecordlist()[0] = temporal_AttrValRecord;
      erroneous = true;
      yyerrok;
    ;}
    break;

  case 101:
#line 923 "ldif.y"
    {
       temporal_changemodifydata.operation() = CHARSTRING("add");
       temporal_changemodifydata.attrvalrecordlist().set_size(0);
    ;}
    break;

  case 102:
#line 928 "ldif.y"
    {
       temporal_changemodifydata.operation() = CHARSTRING("delete");
       temporal_changemodifydata.attrvalrecordlist().set_size(0);
    ;}
    break;

  case 103:
#line 933 "ldif.y"
    {
       temporal_changemodifydata.operation() = CHARSTRING("replace");
       temporal_changemodifydata.attrvalrecordlist().set_size(0);
    ;}
    break;

  case 104:
#line 938 "ldif.y"
    {
      if(!error_recovery)
      {
        TTCN_warning("Wrong modification operation name at line "
          "%d",line_number);
        error_recovery = true;
      }
      temporal_changemodifydata.operation() = CHARSTRING("ERROR");
      temporal_changemodifydata.attrvalrecordlist().set_size(0);
      erroneous = true;
      yyerrok;
    ;}
    break;

  case 105:
#line 954 "ldif.y"
    {
      temporal_changemodifydata.attrvalrecordlist()
        [AttrValRecord_Counter++] = temporal_AttrValRecord;
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2648 "ldif.tab.cc"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 961 "ldif.y"


void ldif_error(const char *s)
{
}
extern FILE* ldif_in;
LDIF__RFC4511::LDIFData LDIF__RFC4511::f__ImportLDIF(const CHARSTRING& pl__file__name, const BOOLEAN& pl__resolve__env)
{
  temporal_data.version() = -1;
  temporal_data.datalist().set_size(0);


  ldif_in = fopen(pl__file__name,"r");

  if(ldif_in != NULL)
  {
     line_number = 0;
     AttrValRecord_Counter = 0;
     option_counter = 0;
     data_counter = 0;
     control_counter = 0;
     modification_counter = 0;
     erroneous = false;
     inner_resolve_env = pl__resolve__env;

     ldif_restart(ldif_in);
     if(yyparse() != 0)
     {
       temporal_data.version() = -1;
       temporal_data.datalist().set_size(0);
     }else if(erroneous)
     {
       temporal_data.version() = -1;
       temporal_data.datalist().set_size(0);
     }else{
       bool selection = temporal_data.datalist()[0].data().ischosen(LDIFChoice::ALT_content);
       for(int i = 1; i < temporal_data.datalist().size_of(); i++)
       {
         if(selection != temporal_data.datalist()[i].data().ischosen(LDIFChoice::ALT_content))
         {
           erroneous = true;
           TTCN_warning("Content and change records "
             "can not be mixed in one file");
         }
       }
       
       for(int i = 0; i < temporal_data.datalist().size_of(); i++)
       {
          if(temporal_data.datalist()[i].data().ischosen(LDIFChoice::ALT_change )
            && temporal_data.datalist()[i].data().change().changetype()
                 .ischosen(ChangeType::ALT_changemodify))
          {
             for(int j = 0;
                 j < temporal_data.datalist()[i].data().change()
                       .changetype().changemodify().size_of();
                 j++)
             {
               CHARSTRING type = temporal_data.datalist()[i].data()
                                   .change().changetype().changemodify()[j]
                                   .attrvalrecordlist()[0].attributetype();
               for(int k = 1;
                   k < temporal_data.datalist()[i].data()
                         .change().changetype().changemodify()[j]
                         .attrvalrecordlist().size_of(); 
                  k++)
               {
                 if(type != temporal_data.datalist()[i].data().change()
                             .changetype().changemodify()[j]
                             .attrvalrecordlist()[k].attributetype())
                 {
                   TTCN_warning("The %dth modified attribute's type is "
                     "different from the one described in the %dth "
                     "changerecord's %dth modify record (%s) (%s)",k,i,j,
                     (const char*)type,(const char*)temporal_data.datalist()[i]
                     .data().change().changetype().changemodify()[j]
                     .attrvalrecordlist()[k].attributetype());
                   erroneous = true;
                 }
               }
             }
          }
       }
       if(erroneous)
         temporal_data.version() = -1;
     }
  }else{
     TTCN_warning("The file %s could not be opened",(const char*)pl__file__name);
  }

  fclose(ldif_in);
  return temporal_data;	
}

