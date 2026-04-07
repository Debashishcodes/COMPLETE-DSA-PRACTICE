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
    vector<ListNode*> splitListToParts(ListNode* head, int k){
        vector<ListNode *>ans;
        int n = 0;
        ListNode * temp = head;

        // Count total nodes
        while(temp){
            temp = temp->next;
            n++;
        }

        int size = n / k;
        int extra = n % k;

        temp = head;

        while(temp != NULL){
            ListNode * c = new ListNode(100); // dummy node
            ListNode * tempC = c;

            int s = size;
            if(extra > 0){
                s++;
                extra--;
            }

            for(int i = 1; i <= s; i++){
                tempC->next = temp;
                temp = temp->next;
                tempC = tempC->next;
            }

            tempC->next = NULL;
            ans.push_back(c->next);
        }

        // If parts < k, add NULL
        while(ans.size() < k){
            ans.push_back(NULL);
        }

        return ans;
    }
};

// Helper: Create linked list
ListNode* createList(vector<int> v){
    if(v.empty()) return NULL;

    ListNode* head = new ListNode(v[0]);
    ListNode* temp = head;

    for(int i = 1; i < v.size(); i++){
        temp->next = new ListNode(v[i]);
        temp = temp->next;
    }

    return head;
}

// Helper: Print list
void printList(ListNode* head){
    while(head){
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7};
    int k = 3;

    ListNode* head = createList(v);

    Solution obj;
    vector<ListNode*> result = obj.splitListToParts(head, k);

    cout << "Split Parts:\n";
    for(int i = 0; i < result.size(); i++){
        cout << "Part " << i+1 << ": ";
        printList(result[i]);
    }

    return 0;
}