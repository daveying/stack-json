CC  	= gcc -g
LEX		= flex -i -I
YACC	= bison -d -y
ALLOCA	=

expr: expr.y expr.lex
	$(YACC) expr.y
	$(LEX)  expr.lex
	$(CC) -o expr lex.yy.c y.tab.c $(ALLOCA) -ll -lm

test: expr test.txt
	./expr test.txt

clean:
	rm expr lex.yy.c y.tab.c y.tab.h
