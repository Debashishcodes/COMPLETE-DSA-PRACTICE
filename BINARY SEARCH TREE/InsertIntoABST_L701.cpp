#include <iostream>
using namespace std;

// TreeNode definition
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
};

// Insert into BST
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == NULL)
        return new TreeNode(val);

    if (root->val > val) {
        if (root->left == NULL) {
            root->left = new TreeNode(val);
        }
        else {
            insertIntoBST(root->left, val);
        }
    }
    else {
        if (root->right == NULL) {
            root->right = new TreeNode(val);
        }
        else {
            insertIntoBST(root->right, val);
        }
    }

    return root;
}

// Inorder Traversal
void inorder(TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = NULL;

    // Creating BST
    root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    cout << "BST before insertion: ";
    inorder(root);
    cout << endl;

    int val;
    cout << "Enter value to insert: ";
    cin >> val;

    root = insertIntoBST(root, val);

    cout << "BST after insertion: ";
    inorder(root);
    cout << endl;

    return 0;
}