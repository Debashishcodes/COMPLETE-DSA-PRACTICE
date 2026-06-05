#include <iostream>
using namespace std;

// Definition for a binary tree node
class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        else if(root->val==val) return root;
        else if(root->val < val) return searchBST(root->right,val);
        else return searchBST(root->left,val);    
    }
};
// Function to insert nodes into BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}
// main function
int main() {
    TreeNode* root = NULL;

    // Creating BST
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 3);

    int target;
    cout << "Enter value to search: ";
    cin >> target;

    
    TreeNode* result = root->searchBST(root, target);

    if(result != NULL)
        cout << "Value found: " << result->val << endl;
    else
        cout << "Value not found" << endl;
}