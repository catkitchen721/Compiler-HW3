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
#line 59 "compiler_hw3.y" /* yacc.c:1909  */

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
