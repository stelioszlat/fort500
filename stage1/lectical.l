
%{
    #include "keywords.h"
    // #include "syntactical.tab.h"
    #include <string.h>
    #include "hash_table.h"
    // int chars = 0;
    // int words = 0;
    int lines = 1;
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
wh                 [ \t]

%option caseless
%option noyywrap
%% 

FUNCTION        {printf("\e[0;32mFUNCTION: \e[0;37m%d\n", T_FUNCTION);return T_FUNCTION;}
SUBROUTINE      {printf("\e[0;32mSUBOUTINE: \e[0;37m%d\n", T_SUBROUTINE);return T_SUBROUTINE;}
END             {printf("\e[0;32mEND: \e[0;37m%d\n", T_END);return T_END;}
INTEGER         {printf("\e[0;32mINTEGER: \e[0;37m%d\n", T_INTEGER);return T_INTEGER;}
REAL            {printf("\e[0;32mREAL: \e[0;37m%d\n", T_REAL);return T_REAL;}
LOGICAL         {printf("\e[0;32mLOGICAL: \e[0;37m%d\n", T_LOGICAL);return T_LOGICAL;}
CHARACTER       {printf("\e[0;32mCHARACTER: \e[0;37m%d\n", T_CHARACTER);return T_CHARACTER;}
RECORD          {printf("\e[0;32mRECORD: \e[0;37m%d\n", T_RECORD);return T_RECORD;}
ENDREC          {printf("\e[0;32mENDREC: \e[0;37m%d\n", T_ENDREC);return T_ENDREC;}
DATA            {printf("\e[0;32mDATA: \e[0;37m%d\n", T_DATA);return T_DATA;}
CONTINUE        {printf("\e[0;32mCONTINUE: \e[0;37m%d\n", T_CONTINUE);return T_CONTINUE;}
GOTO            {printf("\e[0;32mGOTO: \e[0;37m%d\n", T_GOTO);return T_GOTO;}
CALL            {printf("\e[0;32mCALL: \e[0;37m%d\n", T_CALL);return T_CALL;}
READ            {printf("\e[0;32mREAD: \e[0;37m%d\n", T_READ);return T_READ;}
WRITE           {printf("\e[0;32mWRITE: \e[0;37m%d\n", T_WRITE);return T_WRITE;}
IF              {printf("\e[0;32mIF: \e[0;37m%d\n", T_IF);return T_IF;}
THEN            {printf("\e[0;32mTHEN: \e[0;37m%d\n", T_THEN);return T_THEN;}
ELSE            {printf("\e[0;32mELSE: \e[0;37m%d\n", T_ELSE);return T_ELSE;}
ENDIF           {printf("\e[0;32mENDIF: \e[0;37m%d\n", T_ENDIF);return T_ENDIF;}
DO              {printf("\e[0;32mDO: \e[0;37m%d\n", T_DO);return T_DO;}
ENDDO           {printf("\e[0;32mENDO: \e[0;37m%d\n", T_ENDO);return T_ENDO;}
STOP            {printf("\e[0;32mSTOP: \e[0;37m%d\n", T_STOP);return T_STOP;}
RETURN          {printf("\e[0;32mRETURN: \e[0;37m%d\n", T_RETURN);return T_RETURN;}

0                                                              {printf("\e[0;32mINTEGER CONSTANT: \e[0;37m%d\n|-NUMERICAL VALUE: %s\n", T_ICONST, yytext);yymore();return T_ICONST;}
{digitn}{digit}*|{digit}                                     {printf("\e[0;32mINTEGER CONSTANT: \e[0;37m%d\n|-NUMERICAL VALUE: %s\n", T_ICONST, yytext);return T_ICONST;}
0B1[01]*|0H{hex_digitn}{hex_digit}*                           {printf("\e[0;32mINTEGER CONSTANT: \e[0;37m%d\n|-NUMERICAL VALUE: %d\n", T_ICONST, strtonum(yytext));return T_ICONST;}
(0|{digitn}{digit}*)?"."(0*{digitn}+{digit}*|0)                 {printf("\e[0;32mREAL CONSTANT: \e[0;37m%d\n|-NUMERICAL VALUE: %lf\n", T_RCONST,strtod(yytext,NULL));return T_RCONST;}                                    

"."("TRUE"|"FALSE")"."           {printf("\e[0;32mLOGICAL CONSTANT: \e[0;37m%d\n|-CONSTANT VALUE: %s\n", T_LCONST, yytext);return T_LCONST;}
\'.\'|\'\\[nftrbv]\'            {printf("\e[0;32mCHARACTER CONSTANT: \e[0;37m%d\n|-CONSTANT VALUE: %s\n", T_CCONST, yytext);return T_CCONST;}
\".*\"                          {printf("\e[0;32mSTRING CONSTANT: \e[0;37m%d\n", T_SCONST);return T_SCONST;}
"."OR"."                        {printf("\e[0;32mOR OPERATOR: \e[0;37m%d\n", T_OROP);return T_OROP;}
"."AND"."                       {printf("\e[0;32mAND OPERATOR: \e[0;37m%d\n", T_ANDOP);return T_ANDOP;}
"."NOT"."                       {printf("\e[0;32mNOT OPERATOR: \e[0;37m%d\n", T_NOTOP);return T_NOTOP;}
"."(GT|GE|LT|LE|EQ|NE)"."       {printf("\e[0;32mRELATIONAL OPERATOR: \e[0;37m%d\n", T_RELOP);return T_RELOP;}
"+"|"-"                         {printf("\e[0;32mADDITION OPERATOR: \e[0;37m%d\n", T_ADDOP);return T_ADDOP;}
"*"                             {printf("\e[0;32mMULTIPLICATION OPERATOR: \e[0;37m%d\n", T_MULOP);return T_MULOP;}
"/"                             {printf("\e[0;32mDIVISION OPERATOR: \e[0;37m%d\n", T_DIVOP);return T_DIVOP;}
"**"                            {printf("\e[0;32mPOWER OPERATOR: \e[0;37m%d\n", T_POWEROP);return T_POWEROP;}
"("                             {printf("\e[0;32mLEFT PARENTHESES SYMBOL: \e[0;37m%d\n", T_LPAREN);return T_LPAREN;}
")"                             {printf("\e[0;32mRIGHT PARENTHESES SYMBOL: \e[0;37m%d\n", T_RPAREN);return T_RPAREN;}
","                             {printf("\e[0;32mCOMMA SYMBOL: \e[0;37m%d\n", T_COMMA);return T_COMMA;}
"="                             {printf("\e[0;32mASSIGN SYMBOL : \e[0;37m%d\n", T_ASSIGN);return T_ASSIGN;}
":"                             {printf("\e[0;32mCOLON SYMBOL: \e[0;37m%d\n", T_COLON);return T_COLON;}
$.*                             {printf("\e[0;32mCOMMENT LINE: \e[0;37m%d\n", T_COMMENT);return T_COMMENT;}

{alpha}({alphanum}*|{alphanum}"_"{alphanum}|"_")*       {printf("\e[0;32mID : \e[0;37m%d\n|-IDENTIFIER VALUE: %s\n", T_ID, yytext);hashtbl_insert(table, yytext, lines, 0);return T_ID;}

\n                              {lines++;}
{wh}+                           {}
.                               {printf("\e[0;32m\e[0;31mError:\e[0;37m %d: unidentified character\n", lines);errors++;}
%%

int main(int argc, char* argv[]){

    int token;
    yylineno = 1;

    if(!(table = hashtbl_create(10, NULL))){
        printf("Could not create table\n");
        exit(-1);
    }

    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if (yyin == NULL){
            fprintf(stderr, "Could not open file...exiting\n"); return -1;
        }
    }
    
    do{
        token = yylex();
        // hashtbl_get(table, 0);
    }while(token != 0);
    
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
