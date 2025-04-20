#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
}*start=NULL;

void create() {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) return;

    int n;
    printf("Enter a Number: ");
    scanf("%d", &n);

    ptr->data = n;
    ptr->next = NULL;
    ptr->prev = NULL;

    if (start == NULL) {
        start = ptr;
    } else {
        struct node* temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }
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