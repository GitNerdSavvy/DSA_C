#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node Stack;
Stack* top = NULL;

void push() {
    Stack* ptr = (Stack*)malloc(sizeof(Stack));
    int data;
    printf("Enter an element: ");
    scanf("%d", &data);
    ptr->data = data;
    ptr->next = top;
    top = ptr;
}

void pop() {
    if(top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    Stack* ptr = top;
    top = top->next;
    free(ptr);
}

void display() {
    Stack* temp = top;
    if(temp == NULL) {
        printf("Stack is empty..\n");
        return;
    }
    printf("Stack Elements are: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int ch;
    while(1) {
        printf("\n1. Push\n2. Pop\n3. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 6: exit(0);
            default: printf("Invalid Choice.\n");
        }
    }
    return 0;
}
