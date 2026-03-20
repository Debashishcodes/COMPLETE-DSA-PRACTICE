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
    ListNode* partition(ListNode* head, int x) {
        ListNode * lo = new ListNode(100);
        ListNode * hi = new ListNode(120);
        ListNode * tempL = lo;
        ListNode * tempH = hi;
        ListNode * temp  = head;

        while(temp != NULL){
            if(temp->val < x){
                tempL->next = temp;
                temp = temp->next;
                tempL = tempL->next;
            }
            else{
                tempH->next = temp;
                temp = temp->next;
                tempH = tempH->next;
            }
        }

        tempL->next = hi->next;
        tempH->next = NULL;

        return lo->next;
    }
};

// Helper function to insert node at end
ListNode* insert(ListNode* head, int val) {
    if (!head) return new ListNode(val);
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new ListNode(val);
    return head;
}

// Helper function to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* head = NULL;

    // Create linked list: 1 -> 4 -> 3 -> 2 -> 5 -> 2
    head = insert(head, 1);
    head = insert(head, 4);
    head = insert(head, 3);
    head = insert(head, 2);
    head = insert(head, 5);
    head = insert(head, 2);

    cout << "Original list: ";
    printList(head);

    Solution obj;
    int x = 3;

    head = obj.partition(head, x);

    cout << "Partitioned list around " << x << ": ";
    printList(head);

    return 0;
}