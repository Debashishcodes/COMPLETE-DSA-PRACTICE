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

class LinkedList{
private:
    Node* head;
    Node* tail;
    int size;
public:
    LinkedList() {
        head = tail = NULL;
        size = 0;
    }

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
    void DeleteAtHead(){
        if(size==0) {
            cout<<"nothing to be deleted !";
            return;
        }
        head = head ->next;
        size--;
    }
    void deleteAtEnd(){
        if(size==0) {
            cout<<"nothing to be deleted !";
            return;
        }
        else{
            Node * temp = head ;
            while(temp->next!=tail){
                temp = temp -> next ;
            }
            temp->next = NULL;
            temp = tail;
            size--;
        }
    }
    void deleteAtIdx(int idx){
        if(size==0) {
            cout<<"nothing to be deleted !";
            return;
        }
        else if(idx<0 || idx>size) cout<<"invalid index"<<endl;
        else if(idx==0) return DeleteAtHead( );
        else if(idx==size) return deleteAtEnd( );
        else{
            Node * temp = head ;
            for(int i = 1;i<=idx-1;i++){
                temp = temp->next ;
            }
            temp->next = temp->next->next;
            size--;
        }
    }
    void Display() {
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
    ll.insertAtEnd(50);
    ll.Display();
    ll.DeleteAtHead();
    ll.Display();
    ll.deleteAtEnd();
    ll.Display();
    ll.deleteAtIdx(2);
    ll.Display();
}