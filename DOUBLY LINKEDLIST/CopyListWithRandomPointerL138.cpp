#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;     // extra (DLL idea)
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        prev = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        Node* temp = head;

        // 1. Insert copy nodes
        while (temp) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            copy->prev = temp;
            temp = copy->next;
        }

        // 2. Assign random pointers
        temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        // 3. Separate lists
        temp = head;
        Node* newHead = head->next;

        while (temp) {
            Node* copy = temp->next;
            temp->next = copy->next;

            if (copy->next)
                copy->next = copy->next->next;

            temp = temp->next;
        }

        // 4. Fix prev pointers
        Node* curr = newHead;
        Node* p = NULL;
        while (curr) {
            curr->prev = p;
            p = curr;
            curr = curr->next;
        }

        return newHead;
    }
};

// 🔹 Helper function to print list
void printList(Node* head) {
    while (head) {
        cout << "Val: " << head->val;

        if (head->random)
            cout << ", Random: " << head->random->val;
        else
            cout << ", Random: NULL";

        cout << endl;
        head = head->next;
    }
}

int main() {
    // Create sample list: 1 -> 2 -> 3
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    n1->next = n2;
    n2->next = n3;

    n2->prev = n1;
    n3->prev = n2;

    // Random connections
    n1->random = n3;  // 1 -> 3
    n2->random = n1;  // 2 -> 1
    n3->random = n2;  // 3 -> 2

    cout << "Original List:\n";
    printList(n1);

    Solution obj;
    Node* copied = obj.copyRandomList(n1);

    cout << "\nCopied List:\n";
    printList(copied);

    return 0;
}