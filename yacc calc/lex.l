%{
#include "y.tab.h"
#include <stdlib.h>
%}

%%
[0-9]+      { yylval = atoi(yytext); return NUM; }
\n          return '\n';
[ \t]+      ;
.           return yytext[0];
%%

int yywrap(){ return 1; }

/*
 sudo install flex bison gcc
 and we need parser.y file too along with this 
 <<< main >>>
 
yacc -d parser.y
lex lex.l
gcc y.tab.c lex.yy.c -o parser
./parser

 then input... ctrl + D after finishing
*/
