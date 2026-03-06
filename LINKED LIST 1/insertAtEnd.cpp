#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* Next;

    Node(int v) {
        data = v;
        Next = NULL;
    }
};
// insert at end
void insertAtEnd(Node* head, Node* newNode) {
    while (head->Next != NULL) {
        head = head->Next;   // move to last node
    }
    head->Next = newNode;    // attach new node
    newNode->Next = NULL;
}
// traversal
void traverseList(Node* head) {
    Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->Next;
        }
    cout << endl;
}
int main() {
    Node*a = new Node(10);
    Node*b = new Node(20);
    Node*c = new Node(30);
    Node*d = new Node(40);
    a->Next = b;
    b->Next = c;
    c->Next = d;
    d->Next = NULL;
    traverseList(a);
    Node* x = new Node(50);
    insertAtEnd(a,x);
    traverseList(a);
}
