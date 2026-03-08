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

void deleteAtEnd(Node* head) {
    if (head == NULL || head->Next == NULL)
        return;

    Node* temp = head;

    while (temp->Next->Next != NULL) {
        temp = temp->Next;
    }

    temp->Next = NULL;
}

void traverseList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->Next != NULL)
            cout << " * ";
        head = head->Next;
    }
    cout << endl;
}

int main() {
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);

    a.Next = &b;
    b.Next = &c;
    c.Next = &d;
    d.Next = NULL;

    Node* head = &a;

    cout << "Before deletion:\n";
    traverseList(head);

    deleteAtEnd(head);

    cout << "After deleting end:\n";
    traverseList(head);
}
