#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
} *start = NULL;

void create() {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Error, memory not allocated\n");
        return;
    }
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    ptr->data = num;
    ptr->next = NULL;

    if (start == NULL) {
        start = ptr;
    } else {
        struct node* temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

void display() {
    struct node* temp = start;
    int c = 0;
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        c++;
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\nTotal Nodes: %d\n", c);
}

void LastNode() {
    struct node* temp = start;
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("This is the last node: %d\n", temp->data);
}

void insert_at_first() {
    int x;
    printf("Enter value to insert at beginning: ");
    scanf("%d", &x);

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = start;
    start = temp;
}

void insert_at_last() {
    int d;
    printf("Enter value to insert at end: ");
    scanf("%d", &d);

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = d;
    temp->next = NULL;
    if (start == NULL) {
        start = temp;
        return;
    }
    struct node* ptr = start;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void insert_at_index() {
    int data, i;
    printf("Enter value and index to insert: ");
    scanf("%d %d", &data, &i);

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (i == 0) {
        temp->next = start;
        start = temp;
        return;
    }

    struct node* ptr = start;
    for (int idx = 0; idx < i - 1; idx++) {
        if (ptr == NULL) {
            printf("Invalid index.\n");
            free(temp);
            return;
        }
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Invalid index.\n");
        free(temp);
        return;
    }

    temp->next = ptr->next;
    ptr->next = temp;
}

void delete_at_first() {
    if (start == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct node* temp = start;
    start = start->next;
    free(temp);
    printf("First node deleted.\n");
}

void delete_at_last() {
    if (start == NULL) {
        printf("List is already empty.\n");
        return;
    }
    if (start->next == NULL) {
        free(start);
        start = NULL;
        printf("Last node deleted.\n");
        return;
    }
    struct node* temp = start;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Last node deleted.\n");
}

void delete_at_index() {
    int index;
    printf("Enter index to delete: ");
    scanf("%d", &index);

    if (start == NULL) {
        printf("List is already empty.\n");
        return;
    }
    if (index == 0) {
        delete_at_first();
        return;
    }

    struct node* ptr = start;
    struct node* p = start->next;

    for (int i = 0; i < index - 1; i++) {
        if (p == NULL || p->next == NULL) {
            printf("Invalid index.\n");
            return;
        }
        ptr = ptr->next;
        p = p->next;
    }

    ptr->next = p->next;
    free(p);
    printf("Node at index %d deleted.\n", index);
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Create\n2.Display\n3.Last Node\n4.Insert at First\n5.Insert at Last\n6.Insert at Index\n7.Delete at First\n8.Delete at Last\n9.Delete at Index\n10.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: LastNode(); break;
            case 4: insert_at_first(); break;
            case 5: insert_at_last(); break;
            case 6: insert_at_index(); break;
            case 7: delete_at_first(); break;
            case 8: delete_at_last(); break;
            case 9: delete_at_index(); break;
            case 10: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
