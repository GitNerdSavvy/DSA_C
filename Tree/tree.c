#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node node;

node *createNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void display(node *temp)
{
    if (temp == NULL)
    {
        return;
    }
    if (temp->left == NULL && temp->right == NULL)
    {
        printf("%d ", temp->data);
        return;
    }
    if (temp->left == NULL)
    {
        printf("%d ", temp->data);
        display(temp->right);
        return;
    }
    if (temp->right == NULL)
    {
        printf("%d ", temp->data);
        display(temp->left);
        return;
    }
    display(temp->left);
    printf("%d ", temp->data);
    display(temp->right);
}
node *insertNode(node *root, int d)
{
    if (root == NULL)
    {
        return createNode(d);
    }

    if (d < root->data)
    {
        root->left = insertNode(root->left, d);
    }
    else
    {
        root->right = insertNode(root->right, d);
    }
    return root;
}
int main()
{
    node *root = NULL;
    int ch;
    while (1)
    {
        printf("Enter Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            int data;
            printf("Enter a Val:");
            scanf("%d", &data);
            root = insertNode(root, data);
            break;
        }
        case 2:
            display(root);
            printf("\n");
            break;
        case 3:
        {
            int d;
            printf("Enter a val:");
            scanf("%d", &d);
            root = insertNode(root, d);
            break;
        }
        default:
            exit(0);
        }
    }

    return 0;
}
