#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node * temp = head;
        while(temp != NULL){
            Node * a = temp->next;

            if(temp->child != NULL){
                Node * c = temp->child;
                temp->child = NULL;

                c = flatten(c);

                temp->next = c;
                c->prev = temp;

                // go to last node of child list
                while(c->next != NULL){
                    c = c->next;
                }

                c->next = a;
                if(a) a->prev = c;
            }

            temp = a;
        }
        return head;
    }
};

// Function to print the flattened list
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating nodes
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    // Main list: 1 - 2 - 3 - 4 - 5
    head->next = n2;
    n2->prev = head;

    n2->next = n3;
    n3->prev = n2;

    n3->next = n4;
    n4->prev = n3;

    n4->next = n5;
    n5->prev = n4;

    // Create child list for node 3: 7 - 8
    Node* c1 = new Node(7);
    Node* c2 = new Node(8);

    c1->next = c2;
    c2->prev = c1;

    n3->child = c1;

    Solution obj;
    head = obj.flatten(head);

    cout << "Flattened list: ";
    printList(head);

    return 0;
}