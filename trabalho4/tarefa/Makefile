scanner: lex.yy.c
	gcc -o s lex.yy.c -ll
	
lex.yy.c: scanner.l
	lex scanner.l

clean:
	rm lex.yy.c scanner
