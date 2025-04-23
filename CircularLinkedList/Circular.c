#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node NODE;
NODE* start = NULL;
NODE* last = NULL;

void create() {
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    int data;
    printf("Enter the required data: ");
    scanf("%d", &data);
    temp->data = data;

    if (start == NULL) {
        start = temp;
        last = temp;
        temp->next = start;
    } else {
        last->next = temp;
        last = temp;
        last->next = start;
    }
}

void display() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    NODE* temp = start;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != start);
    printf("(back to start)\n");
}

void LastNode() {
    if (last == NULL) {
        printf("List is empty.\n");
    } else {
        printf("Last node data: %d\n", last->data);
    }
}

void insert_at_first() {
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    int data;
    printf("Enter data to insert at first: ");
    scanf("%d", &data);
    temp->data = data;

    if (start == NULL) {
        start = last = temp;
        temp->next = start;
    } else {
        temp->next = start;
        start = temp;
        last->next = start;
    }
}

void insert_at_last() {
    create();
}

void insert_at_index() {
    int index, data;
    printf("Enter index to insert at: ");
    scanf("%d", &index);
    printf("Enter data: ");
    scanf("%d", &data);

    if (index == 0) {
        insert_at_first();
        return;
    }

    NODE* temp = start;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
        if (temp == start) {
            printf("Index out of bounds.\n");
            return;
        }
    }

    NODE* ptr = (NODE*)malloc(sizeof(NODE));
    ptr->data = data;
    ptr->next = temp->next;
    temp->next = ptr;
    if (temp == last) {
        last = ptr;
    }
}

void delete_at_first() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    NODE* temp = start;
    if (start == last) {
        start = last = NULL;
    } else {
        start = start->next;
        last->next = start;
    }
    free(temp);
}

void delete_at_last() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (start == last) {
        free(start);
        start = last = NULL;
        return;
    }
    NODE* temp = start;
    while (temp->next != last) {
        temp = temp->next;
    }
    temp->next = start;
    free(last);
    last = temp;
}

void delete_at_index() {
    int index;
    printf("Enter index to delete (0-based): ");
    scanf("%d", &index);

    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (index == 0) {
        delete_at_first();
        return;
    }

    NODE* temp = start;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
        if (temp->next == start) {
            printf("Index out of bounds.\n");
            return;
        }
    }

    NODE* ptr = temp->next;
    temp->next = ptr->next;
    if (ptr == last) {
        last = temp;
    }
    free(ptr);
}

int main() {
    int ch;
    while (1) {
        printf("\n1. Create\n2. Display\n3. Last Node\n4. Insert at First\n5. Insert at Last\n6. Insert at Index\n7. Delete at First\n8. Delete at Last\n9. Delete at Index\n10. Exit\nEnter your Choice: ");
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
