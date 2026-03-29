// Implementation of symbol table.

#include <stdio.h>
#include <string.h>

struct {
    char n[20];
    int a;
}s[100];
int c=0,i,j;
char x[20];

int f(){
    for(i=0;i<c;i++)
        if(strcmp(s[i].n,x)==0)
            return i;
    return -1;
}


                while(j--){
                    scanf("%s %d", s[c].n, &s[c].a);
                    c++;
                }
                break;

            case 2:
                scanf("%s",x);
                i=f();
                if(i==-1) printf("Not Found\n");
                else scanf("%d",&s[i].a);
                break;

            case 3:
                scanf("%s",x);
                i=f();
                if(i==-1) printf("Not Found\n");
                else printf("%d\n",s[i].a);
                break;

            case 4:
                scanf("%s",x);
                i=f();
                if(i==-1) printf("Not Found\n");
                else{
                    for(j=i;j<c-1;j++)
                        s[j]=s[j+1];
                    c--;
                }
                break;

            case 5:
                for(i=0;i<c;i++)
                    printf("%s\t%d\n",s[i].n,s[i].a);
                break;

            case 6:
                return 0;
        }
    }
}
