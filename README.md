AM: 2116\*\*0
FORT200

A.Lectical Rules
KEYWORDS:
FUNCTION SUBROUTINE END INTEGER REAL LOGICAL CHARACTER COMPLEX RECORD ENDREC LIST DATA CONTINUE GOTO CALL READ WRITE NEW LENGTH IF THEN ELSE ENDIF DO ENDDO STOP RETURN

ID:
anything
_anything
\_anyth_ing
anything_

ICONST:
0
1234567890
Ox1234567890ABCDEF
Ob10

RCONST:
0.0
1234567890.1234567890E+-1234567890
0x1234567890ABCDEF.1234567890ABCDEF
0b10.10

LCONST:
.TRUE.
.FALSE.

CCONST:
'32-126'
'\nftrbv'

OROP: .OR.

ANDOP: .AND.

NOTOP: .NOT.

RELOP: .GT. .GE. .LT. .LE. .EQ. .NE.

ADDOP: + - 

MULOP: *

DIVOP: /

POWEROP: **

LISTFUNC:
AD* | D+ | CD+R

STRING:
"CCONST\*"

LPAREN: (
RPAREN: )
COMMA: ,
ASSIGN: =
DOT: .
COLON: :
LBRACK: [
RBRACK: ]
EOF: <EOF>

COMMENTS: \$ comment until end of line

B.Syntactical Rules
program -> body END subprograms

body -> declarations statements

declarations -> declarations type vars
| declarations RECORD fields ENDREC vars
| declarations DATA vals
| ε

type -> INTEGER | REAL | LOGICAL | CHARACTER | COMPLEX

vars -> vars COMMA undef_variable
| undef_variable

undef_variable -> LIST undef_variable
| ID LPAREN dims RPAREN
| ID

dims -> dims COMMA dim
| dim

dim -> ICONST | ID

fields -> fields field
| field

field -> type vars
| RECORD fields ENDREC vars

vals -> vals COMMA ID value_list
| ID value_list

value_list -> DIVOP values DIVOP

values -> values COMMA value
| value

value -> sign constant
| STRING

sign -> ADDOP
| ε

constant -> simple_constant
| complex_constant

simple_constant -> ICONST | RCONST | LCONST | CCONST

complex_constant -> LPAREN RCONST COLON sign RCONST RPAREN
  
statements -> statements labeled_statement
| labeled_statement

labeled_statement -> label statement
| statement

label -> ICONST

statement -> simple_statement
| compound_statement

simple_statement -> assignment
| goto_statement
| if_statement
| subroutine_call
| io_statement
| CONTINUE
| RETURN
| STOP

assignment -> variable ASSIGN expression
| variable ASSIGN STRING

variable -> variable DOT ID
| variable LPAREN expressions RPAREN
| LISTFUNC LPAREN expression RPAREN
| ID

expressions -> expressions COMMA expression
| expression

expression -> expression OROP expression
| expression ANDOP expression
| expression RELOP expression
| expression ADDOP expression
| expression MULOP expression
| expression DIVOP expression
| expression POWEROP expression
| NOTOP expression
| ADDOP expression
| variable
| simple_constant
| LENGTH LPAREN expression RPAREN
| NEW LPAREN expression RPAREN
| LPAREN expression RPAREN
| LPAREN expression COLON expression RPAREN
| listexpression


listexpression -> LBRACK expressions RBRACK
| LBRACK RBRACK 

goto_statement -> GOTO label
| GOTO ID COMMA LPAREN labels RPAREN

labels -> labels COMMA label
| label

if_statement -> IF LPAREN expression RPAREN label COMMA label COMMA label
| IF LPAREN expression RPAREN simple_statement

subroutine_call -> CALL variable

io_statement -> READ read_list
| WRITE write_list

read_list -> read_list COMMA read_item
| read_item

read_item -> variable
| LPAREN read_list COMMA ID ASSIGN iter_space RPAREN

iter_space -> expression COMMA expression step

step -> COMMA expression
| ε

write_list -> write_list COMMA write_item
| write_item

write_item -> expression
| LPAREN write_list COMMA ID ASSIGN iter_space RPAREN
| STRING

compound_statement -> branch_statement
| loop_statement

branch_statement -> IF LPAREN expression RPAREN THEN body tail

tail -> ELSE body ENDIF
| ENDIF

loop_statement -> DO ID ASSIGN iter_space body ENDDO

subprograms -> subprograms subprogram
| ε

subprogram -> header body END

header -> type FUNCTION ID LPAREN formal_parameters RPAREN
| LIST FUNCTION ID LPAREN formal_parameters RPAREN
| SUBROUTINE ID LPAREN formal_parameters RPAREN
| SUBROUTINE ID

formal_parameters -> type vars COMMA formal_parameters
| type vars
