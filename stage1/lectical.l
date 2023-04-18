
%{
    #include "keywords.h"
    #include <string.h>

    int lines = 1;
    int errors = 0;
%}

alpha             [a-zA-Z]
nalpha            [^a-zA-Z]
digit             [0-9]
digitn            [1-9]
hex_digit         [0-9A-F]
hex_digitn        [1-9A-F]
alphanum          [a-zA-Z0-9]
alphanumu         [a-zA-z0-9_]
wh                 [ \t]

%option caseless
%option noyywrap
%% 

FUNCTION        {print_token("FUNCTION", T_FUNCTION);return T_FUNCTION;}
SUBROUTINE      {print_token("SUBROUTINE", T_SUBROUTINE);return T_SUBROUTINE;}
END             {print_token("END", T_END);return T_END;}
INTEGER         {print_token("INTEGER", T_INTEGER);return T_INTEGER;}
REAL            {print_token("REAL", T_REAL);return T_REAL;}
LOGICAL         {print_token("LOGICAL", T_LOGICAL);return T_LOGICAL;}
CHARACTER       {print_token("CHARACTER", T_CHARACTER);return T_CHARACTER;}
COMPLEX         {print_token("COMPLEX", T_COMPLEX);return T_COMPLEX;}
RECORD          {print_token("RECORD", T_RECORD);return T_RECORD;}
ENDREC          {print_token("ENDREC", T_ENDREC);return T_ENDREC;}
LIST            {print_token("LIST", T_LIST);return T_LIST;}
DATA            {print_token("DATA", T_DATA);return T_DATA;}
CONTINUE        {print_token("CONTINUE", T_CONTINUE);return T_CONTINUE;}
GOTO            {print_token("GOTO", T_GOTO);return T_GOTO;}
CALL            {print_token("CALL", T_CALL);return T_CALL;}
READ            {print_token("READ", T_READ);return T_READ;}
WRITE           {print_token("WRITE", T_WRITE);return T_WRITE;}
NEW             {print_token("NEW", T_NEW);return T_NEW;}
LENGTH          {print_token("LENGTH", T_LENGTH);return T_LENGTH;}
IF              {print_token("IF", T_IF);return T_IF;}
THEN            {print_token("THEN", T_THEN);return T_THEN;}
ELSE            {print_token("ELSE", T_ELSE);return T_ELSE;}
ENDIF           {print_token("ENDIF", T_ENDIF);return T_ENDIF;}
DO              {print_token("DO", T_DO);return T_DO;}
ENDDO           {print_token("ENDDO", T_ENDDO);return T_ENDDO;}
STOP            {print_token("STOP", T_STOP);return T_STOP;}
RETURN          {print_token("RETURN", T_RETURN);return T_RETURN;}

0|{digitn}{digit}*|{digit}                                      {print_token("INTEGER CONSTANT", T_ICONST);return T_ICONST;}
0B1[01]*|0H{hex_digitn}{hex_digit}*                             {print_token("INTEGER CONSTANT", T_ICONST);return T_ICONST;}
(0|{digitn}{digit}*)?"."(0*{digitn}+{digit}*|0)                 {print_token("REAL CONSTANT", T_RCONST);return T_RCONST;}                                    

"."("TRUE"|"FALSE")"."          {print_token("LOGICAL CONSTANT", T_LCONST);return T_LCONST;}
\'.?\'|\'\\[nftrbv]\'           {print_token("CHARACTER CONSTANT", T_CCONST);return T_CCONST;}
\".*((\\\n)?.*)*\"              {print_token("STRING CONSTANT", T_SCONST);return T_SCONST;}
"."OR"."                        {print_token("OR OPERATOR", T_OROP);return T_OROP;}
"."AND"."                       {print_token("AND OPERATOR", T_ANDOP);return T_ANDOP;}
"."NOT"."                       {print_token("NOT OPERATOR", T_NOTOP);return T_NOTOP;}
"."(GT|GE|LT|LE|EQ|NE)"."       {print_token("RELATIONAL OPERATOR", T_RELOP);return T_RELOP;}
AD*|D+|CD+R                     {print_token("LISTFUNC", T_LISTFUNC);return T_LISTFUNC;}
"+"|"-"                         {print_token("ADDITION OPERATOR", T_ADDOP);return T_ADDOP;}
"*"                             {print_token("MULTIPLICATION OPERATOR", T_MULOP);return T_MULOP;}
"/"                             {print_token("DIVISION OPERATOR", T_DIVOP);return T_DIVOP;}
"**"                            {print_token("POWER OPERATOR", T_POWEROP);return T_POWEROP;}
"("                             {print_token("LEFT PARENTHESES SYMBOL", T_LPAREN);return T_LPAREN;}
")"                             {print_token("RIGHT PARENTHESSES SYMBOL", T_RPAREN);return T_RPAREN;}
","                             {print_token("COMMA SYMBOL", T_COMMA);return T_COMMA;}
"="                             {print_token("ASSIGN SYMBOL", T_ASSIGN);return T_ASSIGN;}
"."                             {print_token("DOT SYMBOL", T_DOT);return T_DOT;}
":"                             {print_token("COLON SYMBOL", T_COLON);return T_COLON;}
"["                             {print_token("LEFT BRACKET SYMBOL", T_LBRACK);return T_LBRACK;}
"]"                             {print_token("RIGHT BRACKET SYMBOL", T_RBRACK);return T_RBRACK;}
\$.*                            {print_token("COMMENT LINE", T_COMMENT);return T_COMMENT;}

{alpha}{alphanum}*|_{alpha}{alphanum}*(_{alphanum}+)?_       {return T_ID;}

\n                              {lines++;}
{wh}+                           {}
.                               {printf("\e[0;32m\e[0;31mError:\e[0;37m %d: unidentified character: %s\n", lines, yytext);errors++;}
%%

int main(int argc, char* argv[]){

    int token;
    yylineno = 0;

    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if (yyin == NULL){
            fprintf(stderr, "Could not open file...exiting\n"); return -1;
        }
    }
    
    do{
        token = yylex();
    } while(token != 0);
    
    if(errors > 0){
        printf("\e[0;31mErrors: \e[0;37m%d\n", errors);
    }
    else{
        printf("Successful lectical analysis\n");
    }
    fclose(yyin);
    yyterminate();
}

int strtonum(char *str){
    if(str[0] != 0){
        switch(str[1]){
            case 'H':{
                printf("HEX Number\n");
                return strtohex(str);
            }
            case 'B':{
                printf("BIN Number\n");
                return strtobin(str);
            }
        }
    }
    else{
        return strtoint(str);
    }
    errors++;

    fprintf(stderr, "%s: invalid number format\n\n", str);
    return -1;
}

int strtoint(char *str){
    printf("|-INTEGER: %s\n", str);
    return atoi(str);
}

int strtohex(char *str){
    printf("|-HEX: %s\n", str);
    return (int)strtol(&str[2], NULL, 16);
}

int strtobin(char *str){
    printf("|-BINARY: %s\n", str);
    return (int)strtol(&str[2], NULL, 2);
}

void print_token(char* token_label, int token_id) {
    printf("\e[0;32m%s : \e[0;37m%d\n|-%s: %s\n", token_label, token_id, token_label, yytext);
}
