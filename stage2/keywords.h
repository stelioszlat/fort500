#define T_EOF 0

#define T_FUNCTION 1
#define T_SUBROUTINE 2
#define T_END 3
#define T_INTEGER 4
#define T_REAL 5
#define T_LOGICAL 6
#define T_CHARACTER 7
#define T_COMPLEX 8
#define T_RECORD 9
#define T_ENDREC 10
#define T_LIST 11
#define T_DATA 12
#define T_CONTINUE 13
#define T_GOTO 14
#define T_CALL 15
#define T_READ 16
#define T_WRITE 16
#define T_NEW 17
#define T_LENGTH 18
#define T_IF 19
#define T_THEN 20
#define T_ELSE 21
#define T_ENDIF 22
#define T_DO 23
#define T_ENDO 24
#define T_STOP 25
#define T_RETURN 26

#define T_ICONST 27
#define T_RCONST 28
#define T_LCONST 29
#define T_CCONST 30

#define T_OROP 31
#define T_ANDOP 32
#define T_NOTOP 33
#define T_RELOP 34
#define T_LISTFUNC 35 
#define T_ADDOP 36
#define T_MULOP 37
#define T_DIVOP 38
#define T_POWEROP 39

#define T_SCONST 40
#define T_LPAREN 41
#define T_RPAREN 42
#define T_COMMA 43
#define T_ASSIGN 44
#define T_DOT 45
#define T_COLON 46
#define T_LBRACK 47
#define T_RBRACK 48

#define T_COMMENT 49 
#define T_ID 50

int strtobin(char *str);
int strtohex(char *str);
int strtoint(char *str);
int strtonum(char *str);