#include <iostream>
using namespace std;

// Definition for singly-linked list.
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Insert at tail
void insertAtTail(ListNode* &head, int val) {
    if (head == NULL) {
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
}

// Print list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = NULL;

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

        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;

        ListNode* temp = head;
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
        if (c) c->next = NULL;

        ListNode* newHead = reverseList(b);

        if (a) a->next = newHead;
        b->next = d;

        if (a) return head;
        return newHead;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp = head;
        int gap = 1;

        while (temp != NULL && temp->next != NULL) {
            int remainLen = 0;
            ListNode* t = temp->next;

            for (int i = 1; i <= gap + 1 && t != NULL; i++) {
                t = t->next;
                remainLen++;
            }

            if (remainLen < gap + 1) gap = remainLen + 1;

            // ⚠️ FIX: even length group should reverse when gap is EVEN
            if (gap % 2 == 0) {
                reverseBetween(temp, 2, 2 + gap - 1);
            }

            gap++;

            for (int i = 1; temp != NULL && i <= gap; i++) {
                temp = temp->next;
            }
        }

        return head;
    }
};

int main() {
    ListNode* head = NULL;

    // Example input: 1->2->3->4->5->6->7->8
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);

    cout << "Original List:\n";
    printList(head);

    Solution obj;
    head = obj.reverseEvenLengthGroups(head);

    cout << "After Operation:\n";
    printList(head);

    return 0;
}