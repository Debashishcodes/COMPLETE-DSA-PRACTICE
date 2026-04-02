#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DLL {
public:
    Node* head;
    Node* tail;

    DLL() {
        head = tail = NULL;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Get head value
    int getHead() {
        if (head == NULL) {
            cout << "List is empty\n";
            return -1;
        }
        return head->data;
    }

    // Get tail value
    int getTail() {
        if (tail == NULL) {
            cout << "List is empty\n";
            return -1;
        }
        return tail->data;
    }
};

int main() {
    DLL list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);

    cout << "Head: " << list.getHead() << endl;
    cout << "Tail: " << list.getTail() << endl;

    return 0;
}