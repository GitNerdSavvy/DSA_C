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

void LastNode() {
    if (tail == NULL) {
        printf("List is Empty.\n");
        return;
    }
    printf("Last Node: %d\n", tail->data);
}

void insert_at_first() {
    int x;
    printf("Enter value to insert at first: ");
    scanf("%d", &x);

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = start;

    if (start != NULL)
        start->prev = temp;
    else
        tail = temp;

    start = temp;
}

void insert_at_last() {
    int x;
    printf("Enter value to insert at last: ");
    scanf("%d", &x);

    struct node* temp = (struct node*)malloc(sizeof(struct node));
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

void insert_at_index() {
    int x, index;
    printf("Enter value and index: ");
    scanf("%d %d", &x, &index);

    if (index == 0) {
        insert_at_first();
        return;
    }

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;

    struct node* ptr = start;
    for (int i = 0; i < index - 1; i++) {
        if (ptr == NULL) {
            printf("Index out of bounds.\n");
            free(temp);
            return;
        }
        ptr = ptr->next;
    }

    if (ptr == tail) {
        insert_at_last();
        free(temp);
        return;
    }

    temp->next = ptr->next;
    temp->prev = ptr;

    if (ptr->next != NULL)
        ptr->next->prev = temp;

    ptr->next = temp;
}

void delete_at_first() {
    if (start == NULL) {
        printf("List is Empty.\n");
        return;
    }

    struct node* temp = start;

    if (start->next == NULL) {
        start = tail = NULL;
    } else {
        start = start->next;
        start->prev = NULL;
    }

    free(temp);
}

void delete_at_last() {
    if (tail == NULL) {
        printf("List is Empty.\n");
        return;
    }

    struct node* temp = tail;

    if (start == tail) {
        start = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }

    free(temp);
}

void delete_at_index() {
    if (start == NULL) {
        printf("List is Empty.\n");
        return;
    }

    int index;
    printf("Enter index to delete: ");
    scanf("%d", &index);

    if (index < 0) {
        printf("Invalid index.\n");
        return;
    }

    if (index == 0) {
        delete_at_first();
        return;
    }

    struct node* temp = start;
    for (int i = 0; temp != NULL && i < index; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Index out of range.\n");
        return;
    }

    if (temp == tail) {
        delete_at_last();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

int main() {
    int ch;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Node\n");
        printf("2. Display List\n");
        printf("3. Last Node\n");
        printf("4. Insert at first\n");
        printf("5. Insert at last\n");
        printf("6. Insert at index\n");
        printf("7. Delete at first\n");
        printf("8. Delete at last\n");
        printf("9. Delete at index\n");
        printf("10. Exit\n");
        printf("Enter your Choice: ");
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
            default: printf("Invalid Choice.\n");
        }
    }
    return 0;
}
