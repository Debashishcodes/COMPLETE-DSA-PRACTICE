#include<iostream>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * tempA = headA;
        ListNode * tempB = headB;

        int lenA = 0;
        while(tempA != NULL){
            lenA++;
            tempA = tempA->next;
        }

        int lenB = 0;
        while(tempB != NULL){
            lenB++;
            tempB = tempB->next;
        }

        tempA = headA;
        tempB = headB;

        if(lenA >= lenB){
            int diff = lenA - lenB;

            for(int i = 1; i <= diff; i++){
                tempA = tempA->next;
            }

            while(tempA != tempB){
                tempA = tempA->next;
                tempB = tempB->next;
            }
            return tempA;
        }
        else{
            int diff = lenB - lenA;

            for(int i = 1; i <= diff; i++){
                tempB = tempB->next;
            }

            while(tempA != tempB){
                tempA = tempA->next;
                tempB = tempB->next;
            }
            return tempB;
        }
    }
};

int main(){

    // Common intersection part
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    // List A: 3 -> 6 -> 9 -> 8 -> 10
    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(6);
    headA->next->next = new ListNode(9);
    headA->next->next->next = common;

    // List B: 4 -> 8 -> 10
    ListNode* headB = new ListNode(4);
    headB->next = common;

    Solution obj;
    ListNode* intersection = obj.getIntersectionNode(headA, headB);

    if(intersection)
        cout << "Intersection at node value: " << intersection->val << endl;
    else
        cout << "No intersection found" << endl;

    return 0;
}