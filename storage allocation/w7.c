// Implement any one storage allocation strategies (heap, stack, static)

#include <stdio.h>
struct {
    char name[20];
    int addr;
} s[100];
int top = -1;
int main(){
    int ch;
    char name[20];
    printf("\n1.Push\n2.Pop\n3.Display\n4.Exit: ");
    while(1){
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                if(top==99)
                    printf("Stack Overflow\n");
                else{
                    printf("Enter variable: ");
                    scanf("%s",s[++top].name);
                    s[top].addr = top;
                }
                break;
            case 2:
                if(top==-1)
                    printf("Stack Underflow\n");
                else{
                    printf("Deleted: %s\n",s[top].name);
                    top--;
                }
                break;
            case 3:
                for(int i=top;i>=0;i--)
                    printf("%s\t%d\n",s[i].name,s[i].addr);
                break;
            case 4:
                return 0;
        }
    }
}
