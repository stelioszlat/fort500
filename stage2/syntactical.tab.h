/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_FUNCTION = 258,
     T_SUBROUTINE = 259,
     T_END = 260,
     T_INTEGER = 261,
     T_REAL = 262,
     T_LOGICAL = 263,
     T_STRING = 264,
     T_CHARACTER = 265,
     T_RECORD = 266,
     T_ENDREC = 267,
     T_DATA = 268,
     T_CONTINUE = 269,
     T_GOTO = 270,
     T_CALL = 271,
     T_READ = 272,
     T_WRITE = 273,
     T_IF = 274,
     T_THEN = 275,
     T_ELSE = 276,
     T_ENDIF = 277,
     T_DO = 278,
     T_ENDO = 279,
     T_STOP = 280,
     T_RETURN = 281,
     T_ICONST = 282,
     T_RCONST = 283,
     T_LCONST = 284,
     T_CCONST = 285,
     T_SCONST = 286,
     T_OROP = 287,
     T_ANDOP = 288,
     T_NOTOP = 289,
     T_RELOP = 290,
     T_ADDOP = 291,
     T_MULOP = 292,
     T_DIVOP = 293,
     T_POWEROP = 294,
     T_LPAREN = 295,
     T_RPAREN = 296,
     T_COMMA = 297,
     T_ASSIGN = 298,
     T_COLON = 299,
     T_COMMENT = 300,
     T_ID = 301
   };
#endif
/* Tokens.  */
#define T_FUNCTION 258
#define T_SUBROUTINE 259
#define T_END 260
#define T_INTEGER 261
#define T_REAL 262
#define T_LOGICAL 263
#define T_STRING 264
#define T_CHARACTER 265
#define T_RECORD 266
#define T_ENDREC 267
#define T_DATA 268
#define T_CONTINUE 269
#define T_GOTO 270
#define T_CALL 271
#define T_READ 272
#define T_WRITE 273
#define T_IF 274
#define T_THEN 275
#define T_ELSE 276
#define T_ENDIF 277
#define T_DO 278
#define T_ENDO 279
#define T_STOP 280
#define T_RETURN 281
#define T_ICONST 282
#define T_RCONST 283
#define T_LCONST 284
#define T_CCONST 285
#define T_SCONST 286
#define T_OROP 287
#define T_ANDOP 288
#define T_NOTOP 289
#define T_RELOP 290
#define T_ADDOP 291
#define T_MULOP 292
#define T_DIVOP 293
#define T_POWEROP 294
#define T_LPAREN 295
#define T_RPAREN 296
#define T_COMMA 297
#define T_ASSIGN 298
#define T_COLON 299
#define T_COMMENT 300
#define T_ID 301




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 2 "syntactical.y"
{
    int integerval;
    double doubleval;
    char *stringval;
}
/* Line 1529 of yacc.c.  */
#line 147 "syntactical.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

