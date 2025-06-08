#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
};
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
Node* createList(const vector<int>& values) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int val : values) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}
vector<int> readValues() {
   string line;
   getline(cin , line);
   stringstream ss(line);
   vector<int>v;
   int num;
   while(ss >> num){
        v.push_back(num);
   }
   return v;
}
void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main(){
    cout << "Enter List 1 values: ";
    vector<int> list1 = readValues();

    cout << "Enter List 2 values: ";
    vector<int> list2 = readValues();

    Node* head1 = createList(list1);
    Node* head2 = createList(list2);
    Node* ans=Merge(head1,head2);
    display(ans);
}