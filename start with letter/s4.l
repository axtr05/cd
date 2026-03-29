%{
#include <stdio.h>
%}

%%
^[a-zA-Z][a-zA-Z0-9]*\n   { printf("valid\n"); }
.*\n                      { printf("invalid\n"); }
%%

int main() {
    yylex();
    return 0;
}

int yywrap() { return 1; }

/*
 sudo install flex bison gcc
 already ahve the c file for this so lex is optional
  <<< main >>>
  
 flex s4.l
 gcc lex.yy.c -o s4
 ./s4
then input... ctrl + D after finishing
*/
