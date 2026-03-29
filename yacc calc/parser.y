%{
#include <stdio.h>
int yylex();
void yyerror(const char *);
%}

%token NUM
%left '+' '-'
%left '*' '/'

%%
S: E '\n' { printf("Answer: %d\n", $1); };

E: E'+'E { $$=$1+$3; }
 | E'-'E { $$=$1-$3; }
 | E'*'E { $$=$1*$3; }
 | E'/'E { $$=$1/$3; }
 | NUM
 ;
%%

int main(){ yyparse(); }

void yyerror(const char *s){
    printf("Error\n");
}

/*
 sudo install flex bison gcc
 and we need lex.l file too along with this 
 <<< main >>>
 
yacc -d parser.y
lex lex.l
gcc y.tab.c lex.yy.c -o parser
./parser

 then input... ctrl + D after finishing
*/
