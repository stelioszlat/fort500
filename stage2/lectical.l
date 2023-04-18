%{
    // #include "keywords.h"
    #include "syntactical.tab.h"
    #include "string.h"
    #include "hash_table.h"

    int words = 0;
    int lines = 0;
    int errors = 0;
    HASHTBL *table;
%}

alpha             [a-zA-Z]
nalpha            [^a-zA-Z]
digit             [0-9]
digitn            [1-9]
hex_digit         [0-9A-F]
hex_digitn        [1-9A-F]
alphanum          [a-zA-Z0-9]
alphanumu         [a-zA-z0-9_]
wh                [ \t]

%option caseless
%option noyywrap
%% 

FUNCTION        {return T_FUNCTION;}
SUBROUTINE      {return T_SUBROUTINE;}
END             {return T_END;}
INTEGER         {return T_INTEGER;}
REAL            {return T_REAL;}
LOGICAL         {return T_LOGICAL;}
CHARACTER       {return T_CHARACTER;}
COMPLEX         {return T_COMPLEX;}
RECORD          {return T_RECORD;}
ENDREC          {return T_ENDREC;}
LIST            {return T_LIST;}
DATA            {return T_DATA;}
CONTINUE        {return T_CONTINUE;}
GOTO            {return T_GOTO;}
CALL            {return T_CALL;}
READ            {return T_READ;}
WRITE           {return T_WRITE;}
NEW             {return T_NEW;}
LENGTH          {return T_LENGTH;}
IF              {return T_IF;}
THEN            {return T_THEN;}
ELSE            {return T_ELSE;}
ENDIF           {return T_ENDIF;}
DO              {return T_DO;}
ENDDO           {return T_ENDDO;}
STOP            {return T_STOP;}
RETURN          {return T_RETURN;}

0                                                           {return T_ICONST;}
{digitn}{digit}*|{digit}                                    {return T_ICONST;}
0B1[01]*|0H{hex_digitn}{hex_digit}*                         {return T_ICONST;}
(0|{digitn}{digit}*)?"."(0*{digitn}+{digit}*|0)             {return T_RCONST;}                                    

"."("TRUE"|"FALSE")"."          {return T_LCONST;}
\'.?\'|\'\\[nftrbv]\'           {return T_CCONST;}
\".*((\\\n)?.*)*\"              {return T_SCONST;}
"."OR"."                        {return T_OROP;}
"."AND"."                       {return T_ANDOP;}
"."NOT"."                       {return T_NOTOP;}
"."(GT|GE|LT|LE|EQ|NE)"."       {return T_RELOP;}
"+"|"-"                         {return T_ADDOP;}
"*"                             {return T_MULOP;}
"/"                             {return T_DIVOP;}
"**"                            {return T_POWEROP;}
"("                             {return T_LPAREN;}
")"                             {return T_RPAREN;}
","                             {return T_COMMA;}
"="                             {return T_ASSIGN;}
"."                             {return T_DOT;}
":"                             {return T_COLON;}
"["                             {return T_LBRACK;}
"]"                             {return T_RBRACK;}
\$.*                            {return T_COMMENT;}

{alpha}{alphanum}*|_{alpha}{alphanum}*(_{alphanum}+)?_       {return T_ID;}

\n                              {lines++;}
{wh}+                           {}
.                               {printf("\e[0;32m\e[0;31mError:\e[0;37m %d: unidentified character: %s\n", lines, yytext);errors++;}
%%