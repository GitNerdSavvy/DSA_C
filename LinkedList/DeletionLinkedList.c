#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* delete_at_first(struct node* head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node* delete_at_last(struct node* head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct node* delete_at_index(struct node* head, int index) {
    if (head == NULL) return NULL;
    if (index == 0) return delete_at_first(head);

    struct node* ptr = head;
    struct node* p = head->next;

    for (int i = 0; i < index - 1; i++) {
        if (p == NULL || p->next == NULL) {
            printf("Invalid index.\n");
            return head;
        }
        ptr = ptr->next;
        p = p->next;
    }

    ptr->next = p->next;
    free(p);
    return head;
}

void display(struct node* head) {
    if (head == NULL) {
        printf("List is Empty.\n");
        return;
    }

    struct node* temp = head;
    int c = 0;
    printf("Linked List: ");
    while (temp != NULL) {
        c++;
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\nTotal Nodes: %d\n", c);
}

int main() {
    struct node *head, *first, *second, *third, *fourth, *fifth, *sixth;
    head = (struct node*)malloc(sizeof(struct node));
    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));
    fifth = (struct node*)malloc(sizeof(struct node));
    sixth = (struct node*)malloc(sizeof(struct node));

    head->data = 12;
    head->next = first;
    first->data = 13;
    first->next = second;
    second->data = 23;
    second->next = third;
    third->data = 33;
    third->next = fourth;
    fourth->data = 43;
    fourth->next = fifth;
    fifth->data = 53;
    fifth->next = sixth;
    sixth->data = 63;
    sixth->next = NULL;

    int ch;
    while (1) {
        printf("\n1. Delete at First\n2. Delete at Last\n3. Delete at Index\n4. Exit\nEnter Your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                display(head);
                head = delete_at_first(head);
                display(head);
                break;

            case 2:
                display(head);
                head = delete_at_last(head);
                display(head);
                break;

            case 3:
                printf("Enter Index to be Deleted: ");
                int i;
                scanf("%d", &i);
                display(head);
                head = delete_at_index(head, i);
                display(head);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice.\n");
        }
    }

    return 0;
}
