all: fort500

fort500:	lex.yy.c syntactical.tab.c syntactical.tab.h hash_table.o
	gcc -o fort500 syntactical.tab.c hash_table.o lex.yy.c -ll

lex.yy.c: lectical.l syntactical.tab.h
	flex lectical.l

syntactical.tab.c syntactical.tab.h: syntactical.y 
	bison -v -d syntactical.y 

hash_table.o: hash_table.c hash_table.h 
	gcc -o hash_table.o -c hash_table.c

clean:
	rm fort500 lex.yy.c syntactical.tab.h syntactical.tab.c syntactical.output
