#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *Next = NULL;

        while (curr != NULL) {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        ListNode *a = NULL;
        ListNode *b = NULL; 
        ListNode *c = NULL;
        ListNode *d = NULL;

        ListNode *temp = head;
        int n = 1;

        while (temp != NULL) {
            if (n == left - 1) a = temp;
            if (n == left) b = temp;
            if (n == right) c = temp;
            if (n == right + 1) d = temp;
            temp = temp->next;
            n++;
        }

        if (a) a->next = NULL;
        c->next = NULL;

        c = reverseList(b);

        if (a) a->next = c;
        b->next = d;

        if (a) return head;
        return c;
    }
};

// Helper function to print list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Helper function to create list
ListNode* createList(int arr[], int n) {
    if (n == 0) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    ListNode* head = createList(arr, n);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    int left = 2, right = 4;

    head = obj.reverseBetween(head, left, right);

    cout << "After Reversing from " << left << " to " << right << ": ";
    printList(head);

    return 0;
}