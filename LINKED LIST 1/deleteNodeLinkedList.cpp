#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int v){
        data = v;
        next = NULL;
    }
};

void deleteNode(Node* target){
    if(target == NULL || target->next == NULL){
        return;
    }

    target->data = target->next->data;
    Node* temp = target->next;
    target->next = target->next->next;
    delete temp;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){

    // Creating linked list 4 -> 5 -> 1 -> 9
    Node* head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(1);
    head->next->next->next = new Node(9);

    cout << "Original List: ";
    printList(head);

    // Delete node with value 5
    deleteNode(head->next);

    cout << "After Deletion: ";
    printList(head);

    return 0;
}