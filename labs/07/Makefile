@all:
	yacc -d simplecalc.y
	lex simplecalc.l
	gcc y.tab.c lex.yy.c -ly -ll -o simplecalc
	./simplecalc < simple-input.txt