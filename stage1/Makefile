all: lex

lex: lex.yy.c hash_table.c hash_table.h
	gcc -o lex lex.yy.c hash_table.c

hash: hash_table.c hash_table.h 
	gcc hash_table.c -o hash

lex.yy.c: lectical.l
	flex lectical.l

reload: clean all

test: lex
	./lex test1.f
	./lex test2.f

clean:
	rm lex.yy.c lex