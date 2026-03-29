// Develop a lexical analyzer to recognize a few patterns in c (ex. Identifiers, constants, comments, operators etc.)

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *kw[]={"int","float","if","else","while","return","char"};

int isKeyword(char *w){
    for(int i=0;i<7;i++)
        if(!strcmp(w,kw[i]))
            return 1;
    return 0;
}
int main(){
    int c;
    char w[50];
    int j;
    printf("Enter C program (Ctrl+C to end):\n");
    while((c=getchar())!=EOF){
        if(isalpha(c)){
            for(j=0;isalnum(c);c=getchar())
                w[j++]=c;
            w[j]='\0';

            printf("%s : %s\n",isKeyword(w) ? "Keyword" : "Identifier", w);
        }
        else if(isdigit(c)){
            for(j=0;isdigit(c);c=getchar())
                w[j++]=c;
            w[j]='\0';

            printf("Constant : %s\n",w);
        }
        else if(c=='/' && (c=getchar())=='/'){
            j=0;
            w[j++]='/';
            w[j++]='/';

            while((c=getchar())!='\n' && c!=EOF)
                w[j++]=c;

            w[j]='\0';
            printf("Comment : %s\n",w);
        }
        else if(strchr("+-*/=%",c)){
            printf("Operator : %c\n",c);
        }
    }
}
