@all: 
	lex compiler.l
	gcc lex.yy.c -o compiler -ll
	./compiler code.txt
	python3 syntax-calc.py tokens.out
@clean:
	rm -rf *.c
	rm -rf compiler
	rm -rf graph.txt
	rm -rf *.out
