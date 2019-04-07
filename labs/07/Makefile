@all:
	yacc -d compiler.y
	lex compiler.l
	gcc lex.yy.c y.tab.c -o tree
	./tree code.txt
clean:
	rm -rf *.c
	rm -rf *.h