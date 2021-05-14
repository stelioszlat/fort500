all: lex

lex: lex.yy.c hash_table.c hash_table.h
	gcc -o lex lex.yy.c hash_table.c -ll

hash: hash_table.c hash_table.h 
	gcc hash_table.c -o hash

lex.yy.c: lectical.l
	flex lectical.l

reload: clean all

clean:
	rm test_lex lex.yy.c 