%{
#include <stdio.h>
int yylex();
void yyerror(const char *);
%}

%token ID
%left '+'
%left '*'

%%
E: E'+'T | T ;
T: T'*'F | F ;
F: '('E')' | ID ;
%%

int main(){
    if(yyparse()==0) printf("Valid\n");
}

void yyerror(const char *s){
    printf("Invalid\n");
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
