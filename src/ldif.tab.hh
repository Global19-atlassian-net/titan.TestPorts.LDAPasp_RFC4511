/******************************************************************************
* Copyright (c) 2000-2018 Ericsson Telecom AB
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 28 "ldif.y"
{
	CHARSTRING *string_val;
}
/* Line 1489 of yacc.c.  */
#line 117 "ldif.tab.hh"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE ldif_lval;

