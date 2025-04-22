#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
} *start = NULL, *tail = NULL;

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
        start = tail = ptr;
    } else {
        tail->next = ptr;
        ptr->prev = tail;
        tail = ptr;
    }
}

void display() {
    struct node* temp = start;
    if (start == NULL) {
        printf("List is Empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void displayLast(){
    struct node* temp=tail;
    if(tail==NULL) {
        printf("List is Empty.\n");
        return;
    }
    printf("Doubly Linked List In Reverse: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
void search() {
    struct node* temp = start;
    if (start == NULL) {
        printf("List is Empty.\n");
        return;
    }
    int data, index = 0;
    printf("Enter a Number to Search: ");
    scanf("%d", &data);

    while (temp != NULL) {
        if (temp->data == data) {
            printf("Found at index %d\n", index);
            return;
        }
        temp = temp->next;
        index++;
    }
    printf("Not Found\n");
}

void LastNode() {
    if (tail == NULL) {
        printf("List is Empty.\n");
        return;
    }
    printf("Last Node: %d\n", tail->data);
}

int main() {
    int ch;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Node\n");
        printf("2. Display List\n");
        printf("3. Display List In Reverse\n");
        printf("4. Search Node\n");
        printf("5. Show Last Node\n");
        printf("6. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3:displayLast(); break;
            case 4: search(); break;
            case 5: LastNode(); break;
            case 6: exit(0);
            default: printf("Invalid Choice.\n");
        }
    }
    return 0;
}
