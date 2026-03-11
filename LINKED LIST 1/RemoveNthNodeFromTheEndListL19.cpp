#include <iostream>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Function to remove Nth node from end
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* slow = dummy;
    ListNode* fast = dummy;

    // Move fast pointer n+1 steps ahead
    for(int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move both pointers
    while(fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    // Remove the nth node
    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return dummy->next;
}

// Function to print list
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {

    // Creating linked list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    int n = 2;

    head = removeNthFromEnd(head, n);

    cout << "After Removing " << n << "th Node from End: ";
    printList(head);

    return 0;
}