#include<stdio.h>
#include<stdlib.h>
#define max 10
int stack[max];
int top=-1;
void push(){
    int n;
    if(top==max-1){
        printf("stack overflow.\n");
    }
    printf("Enter an element:");
    scanf("%d",&n);
    top++;
    stack[top]=n;
}
void pop(){
    int n;
    if(top==-1){
        printf("stack underflow.\n");
    }
    
    top--;
    printf("Deleted element: %d\n",stack[top]);
}
void display(){
    if(top==-1){
        printf("Empty Stack.\n");
    }
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int main(){
    int ch;
    while(1){
        printf("\n1. Push\n2. Pop\n3. Display\n6. Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:push();break;
            case 2:pop();break;
            case 3:display();break;
            case 4:exit(0);break;
            default: printf("Invalid Choice.");
        }

    }


return 0;
}