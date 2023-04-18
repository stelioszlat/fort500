
%union{
    int integerval;
    double doubleval;
    char *stringval;
}

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include "hash_table.h"

    extern int yylex();
    extern int yytext;
    extern FILE *yyin;
    extern void yyterminate();

    extern HASHTBL *table;

    int scope = 0;
    extern int lines;
    extern int errors;

    void yyerror(const char *message);
%}


%token <stringval>  T_FUNCTION;
%token <stringval>  T_SUBROUTINE;
%token <stringval>  T_END;
%token <stringval>  T_INTEGER;
%token <stringval>  T_REAL;
%token <stringval>  T_LOGICAL;
%token <stringval>  T_STRING;
%token <stringval>  T_CHARACTER;
%token <stringval>  T_COMPLEX;
%token <stringval>  T_RECORD;
%token <stringval>  T_ENDREC;
%token <stringval>  T_LIST;
%token <stringval>  T_DATA;
%token <stringval>  T_CONTINUE;
%token <stringval>  T_GOTO;
%token <stringval>  T_CALL;
%token <stringval>  T_READ;
%token <stringval>  T_WRITE;
%token <stringval>  T_NEW;
%token <stringval>  T_LENGTH;
%token <stringval>  T_IF;
%token <stringval>  T_THEN;
%token <stringval>  T_ELSE;
%token <stringval>  T_ENDIF;
%token <stringval>  T_DO;
%token <stringval>  T_ENDDO;
%token <stringval>  T_STOP;
%token <stringval>  T_RETURN;

%token <integerval> T_ICONST;
%token <doubleval>  T_RCONST;
%token <stringval>  T_LCONST;
%token <stringval>  T_CCONST;
%token <stringval>  T_SCONST;
%token <stringval>  T_OROP;
%token <stringval>  T_ANDOP;
%token <stringval>  T_NOTOP;
%token <stringval>  T_RELOP;
%token <stringval>  T_LISTFUNC;
%token <stringval>  T_ADDOP;
%token <stringval>  T_MULOP;
%token <stringval>  T_DIVOP;
%token <stringval>  T_POWEROP;
%token <stringval>  T_LPAREN;
%token <stringval>  T_RPAREN;
%token <stringval>  T_COMMA;
%token <stringval>  T_ASSIGN;
%token <stringval>  T_DOT;
%token <stringval>  T_COLON;
%token <stringval>  T_LBRACK;
%token <stringval>  T_RBRACK;

%token <stringval>  T_COMMENT;
%token <stringval>  T_ID;

%left   T_COMMA
%left   T_COLON
%right  T_ASSIGN
%left   T_OROP 
%left   T_ANDOP 
%left   T_RELOP
%left   T_ADDOP
%left   T_MULOP 
%left   T_DIVOP
%left   T_POWEROP
%left   T_NOTOP
%left   T_LPAREN
%left   T_RPAREN
%left   T_LBRACK
%left   T_RBRACK

%nonassoc T_ELSE 
%error-verbose

%start program

%%

program:				body T_END subprograms
;
body:					declarations statements 
;
declarations:	        declarations type vars
                        |   declarations T_RECORD fields T_ENDREC vars
                        |   declarations T_DATA vals 
                        |   /* empty */ {}
;
type:					T_INTEGER                                     
                        |   T_REAL                                    
                        |   T_LOGICAL                                 
                        |   T_CHARACTER
                        |   T_COMPLEX                              
;
vars:					vars T_COMMA undef_variable
    					|   undef_variable
;    
undef_variable:		    T_LIST undef_variable
                        |   T_ID T_LPAREN dims T_RPAREN                                     {/*hashtbl_insert(table, $1, lines, scope);*/}     
                		|   T_ID                                                            {/*hashtbl_insert(table, $1, lines, scope);*/}
;
dims:					dims T_COMMA dim
                        |   dim
;
dim:				    T_ICONST                                                            {printf("INTEGER VALUE: %s\n", $1);}
                        |   T_ID                                                            {/*hashtbl_insert(table, $1, lines, scope);*/}
;
fields:					fields field
        				|   field
;
field:					type vars
    					|   T_RECORD fields T_ENDREC vars
;    
vals:					vals T_COMMA T_ID value_list                                        {/*hashtbl_insert(table, $2, lines, scope);*/}               
    					|   T_ID value_list                                                 {/*hashtbl_insert(table, $1, lines, scope);*/}
;
value_list:				T_DIVOP values T_DIVOP
;
values:					values T_COMMA value
    					|   value
;    
value:					sign constant
    					|   T_STRING                                                        {/*printf("STRING VALUE: %s\n", $1);*/}                            
;
sign:                   T_ADDOP
                        |   /* empty */ {}
;
constant:               simple_constant
                        |   complex_constant
;
simple_constant:        T_ICONST                                                            {printf("INTEGER CONSTANT: %d\n", $1);}
                        |   T_RCONST                                                        {printf("REAL CONSTANT: %s\n", $1);}
                        |   T_LCONST                                                        {printf("LOGICAL CONSTANT: %s\n", $1);}
                        |   T_CCONST                                                        {printf("CHARACTER CONSTANT: %s\n", $1);}
;
complex_constant:       T_LPAREN T_RCONST T_COLON sign T_RCONST T_RPAREN
;
statements:			    statements labeled_statement
                        |   labeled_statement
;
labeled_statement:		label statement
                        |   statement
;
label:					T_ICONST                                
;
statement:				simple_statement
                        |   compound_statement
;
simple_statement:		assignment
                        |   goto_statement
                        |   if_statement
                        |   subroutine_call
                        |   io_statement
                        |   T_CONTINUE
                        |   T_RETURN
                        |   T_STOP
;
assignment:				variable T_ASSIGN expression
                        |   variable T_ASSIGN T_STRING                    
;
variable:				variable T_DOT T_ID                                                           
                        |   variable T_LPAREN expressions T_RPAREN      
                        |   T_ID                                                                        
;     
expressions:				expressions T_COMMA expression
                        |   expression
;        
expression:				expression T_OROP expression
                        |   expression T_ANDOP expression
                        |   expression T_RELOP expression
                        |   expression T_ADDOP expression
                        |   expression T_MULOP expression
                        |   expression T_DIVOP expression
                        |   expression T_POWEROP expression
                        |   T_NOTOP expression
                        |   T_ADDOP expression
                        |   variable
                        |   simple_constant
                        |   T_LENGTH T_LPAREN expression T_RPAREN
                        |   T_NEW T_LPAREN expression T_RPAREN
                        |   T_LPAREN expression T_RPAREN
                        |   T_LPAREN expression T_COLON expression T_RPAREN
                        |   listexpression
;
listexpression:         T_LBRACK expressions T_RBRACK
                        |   T_LBRACK T_RBRACK
goto_statement:			T_GOTO label
                        |   T_GOTO T_ID T_COMMA T_LPAREN labels T_RPAREN                                
;            
labels:					labels T_COMMA label
                        |   label
;    
if_statement:			T_IF T_LPAREN expression T_RPAREN label T_COMMA label T_COMMA label
                        |   T_IF T_LPAREN expression T_RPAREN simple_statement
;
subroutine_call:			T_CALL variable
;
io_statement:			T_READ read_list
                        |   T_WRITE write_list
;    
read_list:	    		read_list T_COMMA read_item
        				|   read_item
;
read_item:				variable
                    |   T_LPAREN read_list T_COMMA T_ID T_ASSIGN iter_space T_RPAREN   
;
iter_space:				expression T_COMMA expression step
;
step:					T_COMMA expression
                        |   /*  empty */    {}
;    
write_list:				write_list T_COMMA write_item
                        |   write_item
; 
write_item:				expression
                        |   T_LPAREN write_list T_COMMA T_ID T_ASSIGN iter_space T_RPAREN               
;
compound_statement:		branch_statement
                        |   loop_statement
;
branch_statement:		T_IF T_LPAREN expression T_RPAREN T_THEN body tail
;
tail:					T_ELSE body T_ENDIF
                        |   T_ENDIF
;
loop_statement:			T_DO T_ID T_ASSIGN iter_space body T_ENDDO                                       
;
subprograms:			subprograms subprogram
                        |   /* empty */ {}
; 
subprogram:				header body T_END
;
header:					type T_FUNCTION T_ID T_LPAREN formal_parameters T_RPAREN
                        |   T_LIST T_FUNCTION T_ID T_LPAREN formal_parameters T_RPAREN                      
                        |   T_SUBROUTINE T_ID T_LPAREN formal_parameters T_RPAREN                       
                        |   T_SUBROUTINE T_ID                                                           
;
formal_parameters:		type vars T_COMMA formal_parameters
                        |   type vars
;

%%

int main(int argc, char *argv[]){

    int token;
    int yylineno = 0;

    if(!(table = hashtbl_create(10, NULL))){
        yyerror("failed to create hash table");
        exit(-1);
    }

    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if(yyin == NULL){
            yyerror("unable to find file");
            return -1;
        }
    }

    yyparse();

    hashtbl_get(table, scope);
    fclose(yyin);
    hashtbl_destroy(table);

    if(errors > 0){
        printf("Total errors: %d\n", errors);
        printf("Syntactical analysis failed!\n");
        return -1;
    }
    else{
        printf("Syntactical analysis successful!\n");
        return 0;
    }
}

void yyerror(const char *message){
    printf("Error in line %d: %s\n", lines, message);
    errors++;
}