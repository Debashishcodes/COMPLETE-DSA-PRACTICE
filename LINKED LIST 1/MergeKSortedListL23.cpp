#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* c = new ListNode(100);
        ListNode* temp = c;

        while (a != NULL && b != NULL) {
            if (a->val <= b->val) {
                temp->next = a;
                a = a->next;
            } else {
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }

        if (a == NULL) temp->next = b;
        else temp->next = a;

        return c->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if (arr.size() == 0) return NULL;

        while (arr.size() > 1) {
            ListNode* a = arr[0];
            arr.erase(arr.begin());

            ListNode* b = arr[0];
            arr.erase(arr.begin());

            ListNode* c = merge(a, b);
            arr.push_back(c);
        }
        return arr[0];
    }
};

// Helper function to create a linked list
ListNode* createList(vector<int> v) {
    if (v.size() == 0) return NULL;

    ListNode* head = new ListNode(v[0]);
    ListNode* temp = head;

    for (int i = 1; i < v.size(); i++) {
        temp->next = new ListNode(v[i]);
        temp = temp->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Solution sol;

    // Creating sample sorted linked lists
    vector<int> v1 = {1, 4, 5};
    vector<int> v2 = {1, 3, 4};
    vector<int> v3 = {2, 6};

    ListNode* l1 = createList(v1);
    ListNode* l2 = createList(v2);
    ListNode* l3 = createList(v3);

    vector<ListNode*> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    // Merge k sorted lists
    ListNode* result = sol.mergeKLists(lists);

    // Print result
    cout << "Merged List: ";
    printList(result);

    return 0;
}