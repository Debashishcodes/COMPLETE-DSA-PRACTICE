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

void deleteAtBeginning(Node* &head) {
    if (head == NULL)
    return;
    // head = head->Next;
    Node * temp = head;
    head = head ->Next;
    delete temp;
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

    a.Next = &b;
    b.Next = &c;
    c.Next = NULL;

    Node* head = &a;

    cout << "Before deletion:\n";
    traverseList(head);

    deleteAtBeginning(head);

    cout << "After deleting beginning:\n";
    traverseList(head);
}
