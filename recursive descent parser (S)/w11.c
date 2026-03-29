// write recursive descent parser for the grammar. S->(L) S->a L->L, S L->S

#include<stdio.h>
#include<stdlib.h>

int i = 0;
char in[100];
void s(); void l();
void match(char c) {
    if(in[i] == c) i++;
    else {
        printf("\ninvalid");
        exit(0);
    }
}
void s() {
    if(in[i] == 'a') match('a');
    else if(in[i] == '(') {
        match('(');
        l();
        match(')');
    }
    else {
        printf("\ninvalid");
        exit(0);
    }
}
void l() {
    s();
    while(in[i] == ',') {
        match(',');
        s();
    }
}
int main() {
    printf("input : ");
    scanf("%s",in);
    s();
    if(in[i] == '\0') printf("\nvalid");
    else printf("\ninvalid");
    return 0;
}
