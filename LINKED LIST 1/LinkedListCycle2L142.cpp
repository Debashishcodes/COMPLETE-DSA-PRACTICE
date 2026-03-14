#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        bool flag = false; // no cycle 
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                flag = true;
                break;
            }
        }

        if(flag == false) return NULL;
        else{
            ListNode * temp = head;
            while(temp != slow){
                slow = slow->next;
                temp = temp->next;
            }
            return slow;
        }
    }
};

int main() {

    // Creating nodes
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Creating a cycle: last node points to second node
    fourth->next = second;

    Solution obj;
    ListNode* cycleStart = obj.detectCycle(head);

    if(cycleStart != NULL)
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    else
        cout << "No cycle detected" << endl;

    return 0;
}