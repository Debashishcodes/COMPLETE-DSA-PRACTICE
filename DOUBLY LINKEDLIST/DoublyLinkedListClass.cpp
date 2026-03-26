#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node * next;
    Node * prev;

    Node (int v){
        data = v;
        next = NULL;
        prev = NULL;
    }
};

class DLL{
public:
    Node * head;
    Node * tail;
    int size;

    DLL(){
        size = 0;
        head = tail = NULL;
    }

    void insertAtTail(int val){
        Node * temp = new Node(val);

        if(head == NULL){   // ✅ first node
            head = tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void display(){
        Node * temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    DLL List;

    List.insertAtTail(10);
    List.insertAtTail(20);
    List.insertAtTail(30);
    List.insertAtTail(40);

    List.display();
}