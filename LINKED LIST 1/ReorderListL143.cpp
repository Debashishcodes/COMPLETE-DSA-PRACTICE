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

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Find middle
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode *b = reverseList(slow->next);
        slow->next = NULL;

        ListNode *a = head;

        // Merge two lists
        while (a && b) {
            ListNode* temp1 = a->next;
            ListNode* temp2 = b->next;

            a->next = b;
            b->next = temp1;

            a = temp1;
            b = temp2;
        }
    }
};

// Helper: Create linked list from array
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

// Helper: Print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, n);

    cout << "Original List:\n";
    printList(head);

    Solution obj;
    obj.reorderList(head);

    cout << "Reordered List:\n";
    printList(head);

    return 0;
}