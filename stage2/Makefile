all: fort200

fort200:	lex.yy.c syntactical.tab.c syntactical.tab.h hash_table.o
	gcc -o fort200 syntactical.tab.c hash_table.o lex.yy.c

lex.yy.c: lectical.l syntactical.tab.h
	flex lectical.l

syntactical.tab.c syntactical.tab.h: syntactical.y 
	bison -v -d syntactical.y 

hash_table.o: hash_table.c hash_table.h 
	gcc -o hash_table.o -c hash_table.c

test:
	./fort200 test1.f
	./fort200 test2.f

clean:
	rm fort200 lex.yy.c syntactical.tab.h syntactical.tab.c syntactical.output
