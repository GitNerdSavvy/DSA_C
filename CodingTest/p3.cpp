#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
     Node *left;
     Node *right;
};

int find(Node *root,int a){
    Node* ptr=root;
    int c=0;
    while(ptr){
        if(ptr->data==a){
            return c;
        }
        else if(ptr->data<a){
            
        }

    }
}
int func(Node* root,int a,int b){
        int ans1=find(root,a);
        int ans2=find(root,b);
        return ans1+ans2;
}

Node *createNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}
void display(Node *temp)
{
    if (temp == nullptr)
    {
        return;
    }
    if (temp->left == nullptr && temp->right == nullptr)
    {
        cout<<temp->data;
        return;
    }
    if (temp->left == nullptr)
    {
       cout<<temp->data;
        display(temp->right);
        return;
    }
    if (temp->right == nullptr)
    {
        cout<<temp->data;
        display(temp->left);
        return;
    }
    display(temp->left);
    cout<<temp->data;
    display(temp->right);
}
Node *insertNode(Node *root, int d)
{
    if (root == nullptr)
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
    Node *root = nullptr;
    createNode(1);
    insertNode(root,2);
    insertNode(root,3);

    return 0;
}
