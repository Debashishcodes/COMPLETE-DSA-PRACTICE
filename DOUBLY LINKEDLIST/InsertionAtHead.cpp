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

    // Insert at beginning
    void insertAtHead(int val) {
        Node* newNode = new Node(val);

        // If list is empty
        if (head == NULL) {
            head = newNode;
            return;
        }

        // Link new node
        newNode->next = head;
        head->prev = newNode;

        // Move head to new node
        head = newNode;
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

    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);

    list.display();

    return 0;
}