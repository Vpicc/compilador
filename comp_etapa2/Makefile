#
# UFRGS - Compiladores B - Marcelo Johann - 2009/2 - Etapa 1
#
# Makefile for single compiler call
# All source files must be included from code embedded in scanner.l
# In our case, you probably need #include "hash.c" at the beginning
# and #include "main.c" in the last part of the scanner.l
#

etapa1: y.tab lex.yy.c
	gcc -o etapa2 lex.yy.c
lex.yy.c: scanner.l
	lex scanner.l
y.tab:
	yacc -d parser.y

clean:
	rm lex.yy.c y.tab.c y.tab.h etapa2