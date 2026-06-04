#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val == p->val || root->val == q->val)
            return root;

        else if (root->val > p->val && root->val < q->val)
            return root;

        else if (root->val < p->val && root->val > q->val)
            return root;

        else if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        else
            return lowestCommonAncestor(root->right, p, q);
    }
};

int main() {
    // Creating BST
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = root->left;          // Node 2
    TreeNode* q = root->left->right;   // Node 4

    Solution obj;

    TreeNode* ans = obj.lowestCommonAncestor(root, p, q);

    cout << "LCA = " << ans->val << endl;

    return 0;
}