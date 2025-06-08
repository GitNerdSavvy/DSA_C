#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* createList(vector<int>&v){
    Node* head=nullptr;
    Node* tail=nullptr;
    for(int val : v){
        Node* newNode=new Node();
        newNode->data=val;
        newNode->next=nullptr;
        if(head==nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    return head;
}
Node* rotateList(Node* head, int k){
    if(!head || !head->next) return head;
    Node* h=head,*tail=nullptr;
    int n=0;
    while(h){
        if(h->next==nullptr) tail=h;
        h=h->next;
        n++;
    }
    k=k%n;
    if(k==0) return head;
    tail->next=head;
    h=head;
    for(int i=0;i<n-k-1;i++){
        h=h->next;
    }
    head=h->next;
    h->next=nullptr;
    return head;

}
vector<int> read(){
    string line;
    getline(cin,line);
    stringstream ss(line);
    vector<int>res;
    int num;
    while(ss>>num){
        res.push_back(num);
    }
    return res;
}

void display(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL";
}
int main(){
    cout<<"Enter List elements: ";
    vector<int> list = read();
    Node* head =createList(list);
    int k;
    cout<<"Enter rotation freq: ";
    cin>>k;

    display(rotateList(head,k));
}