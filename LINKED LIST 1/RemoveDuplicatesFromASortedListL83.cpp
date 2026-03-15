#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode *a = head;
        ListNode *b = head->next;

        while(b != NULL){
            while(b != NULL && b->val == a->val){
                b = b->next;
            }
            a->next = b;
            a = b;
            if(b != NULL) b = b->next;
        }

        return head;
    }
};

void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // Creating linked list: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    cout << "Original list: ";
    printList(head);

    Solution obj;
    head = obj.deleteDuplicates(head);

    cout << "After removing duplicates: ";
    printList(head);

    return 0;
}