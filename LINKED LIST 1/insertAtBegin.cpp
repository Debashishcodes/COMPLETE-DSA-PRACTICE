#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node * next ;
    Node(int v){
        data = v;
        next = NULL;
    }
};
void display(Node * head){
    Node* temp = head ;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp ->next;
    }
    cout<<endl ;
}
void insertAtBegin(Node * &head,Node * newnode){
    newnode ->next = head ;
    head = newnode;
}
int main(){
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    a->next = b;
    b->next = c;
    c->next = NULL;
    Node * x = new Node(5); 
    display(a);
    insertAtBegin(a,x);
    display(a);
}