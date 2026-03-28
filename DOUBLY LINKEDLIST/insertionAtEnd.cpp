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
        head = NULL;
        tail = NULL;
    }

    // Insert at tail
    void insertAtTail(int val) {
        Node* newNode = new Node(val);

        // If list is empty
        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        // Link new node
        tail->next = newNode;
        newNode->prev = tail;

        // Move tail
        tail = newNode;
    }

    // Display function
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DLL list;

    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);

    list.display();

    return 0;
}