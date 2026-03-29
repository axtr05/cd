// write recursive descent parser for the grammar. E->E+T  E->T  T->T*F  T->F  F->(E)/id.

#include<stdio.h>
#include<stdlib.h>

int i = 0;
char in[100];
void e(); void e1(); void t(); void t1(); void f();
void match(char c) {
    if(in[i] == c) i++;
    else {
        printf("\ninvalid");
        exit(0);
    }
}
void e() {
    t();
    e1();
}
void e1() {
    if(in[i] == '+') {
        match('+');
        t();
        e1();
    }
}
void t() {
    f();
    t1();
}
void t1() {
    if(in[i] == '*') {
        match('*');
        f();
        t1();
    }
}
void f() {
    if(in[i] == '(') {
        match('(');
        e();
        match(')');
    }
    else if(in[i] == 'i' && in[i+1] == 'd') {
        match('i');
        match('d');
    }
    else {
        printf("\ninvalid");
        exit(0);
    }
}
int main() {
    printf("input : ");
    scanf("%s",in);
    e();
    if(in[i] == '\0') printf("\nvalid");
    else printf("\ninvalid");
    return 0;
}

