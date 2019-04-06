%{
#include <stdio.h>
char *graph;
%}
%start program
%token NUMBER FLOATDCL PRINTDCL INTDCL eof NEWLINE ID NUMBERF

%%

program: statement NEWLINE program
    | eof {printf("Validado\n");return 0;};
   
operators: '+'  
    | '-'   
    | '*'   
    | '/'   
    | '='   
    ;    
statement: ID                                   {printf("digraph D{ \n S-> ID }\n");}
    | FLOATDCL ID                               {printf("digraph D{ S-> FLOAT ID }\n");}
    | INTDCL ID                                 {printf("digraph D{ S-> INTDCL ID }\n");}
    | PRINTDCL ID                               {printf("digraph D{ S-> PRINTDCL ID }\n");}
    | ID operators NUMBER                       {printf("digraph D{ S-> ID OPERATORS NUMBER \n");}
    | ID operators ID operators NUMBER          {printf("S-> ID OPERATORS ID OPERATORS NUMBER\n");}
    | ID operators ID operators NUMBERF         {printf("S-> ID OPERATORS ID OPERATORS NUMBERF\n");}
    ;