#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int v){
        data = v;
        next = NULL;
        prev = NULL;
    }
};
class Deque{
public:
    Node *head;
    Node *tail;
    int s;
    Deque(){
        head = tail = NULL;
        s = 0;
    }
    void push_Front(int val){
        Node *temp = new Node(val);

        if(s == 0){
            head = tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        s++;
    }
    void push_Back(int val){
        Node *temp = new Node(val);
        if(s == 0){
            head = tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        s++;
    }

    void pop_Front(){
        if(s == 0){
            cout << "List is empty!\n";
            return;
        }

        head = head->next;

        if(head != NULL) head->prev = NULL;
        else tail = NULL;

        s--;
    }

    void pop_Back(){
        if(s == 0){
            cout << "List is empty!\n";
            return;
        }

        if(s == 1){
            pop_Front();
            return;
        }

        Node *temp = tail->prev;
        temp->next = NULL;
        tail = temp;

        s--;
    }

    int front(){
        if(s == 0){
            cout << "Deque is empty\n";
            return -1;
        }
        return head->data;
    }

    int back(){
        if(s == 0){
            cout << "Deque is empty\n";
            return -1;
        }
        return tail->data;
    }

    int size(){
        return s;
    }

    bool empty(){
        return s == 0;
    }

    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Deque dq;

    dq.push_Back(10);
    dq.push_Back(20);
    dq.push_Back(30);
    dq.push_Back(40);
    dq.display();
    dq.pop_Front();
    dq.display();
    dq.push_Front(5);
    dq.display();

    return 0;
}