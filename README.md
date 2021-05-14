AM: 2116\*\*0
FORT500

A.Lectical Rules
KEYWORDS:
FUNCTION SUBROUTINE END INTEGER REAL LOGICAL CHARACTER RECORD ENDREC DATA CONTINUE GOTO CALL READ WRITE IF THEN ELSE ENDIF DO ENDO STOP RETURN

ID:
anything
_anything
\_anyth_ing
anything_

ICONST:
0
1234567890
OH1234567890ABCDEF
OB10

RCONST:
0.0
1234567890.1234567890E+-1234567890
0H1234567890ABCDEF.1234567890ABCDEF
0B10.10

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

STRING:
"CCONST\*"

LPAREN: (
RPAREN: )
COMMA: ,
ASSIGN: =
COLON: :
EOF: <EOF>

COMMENTS: \$ comment until end of line

B.Syntactical Rules
program -> body END subprograms

body -> declarations statements

declarations -> declarations type vars
| declarations RECORD fields ENDREC vars
| declarations DATA vals
| ε

type -> INTEGER | REAL | LOGICAL | CHARACTER

vars -> vars COMMA undef_variable
| undef_variable

undef_variable -> ID LPAREN dims RPAREN
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

values -> values COMMA value
| value

value -> repeat MULOP ADDOP constant
| repeat MULOP constant
| repeat MULOP STRING
| ADDOP constant
| constant
| STRING

repeat -> ICONST | ε

constant -> ICONST | RCONST | LCONST | CCONST

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

variable -> variable COLON ID
| variable LPAREN expressions RPAREN

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
| constant
| LPAREN expression RPAREN

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
| SUBROUTINE ID LPAREN formal_parameters RPAREN
| SUBROUTINE ID

formal_parameters -> type vars COMMA formal_parameters
| type vars
