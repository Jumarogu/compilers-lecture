all:
	lex example0.l
	gcc lex.yy.c -o example0 -ll
	lex compiler.l
	gcc lex.yy.c -o compiler -ll

clean:
	rm -rf *.c
	rm -rf example0
	rm -rf example1
	rm -rf example2
	rm -rf example3
