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

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    // Delete at head
    void deleteAtHead() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DLL list;
    list.insertAtHead(30);
    list.insertAtHead(20);
    list.insertAtHead(10);

    list.deleteAtHead();
    list.display();

    return 0;
}