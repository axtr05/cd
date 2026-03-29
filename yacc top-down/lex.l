%{
#include "y.tab.h"
%}

%%
[a-zA-Z][a-zA-Z0-9]* { return ID; }
[+*()]               { return yytext[0]; }
[ \t\n]              ;
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
