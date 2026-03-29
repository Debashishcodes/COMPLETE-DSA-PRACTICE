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

    // Insert at any position
    void insertAtPosition(int val, int pos) {
        Node* newNode = new Node(val);

        // Case 1: Insert at beginning
        if (pos == 1) {
            if (head == NULL) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            return;
        }

        Node* temp = head;

        // Traverse to (pos-1) node
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        // If position is invalid
        if (temp == NULL) {
            cout << "Invalid Position!" << endl;
            return;
        }

        // Case 2: Insert at tail
        if (temp->next == NULL) {
            temp->next = newNode;
            newNode->prev = temp;
            tail = newNode;
            return;
        }

        // Case 3: Insert in middle
        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // Display
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

    list.insertAtPosition(10, 1); // 10
    list.insertAtPosition(20, 2); // 10 20
    list.insertAtPosition(30, 3); // 10 20 30
    list.insertAtPosition(15, 2); // 10 15 20 30

    list.display();

    return 0;
}