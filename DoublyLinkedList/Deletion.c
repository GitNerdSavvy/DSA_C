#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
} *start = NULL, *tail = NULL;

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

struct node *delete_at_first(struct node *head) {
    if (head == NULL)
        return NULL;

    if (head->next == NULL) {
        free(head);
        start = tail = NULL;
        return NULL;
    }

    struct node *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    return head;
}

struct node *delete_at_last(struct node *head) {
    if (head == NULL)
        return NULL;

    if (head->next == NULL) {
        free(head);
        start = tail = NULL;
        return NULL;
    }

    struct node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
    return head;
}

struct node *delete_at_index(struct node *head, int index) {
    if (head == NULL || index < 0)
        return head;

    struct node *temp = head;
    int i = 0;

    if (index == 0)
        return delete_at_first(head);

    while (temp != NULL && i < index) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Index out of range.\n");
        return head;
    }

    if (temp->next == NULL)
        return delete_at_last(head);

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);

    return head;
}

int main() {
    struct node *head, *first, *second, *third, *fourth, *fifth, *sixth;
    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    sixth = (struct node *)malloc(sizeof(struct node));

    head->prev = NULL;
    head->data = 12;
    head->next = first;

    first->prev = head;
    first->data = 13;
    first->next = second;

    second->prev = first;
    second->data = 23;
    second->next = third;

    third->prev = second;
    third->data = 33;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 43;
    fourth->next = fifth;

    fifth->prev = fourth;
    fifth->data = 53;
    fifth->next = sixth;

    sixth->prev = fifth;
    sixth->data = 63;
    sixth->next = NULL;

    start = head;
    tail = sixth;

    int ch;
    while (1) {
        printf("\n1. Delete at First\n2. Delete at Last\n3. Delete at Index\n4. Exit\nEnter Your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                display(start);
                start = delete_at_first(start);
                display(start);
                break;

            case 2:
                display(start);
                start = delete_at_last(start);
                display(start);
                break;

            case 3:
                printf("Enter Index to be Deleted: ");
                int i;
                scanf("%d", &i);
                display(start);
                start = delete_at_index(start, i);
                display(start);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice.\n");
        }
    }

    return 0;
}
