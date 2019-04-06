%{
#include <stdio.h>
#include "y.tab.h"
extern int yylval;
%}
%%
p                          { yylval = yytext; return PRINT; }
i                          { yylval = yytext; return INTDCL; }
f                          { yylval = yytext; return FLOATDCL; }
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
[0-9]+				{ yylval = atoi(yytext); return NUMBER; }
[0-9]+[.][0-9]+	    { yylval = atoi(yytext); return NUMBER; }

[//].*\n            //ignore
[ \t]               //ignore
[a-z]               { return ID; }
^\n                 //ignore
\n                  { return NEWLINE; }
<<EOF>>             return eof; 
.                   return yytext[0];

%%