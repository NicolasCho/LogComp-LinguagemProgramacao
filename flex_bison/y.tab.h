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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    TIDENTIFIER = 258,             /* TIDENTIFIER  */
    TFLOAT = 259,                  /* TFLOAT  */
    TINTEGER = 260,                /* TINTEGER  */
    TEQUAL = 261,                  /* TEQUAL  */
    TCNE = 262,                    /* TCNE  */
    TCEQ = 263,                    /* TCEQ  */
    TCGT = 264,                    /* TCGT  */
    TCGE = 265,                    /* TCGE  */
    TCLT = 266,                    /* TCLT  */
    TCLE = 267,                    /* TCLE  */
    TLPAREN = 268,                 /* TLPAREN  */
    TRPAREN = 269,                 /* TRPAREN  */
    TLBRACE = 270,                 /* TLBRACE  */
    TRBRACE = 271,                 /* TRBRACE  */
    TDOT = 272,                    /* TDOT  */
    TCOMMA = 273,                  /* TCOMMA  */
    TCOLON = 274,                  /* TCOLON  */
    TMINUS = 275,                  /* TMINUS  */
    TPLUS = 276,                   /* TPLUS  */
    TDIV = 277,                    /* TDIV  */
    TMULT = 278,                   /* TMULT  */
    TWHILE = 279,                  /* TWHILE  */
    TIF = 280,                     /* TIF  */
    TELIF = 281,                   /* TELIF  */
    TELSE = 282,                   /* TELSE  */
    TRETURN = 283,                 /* TRETURN  */
    TDEF = 284,                    /* TDEF  */
    TPRINT = 285,                  /* TPRINT  */
    TNEWLINE = 286                 /* TNEWLINE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TIDENTIFIER 258
#define TFLOAT 259
#define TINTEGER 260
#define TEQUAL 261
#define TCNE 262
#define TCEQ 263
#define TCGT 264
#define TCGE 265
#define TCLT 266
#define TCLE 267
#define TLPAREN 268
#define TRPAREN 269
#define TLBRACE 270
#define TRBRACE 271
#define TDOT 272
#define TCOMMA 273
#define TCOLON 274
#define TMINUS 275
#define TPLUS 276
#define TDIV 277
#define TMULT 278
#define TWHILE 279
#define TIF 280
#define TELIF 281
#define TELSE 282
#define TRETURN 283
#define TDEF 284
#define TPRINT 285
#define TNEWLINE 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
