#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *start = NULL;
void insert_at_first(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    if (start == NULL)
    {
        start = temp ;
        temp->next = NULL ;
        temp->data = x ;
    }
    else
    {
        temp->next = start ;
        temp->data = x ;
        start = temp ;

    }
}
void display()
{
    struct node *temp = start;
    int c = 0;
    if (start == NULL)
    {
        printf("List is Empty.");
        return;
    }
    printf("Linked List:");
    while (temp != NULL)
    {
        c++;
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\nTotal Nodes: %d\n", c);
}
int main()
{

    int ch;
    while (1)
    {
        printf("Enter Your Choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter a Number to be Inserted:");
            int x;
            scanf("%d", &x);
            insert_at_first(x);
            break;
        case 2:
            display();
            break;
        default:
            printf("Invalid Choice.");
        }
    }

    return 0;
}