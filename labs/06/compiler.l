%{
#include <stdio.h>
void printToken(char c[], int comment);
FILE *fo;
%}

%%
p                          printToken("print", 0);
f                          printToken("floatdcl", 0);
i                          printToken("intdcl", 0);
[0-9]+                     printToken("inum", 0);
[0-9]+"."[0-9]*            printToken("fnum", 0);
[a-eg-hj-oq-z]+            printToken("id", 0);
"+"                        printToken("sum", 0);
"-"                        printToken("minus", 0);
"*"                        printToken("multiplication", 0);
"/"                        printToken("division", 0);
"="                        printToken("assign", 0);
[//].*\n                   printToken("\ncomment", 1);
[0-9]+\n                   printToken("inum @", 1);
[0-9]+"."[0-9]*\n          printToken("fnum @", 1);
[a-eg-hj-oq-z]+\n          printToken("id @", 1);
%%

int main(int argc, char **argv) {
    FILE    *fd;
    fo = fopen("tokens.out", "w");
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
    fclose(fo);
    return (0);
}

void printToken( char c[], int comment) {
    if(comment) {
        fprintf(fo, "%s\n", c);    
    } else {
        fprintf(fo, "%s ", c);
    }
}