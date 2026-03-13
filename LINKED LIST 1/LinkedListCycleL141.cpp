#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    
    ListNode(int x){
        val = x;
        next = NULL;
    }
};

bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
    }
    return false;
}

int main(){

    // Creating nodes
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Creating a cycle (4 -> 2)
    fourth->next = second;

    if(hasCycle(head))
        cout << "Cycle detected";
    else
        cout << "No cycle";

    return 0;
}