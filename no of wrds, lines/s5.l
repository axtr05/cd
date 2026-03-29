    %{
#include <stdio.h>
int w=0, l=0;
%}

%%
\n        { l++; }
[ \t]+    ;
[^ \t\n]+ { w++; }
%%

int main(int c, char *v[]) {
    if(c>1) yyin = fopen(v[1],"r");
    yylex();
    if(w) l++; 
    printf("Words=%d Lines=%d\n", w, l);
}
int yywrap() { return 1; }

/*
 sudo install flex bison gcc
 
 <<< main >>>
 
 flex s5.l
 gcc lex.yy.c -o s5
 ./s5
 then input... ctrl + D after finishing
*/
