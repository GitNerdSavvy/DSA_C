#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*start=NULL;

void create(){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("Error, memory not allocated");
        return;
    }
    int num;
    printf("Enter a Number:");
    scanf("%d",&num);
    ptr->data=num;
    ptr->next=NULL;
    if(start==NULL){
        start=ptr;
    }else{
        struct node*temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr;
    }


}
void display(){
    struct node* temp=start;
    int c=0;
    if(start==NULL){
        printf("List is Empty.");
        return;
    }
    printf("Linked List:");
    while(temp!=NULL){
        c++;
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\nTotal Nodes: %d\n",c);
}

void search(){
    struct node* temp=start;
    int num;
    if(start==NULL){
        printf("List is Empty.");
        return;
    }
    printf("Enter a number to search: ");
    scanf("%d",&num);
    while(temp!=NULL){
        if(temp->data==num){
            printf("Number %d is found.\n",num);
            break;
        }
        temp=temp->next;
    }
}
void LastNode(){
    struct node* temp=start;
    if(start==NULL){
        printf("List is Empty.");
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    printf("This is Last Node: %d\n",temp->data);
}
int main(){
    int ch;
    while(1){
        printf("Enter your Choice:");
        scanf("%d",&ch);

        switch(ch){
            case 1:create();
            break;
            case 2:display();
            break;
            case 3:search();
            break;
            case 4:LastNode();
            break;
            case 5:exit(0);
            break;
            default:
            printf("Invalid Choice.");
        }
    }
return 0;
}