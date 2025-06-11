#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
     Node *left;
     Node *right;
};

int MPS(Node* root,int &maxi){
    if(root==NULL) return 0;
    int left= max(0,MPS(root->left,maxi));
    int right= max(0,MPS(root->right,maxi));
    maxi=max(maxi,left+right+root->data);
    return max(left,right)+root->data;
}
    int maxPathSum(Node* root) {
        int maxi=INT_MIN;
        MPS(root,maxi);
        return maxi;
        
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
        cout<<temp->data<<" ";
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
    cout<<temp->data<<" ";
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
     Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    int result = maxPathSum(root);
    cout << "Maximum Path Sum: " << result << endl;

    cout << "Inorder Traversal: ";
    display(root);
    cout << endl;

    return 0;
    

    return 0;
}
