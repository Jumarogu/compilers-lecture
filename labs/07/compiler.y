%{
#include <stdio.h>
%}
%start program
%token INUMBER FLOATDCL PRINTDCL INTDCL ID FNUMBER END
%token AT
%token PLUS TIMES DIVIDE SUBSRACT ASSIGN
%%

program: assign AT {printf("assign %s",$$);}
    | declaration {printf($$);}
    | print {printf("print");}
    | END {printf("END\n");return 0;}
    ;
assign: ID ASSIGN ID operation number {$$ = '';}
    | ID ASSIGN number
    ;
declaration: type ID {printf("%s ID", $1);}
    ;
print: PRINTDCL ID {printf("printdcl %s", $1);} 
    |  PRINTDCL number {printf("printdcl %s", $1);}
    ;
operation: PLUS number { printf("plus %s", $1);}
    | SUBSRACT number    { printf("substract %s", $1);}
    | TIMES   { printf("times %s", $1);}
    | DIVIDE   { printf("divide %s", $1);}
    ;
type: INTDCL {$$ = "intdlc";}
    | FLOATDCL {$$ = "floatdcl";}
    ;
number: INUMBER {$$ = "inum";}
    | FNUMBER {$$ = "fnumber";}
    ;
%%
int main(int argc, char **argv) {
    FILE    *fd;
    if (argc == 2)
    {
        if (!(fd = fopen(argv[1], "r")))
        {
            perror("Error: ");
            return (-1);
        }
        yyset_in(fd);
        yylex();
        fclose(fd);
    }
    else
        printf("Usage: a.out filename\n");
    return (0);
}