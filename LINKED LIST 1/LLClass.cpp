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
class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() {
        head = tail = NULL;
        size = 0;
    }
// insert at end / tail 
    void insertAtEnd(int val) {
        Node* temp = new Node(val);

        if (size == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

//insert at begin / head
void insertAtBegin(int val){
    Node * temp = new Node(val);
    if(size==0){
        temp = head = tail ;
    }
    else{
    temp ->next = head;
    head = temp ;
    }
    size++;
}
//insert at index 
void inserAtIdx(int idx,int val){
    if(idx<0 || idx>size) cout<<"invalid index"<<endl;
    else if(idx==0) insertAtBegin( val);
    else if(idx==size) insertAtEnd( val);
    else{
        Node*t = new Node(val);
        Node * temp = head ;
        for(int i = 1;i<=idx-1;i++){
            temp = temp->next ;
        }
        t->next = temp ->next;
        temp ->next = t;
        size++;
    }
}
// Get elemennt at perticular index 
int getElementAtIdx(int idx){
    if(idx<0 || idx >=size){
        cout<<"invalid index"<<endl;
        return -1;
    }
    else if(idx == 0) return head->val;
    else if(idx==size-1) return tail->val;
    else{
        Node*temp = head ;
        for(int i=1;i<=idx;i++){
            temp= temp ->next;
        }
        return temp->val;
    }
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
};
int main(){
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.display();
    ll.insertAtBegin(5);
    ll.display();
    ll.inserAtIdx(2,15);
    ll.display();
    cout<< ll.getElementAtIdx(3);
}