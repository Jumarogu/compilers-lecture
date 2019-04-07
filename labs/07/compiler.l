%{
#include <stdio.h>
#include "y.tab.h"
extern int yylval;
%}
%%
[/][/].*\n                   //ignore
[ \t]                      //ignore
p                          {return PRINTDCL; }
i                          {return INTDCL; }
f                          {return FLOATDCL; }
[0-9]+				       {return INUMBER; }
[0-9]+[.][0-9]+	           {return FNUMBER; }
[a-eg-hj-oq-z]+            { return ID; }
.*\n                       { return AT; }
"+"                        { yylval = (yytext); return PLUS; }
"-"                        { yylval = (yytext); return SUBSRACT; }
"*"                        { yylval = (yytext); return TIMES; }
"/"                        { yylval = (yytext); return DIVIDE; }
"="                        { yylval = (yytext); return ASSIGN; }
<<EOF>>                    { return END;} 
%%
int yywrap (void)
{return 1;} 