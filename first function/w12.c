// Write a C program to calculate the first function for the grammar.
//      E->E+T  E->T  T->T*F  T->F  F->(E)/id


#include <stdio.h>
#include <ctype.h>

char lhs[10], rhs[10][20];
int n, visited[26];
void first(char c){
    if(visited[c-'A']) return;
    visited[c-'A'] = 1;
    for(int i=0;i<n;i++){
        if(lhs[i]==c){
            if(!isupper(rhs[i][0])) printf("%c ",rhs[i][0]);
            else first(rhs[i][0]);
        }
    }
}
int main(){
    char c;
    printf("Enter number of productions: ");
    scanf("%d",&n);
    printf("Enter productions:\n");
    for(int i=0;i<n;i++)
        scanf(" %c = %s",&lhs[i],rhs[i]);
    printf("Enter symbol: ");
    scanf(" %c",&c);
    printf("FIRST(%c) = { ",c);
    first(c);
    printf("}\n");
}
