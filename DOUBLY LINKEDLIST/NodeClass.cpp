#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node * next;
    Node * prev;
    Node ( int v){
        data = v;
        next = NULL;
        prev = NULL;
    }
};
void display(Node *head){
    Node * temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){

    Node * a = new Node (10);
    Node * b = new Node (20);
    Node * c = new Node (30);
    Node * d = new Node (40);
    Node * e = new Node (50);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    e->prev = d;
    d->prev = c;
    c->prev = b;
    b->prev = a;

    display(a);

}