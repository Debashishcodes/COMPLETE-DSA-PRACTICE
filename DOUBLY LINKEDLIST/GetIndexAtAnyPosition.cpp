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

    DLL() {
        head = NULL;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Get value at position
    int getAtPosition(int pos) {
        Node* temp = head;

        for (int i = 1; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Invalid position\n";
            return -1;
        }

        return temp->data;
    }
};

int main() {
    DLL list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);

    cout << "Value at position 2: " << list.getAtPosition(2) << endl;

    return 0;
}