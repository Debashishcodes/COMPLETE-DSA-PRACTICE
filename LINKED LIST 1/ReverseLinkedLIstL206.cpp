#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* rest = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return rest;
    }
};

// Helper function to insert at end
ListNode* insert(ListNode* head, int val) {
    if(head == NULL) return new ListNode(val);

    ListNode* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = new ListNode(val);
    return head;
}

// Helper function to print list
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* head = NULL;

    // Creating list: 1 -> 2 -> 3 -> 4 -> NULL
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}