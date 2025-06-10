#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* createList(vector<int>&v){
    Node* head=nullptr;
    Node* tail=nullptr;
    for(int num:v){
        Node* n=new Node();
        n->data=num;
        n->next=nullptr;
        if(!head){
            head=tail=n;
        }else{
            tail->next=n;
            tail=n;
        }
    }
    return head;
}

Node* Merge(Node* a, Node* b){
    Node* temp=new Node();
    temp->data=10;
    Node* t=temp;
    Node* f=a;
    Node* s=b;
    while(f && s){
        if(f->data<=s->data){
            Node *newNode=new Node();
            newNode->data=f->data;
            t->next=newNode;
            t=newNode;
            f=f->next;
        }else{
            Node *newNode=new Node();
            newNode->data=s->data;
            t->next=newNode;
            t=newNode;
            s=s->next;
        }
    }
    if(!f) t->next=s;
    if(!s) t->next=f;
    return temp->next;

}

Node* sort(Node *head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* slow =head;
    Node* fast=head;
     while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node *a=head;
        Node *b=slow->next;
        slow->next=nullptr;
        a = sort(a);
        b = sort(b);
        Node *c=Merge(a,b);
        return c;
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
    cout<<"Enter List data:";
    string s;
    getline(cin,s);
    stringstream ss(s);
    int num;
    vector<int>v;
    while(ss>>num){
        v.push_back(num);
    }
    Node* head=createList(v);
    head=sort(head);
    display(head);
}