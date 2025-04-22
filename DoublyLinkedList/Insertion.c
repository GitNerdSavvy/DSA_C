#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
} *start = NULL, *tail = NULL;

void display() {
    struct node *temp = start;
    int c = 0;
    if (start == NULL) {
        printf("List is Empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        c++;
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\nTotal Nodes: %d\n", c);
}

void insert_at_first(int x) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = start;
    if (start != NULL)
        start->prev = temp;
    else
        tail = temp; 
    start = temp;
}

void insert_at_last(int x) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = tail;
    if (start == NULL) {
        start = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void insert_at_index(int index, int x) {
    if (index == 0) {
        insert_at_first(x);
        return;
    }

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;

    struct node *ptr = start;
    for (int i = 0; i < index - 1; i++) {
        if (ptr == NULL) {
            printf("Index out of bounds.\n");
            free(temp);
            return;
        }
        ptr = ptr->next;
    }

    if (ptr == tail) {
        insert_at_last(x);
        free(temp); 
        return;
    }

    temp->next = ptr->next;
    temp->prev = ptr;
    if (ptr->next != NULL)
        ptr->next->prev = temp;
    ptr->next = temp;
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Insert at First\n2.Display\n3.Insert at Last\n4.Insert at Index\n5.Exit\nEnter Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                int x;
                printf("Enter a Number to be Inserted at First: ");
                scanf("%d", &x);
                insert_at_first(x);
                break;
            }
            case 2:
                display();
                break;
            case 3: {
                int last;
                printf("Enter a Number to be Inserted at Last: ");
                scanf("%d", &last);
                insert_at_last(last);
                break;
            }
            case 4: {
                int i, data;
                printf("Enter Index and Data: ");
                scanf("%d %d", &i, &data);
                insert_at_index(i, data);
                break;
            }
            case 5:
                exit(0);
            default:
                printf("Invalid Choice.\n");
        }
    }
    return 0;
}
