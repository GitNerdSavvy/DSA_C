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
        start = temp;
        temp->next = NULL;
        temp->data = x;
    }
    else
    {
        temp->next = start;
        temp->data = x;
        start = temp;
    }
}
void insert_at_last(int d)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
        return;
    }
    struct node *ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    // start = temp;
}
void insert_at_index(int i, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next=NULL;
    if (start == NULL)
    {
        start = temp;
        temp->next = NULL;
        return;
    }
    if(i==0){
        temp->next=start;
        start=temp;
        return;
        
    }
    struct node *ptr=start;;
    while (i--)
    {
        if(ptr==NULL) return;
        ptr = ptr->next;
    }
    if(ptr==NULL) return;
    temp->next = ptr->next;
    ptr->next = temp;
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
        case 3:
            printf("Enter a Number to be Inserted:");
            int d;
            scanf("%d", &d);
            insert_at_last(d);
            break;
        case 4:
            printf("Enter a Number to be Inserted on Index:");
            int i, data;
            scanf("%d %d", &i, &data);
            insert_at_index(i, data);
            break;

        default:
            printf("Invalid Choice.");
        }
    }

    return 0;
}