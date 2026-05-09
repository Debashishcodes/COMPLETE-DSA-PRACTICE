#include<iostream>
using namespace std;
//Display And Insert
class Node {
public:
    int val;
    Node* next;
    Node(int v) {
        val = v;
        next = NULL;
    }
};
class Queue {
private:
    Node* head;
    Node* tail;
    int s;

public:
    Queue() {
        head = tail = NULL;
        s = 0;
    }
// insert at end / tail 
    void push(int val) {
        Node* temp = new Node(val);
        if (s == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        s++;
    }
    void pop(){
        if(s==0){
            cout<<"Queue is Empty ";
            return;
        }
        Node * temp = head;
        head = head->next;
        s--;
        delete(temp);  // wastage nhin ho rahi
    }
    int front(){
       if(s==0){
            cout<<"Queue is Empty ";
            return -1;
        }
        return head->val;
    }
    int back(){
        if(s==0){
            cout<<"Queue is Empty ";
            return -1;
        }
        return tail->val;
    }
//traversal
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int size(){
        return s;
    }
    bool empty(){
        if(s==0) return true;
        else return false;
    }
};
int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display();
    q.push(50);
    q.push(60);
    q.display();
    q.pop();
    q.display(); 
}