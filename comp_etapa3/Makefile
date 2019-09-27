#
# UFRGS - Compiladores B - Marcelo Johann - 2009/2 - Etapa 1
#
# Makefile for single compiler call
# All source files must be included from code embedded in scanner.l
# In our case, you probably need #include "hash.c" at the beginning
# and #include "main.c" in the last part of the scanner.l
#

etapa3: y.tab.o lex.yy.o main.o hash_table.o
	gcc -o etapa3 y.tab.o lex.yy.o main.o hash_table.o -Wall
lex.yy.o: lex.yy.c
	gcc -c lex.yy.c -Wall
y.tab.o: y.tab.c
	gcc -c y.tab.c -Wall
hash.o: hash_table.c
	gcc -c hash.c -Wall
main.o: main.c lex.yy.c y.tab.c
	gcc -c main.c -Wall
y.tab.c: parser.y lex.yy.c
	yacc -d parser.y
lex.yy.c: scanner.l
	lex --header-file=lex.yy.h scanner.l

clean:
	rm lex.yy.c lex.yy.h y.tab.c y.tab.h etapa3 *.o