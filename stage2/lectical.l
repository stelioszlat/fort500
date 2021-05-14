

%{
    // #include "keywords.h"
    #include "syntactical.tab.h"
    #include "string.h"

    int words = 0;
    int lines = 0;
    int errors = 0;

%}

alpha             [a-zA-Z]
digit             [0-9]
digitn            [1-9]
hex_digit         [0-9A-F]
hex_digitn        [1-9A-F]
alphanum          [a-zA-Z0-9]
alphanumu         [a-zA-z0-9_]

%option caseless

%option noyywrap
%% 

FUNCTION        {printf("FUNCTION: %d\n", T_FUNCTION);return T_FUNCTION;}
SUBROUTINE      {printf("SUBOUTINE: %d\n", T_SUBROUTINE);return T_SUBROUTINE;}
END             {printf("END: %d\n", T_END);return T_END;}
INTEGER         {printf("INTEGER: %d\n", T_INTEGER);return T_INTEGER;}
REAL            {printf("REAL: %d\n", T_REAL);return T_REAL;}
LOGICAL         {printf("LOGICAL: %d\n", T_LOGICAL);return T_LOGICAL;}
CHARACTER       {printf("CHARACTER: %d\n", T_CHARACTER);return T_CHARACTER;}
RECORD          {printf("RECORD: %d\n", T_RECORD);return T_RECORD;}
ENDREC          {printf("ENDREC: %d\n", T_ENDREC);return T_ENDREC;}
DATA            {printf("DATA: %d\n", T_DATA);return T_DATA;}
CONTINUE        {printf("CONTINUE: %d\n", T_CONTINUE);return T_CONTINUE;}
GOTO            {printf("GOTO: %d\n", T_GOTO);return T_GOTO;}
CALL            {printf("CALL: %d\n", T_CALL);return T_CALL;}
READ            {printf("READ: %d\n", T_READ);return T_READ;}
WRITE           {printf("WRITE: %d\n", T_WRITE);return T_WRITE;}
IF              {printf("IF: %d\n", T_IF);return T_IF;}
THEN            {printf("THEN: %d\n", T_THEN);return T_THEN;}
ELSE            {printf("ELSE: %d\n", T_ELSE);return T_ELSE;}
ENDIF           {printf("ENDIF: %d\n", T_ENDIF);return T_ENDIF;}
DO              {printf("DO: %d\n", T_DO);return T_DO;}
ENDDO            {printf("ENDO: %d\n", T_ENDO);return T_ENDO;}
STOP            {printf("STOP: %d\n", T_STOP);return T_STOP;}
RETURN          {printf("RETURN: %d\n", T_RETURN);return T_RETURN;}

0B1[01]*|0H{hex_digitn}{hex_digit}*                             {printf("INTEGER CONSTANT: %d\n|-NUMERICAL VALUE: %d\n", T_ICONST, strtonum(yytext));return T_ICONST;}
0|{digitn}{digit}*                                              {printf("INTEGER CONSTANT: %d\n|-NUMERICAL VALUE: %s\n", T_ICONST, yytext);return T_ICONST;}
(0|{digitn}{digit}*)"."(0*{digitn}+{digit}*|0)                   {printf("REAL CONSTANT: %d\n|-NUMERICAL VALUE: %s\n", T_RCONST, yytext);return T_RCONST;}                                    

"."("TRUE"|"FALSE")"."          {printf("LOGICAL CONSTANT: %d\n|-CONSTANT VALUE: %s\n", T_LCONST, yytext);return T_LCONST;}
\'.\'|\'\\[nftrbv]\'            {printf("CHARACTER CONSTANT: %d\n|-CONSTANT VALUE: %s\n", T_CCONST, yytext);return T_CCONST;}
\".*\"                          {printf("STRING CONSTANT: %d\n", T_SCONST);return T_SCONST;}
"."OR"."                        {printf("OR OPERATOR: %d\n", T_OROP);return T_OROP;}
"."AND"."                       {printf("AND OPERATOR: %d\n", T_ANDOP);return T_ANDOP;}
"."NOT"."                       {printf("NOT OPERATOR: %d\n", T_NOTOP);return T_NOTOP;}
"."(GT|GE|LT|LE|EQ|NE)"."       {printf("RELATIONAL OPERATOR: %d\n", T_RELOP);return T_RELOP;}
"+"|"-"                         {printf("ADDITION OPERATOR: %d\n", T_ADDOP);return T_ADDOP;}
"*"                             {printf("MULTIPLICATION OPERATOR: %d\n", T_MULOP);return T_MULOP;}
"/"                             {printf("DIVISION OPERATOR: %d\n", T_DIVOP);return T_DIVOP;}
"**"                            {printf("POWER OPERATOR: %d\n", T_POWEROP);return T_POWEROP;}
"("                             {printf("LEFT PARENTHESES SYMBOL: %d\n", T_LPAREN);return T_LPAREN;}
")"                             {printf("RIGHT PARENTHESES SYMBOL: %d\n", T_RPAREN);return T_RPAREN;}
","                             {printf("COMMA SYMBOL: %d\n", T_COMMA);return T_COMMA;}
"="                             {printf("ASSIGN SYMBOL : %d\n", T_ASSIGN);return T_ASSIGN;}
":"                             {printf("COLON SYMBOL: %d\n", T_COLON);return T_COLON;}
$.*                             {printf("COMMENT LINE: %d\n", T_COMMENT);return T_COMMENT;}

\n                              {lines++;}

{alpha}({alphanum}*|{alphanum}"_"{alphanum}|"_")*        {printf("ID : %d\n|-IDENTIFIER VALUE: %s\n", T_ID, yytext);return T_ID;}
.                               {fprintf(stderr, "Lectical: %d : \x1b[31merror:\x1b[0m unidentified character %s\n", ++errors, yytext);return -1;}
%%

int strtonum(char *str){
    if(str[0] != 0){
        switch(str[1]){
            case 'H':{
                break;
            }
            case 'B':{
                printf("Binary number");
                break;
            }
        }
    }
    else{
        errors++;
        fprintf(stderr, "%s: invalid number format", str);
    }
    return 0;
}

int strtoint(char *str){
    printf("%s\n", str);
    return 0;
}

int strtohex(char *str){
    printf("%s\n", str);
    return (int)strtol(&str[2], NULL, 16);
}

int strtobin(char *str){
    return (int)strtol(&str[2], NULL, 2);
}
