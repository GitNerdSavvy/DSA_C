#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* createList(vector<int>&v){
    Node* head=nullptr;
    Node* tail=nullptr;
    for(int val:v){
        Node* newNode=new Node();
        newNode->data=val;
        newNode->next=nullptr;
        if(!head){
            head=tail=newNode;

        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    return head;

}

Node* mergeListZero(Node* head){
    Node *left=head->next;
    while(left){
        Node* right = left;
        int sum=0;
        while(right->data!=0){
            sum+=right->data;
            right=right->next;
        }
        left->data=sum;
        left->next = right->next;
        left=left->next;
    }
    return head->next;
}

void display(Node* head){
    Node* ptr=head;
    while(ptr){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL";
}
int main(){
    cout<<"Enter List1 values:";
    vector<int>v;
    string s;
    getline(cin,s);
    stringstream ss(s);
    int num;
    while(ss>>num){
        v.push_back(num);
    }
    Node* list = createList(v);
    display(mergeListZero(list));
    
}