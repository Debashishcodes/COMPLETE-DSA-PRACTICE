#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Definition of ListNode
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx = 1;
        int fastidx = -1;
        int lastidx = -1;

        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return {-1, -1};

        ListNode *a = head;
        ListNode *b = head->next;
        ListNode *c = head->next->next;

        // maximum distance
        while (c) {
            if ((b->val > a->val && b->val > c->val) || 
                (b->val < a->val && b->val < c->val)) {

                if (fastidx == -1) fastidx = idx;
                else lastidx = idx;
            }

            idx++;
            a = a->next;
            b = b->next;
            c = c->next;
        }

        if (lastidx == -1) return {-1, -1};

        int maxd = lastidx - fastidx;

        // minimum distance
        fastidx = -1;
        lastidx = -1;
        idx = 1;
        a = head;
        b = head->next;
        c = head->next->next;

        int mindistance = INT_MAX;

        while (c) {
            if ((b->val > a->val && b->val > c->val) || 
                (b->val < a->val && b->val < c->val)) {

                fastidx = lastidx;
                lastidx = idx;

                if (fastidx != -1) {
                    int d = lastidx - fastidx;
                    mindistance = min(mindistance, d);
                }
            }

            idx++;
            a = a->next;
            b = b->next;
            c = c->next;
        }

        return {mindistance, maxd};
    }
};

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n < 3) {
        cout << "-1 -1\n";
        return 0;
    }

    // Create linked list
    int x;
    cin >> x;
    ListNode* head = new ListNode(x);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        temp->next = new ListNode(x);
        temp = temp->next;
    }

    Solution obj;
    vector<int> ans = obj.nodesBetweenCriticalPoints(head);

    cout << "Minimum Distance: " << ans[0] << endl;
    cout << "Maximum Distance: " << ans[1] << endl;

    return 0;
}