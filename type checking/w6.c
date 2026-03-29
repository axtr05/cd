// Implement type checking.

#include<stdio.h>
#include<string.h>

char t1[20], t2[20], op;
int main() {
    printf("Enter type1 operator type2: ");
    scanf("%s %c %s", t1, &op, t2);
    if(!strcmp(t1,t2)) printf("Valid expression, result type = %s\n", t1);
    else if(!strcmp(t1,"int") && !strcmp(t2,"float") || !strcmp(t2,"int") && !strcmp(t1,"float"))
        printf("Valid expression, result type = float\n");
    else printf("Invalid expression\n");
    return 0;
}
