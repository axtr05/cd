%{
#include <stdio.h>
%}

%%
int|float|if|else        { printf("%s -> Keyword\n", yytext); }
[0-9]+                  { printf("%s -> Number\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*  { printf("%s -> Identifier\n", yytext); }
[+\-*/=]                { printf("%s -> Operator\n", yytext); }
[ \t\n]+                ;
.                       { printf("%s -> Symbol\n", yytext); }
%%

int main(){ yylex(); }
int yywrap(){ return 1; }

/*
 sudo install flex bison gcc
 
 <<< main >>>
 
flex s2.l
gcc lex.yy.c -o s2
./s2
 then input... ctrl + D after finishing
*/
