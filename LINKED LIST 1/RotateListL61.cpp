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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;

        ListNode * temp = head;
        ListNode * tail = NULL;
        int n = 0;

        while(temp!=NULL){
            if(temp->next==NULL){
                tail=temp;
            }
            temp=temp->next;
            n++;
        }

        k = k % n;
        if(k==0) return head;

        temp = head;
        for(int i = 1; i < n-k; i++){
            temp = temp->next;
        }

        tail->next = head;
        head = temp->next;
        temp->next = NULL;

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

    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.rotateRight(head, k);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}