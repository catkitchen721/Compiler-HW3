/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    ADD = 264,
    SUB = 265,
    MUL = 266,
    DIV = 267,
    MOD = 268,
    INC = 269,
    DEC = 270,
    MT = 271,
    LT = 272,
    MTE = 273,
    LTE = 274,
    EQ = 275,
    NE = 276,
    ASGN = 277,
    ADDASGN = 278,
    SUBASGN = 279,
    MULASGN = 280,
    DIVASGN = 281,
    MODASGN = 282,
    AND = 283,
    OR = 284,
    NOT = 285,
    LB = 286,
    RB = 287,
    LCB = 288,
    RCB = 289,
    LSB = 290,
    RSB = 291,
    COMMA = 292,
    RET = 293,
    CONTINUE = 294,
    BREAK = 295,
    C_COMMENT = 296,
    CPP_COMMENT = 297,
    NL = 298,
    I_CONST = 299,
    F_CONST = 300,
    TRUE_RESULT = 301,
    FALSE_RESULT = 302,
    INT = 303,
    FLOAT = 304,
    BOOL = 305,
    STRING = 306,
    VOID = 307,
    STR_CONST = 308,
    ID = 309
  };
#endif
/* Tokens.  */
#define PRINT 258
#define IF 259
#define ELSE 260
#define FOR 261
#define WHILE 262
#define SEMICOLON 263
#define ADD 264
#define SUB 265
#define MUL 266
#define DIV 267
#define MOD 268
#define INC 269
#define DEC 270
#define MT 271
#define LT 272
#define MTE 273
#define LTE 274
#define EQ 275
#define NE 276
#define ASGN 277
#define ADDASGN 278
#define SUBASGN 279
#define MULASGN 280
#define DIVASGN 281
#define MODASGN 282
#define AND 283
#define OR 284
#define NOT 285
#define LB 286
#define RB 287
#define LCB 288
#define RCB 289
#define LSB 290
#define RSB 291
#define COMMA 292
#define RET 293
#define CONTINUE 294
#define BREAK 295
#define C_COMMENT 296
#define CPP_COMMENT 297
#define NL 298
#define I_CONST 299
#define F_CONST 300
#define TRUE_RESULT 301
#define FALSE_RESULT 302
#define INT 303
#define FLOAT 304
#define BOOL 305
#define STRING 306
#define VOID 307
#define STR_CONST 308
#define ID 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 54 "compiler_hw3.y" /* yacc.c:1909  */

	int i_val;
    double f_val;
    char* string;
    int bool_val;

#line 169 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
