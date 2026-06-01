#include <iostream>
#include <unordered_map>
using namespace std;

// Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
private:
    unordered_map<long long, int> prefix;
    int ans = 0;

    void dfs(TreeNode* node, long long currSum, int targetSum) {
        if (node == nullptr)
            return;

        currSum += node->val;

        if (prefix.find(currSum - targetSum) != prefix.end()) {
            ans += prefix[currSum - targetSum];
        }

        prefix[currSum]++;

        dfs(node->left, currSum, targetSum);
        dfs(node->right, currSum, targetSum);

        // Backtracking
        prefix[currSum]--;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        dfs(root, 0, targetSum);
        return ans;
    }
};

int main() {
    /*
            10
           /  \
          5   -3
         / \    \
        3   2    11
       / \   \
      3  -2   1

    targetSum = 8
    Answer = 3
    */

    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    root->right->right = new TreeNode(11);

    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);

    root->left->right->right = new TreeNode(1);

    int targetSum = 8;

    Solution obj;
    cout << "Number of paths = "
         << obj.pathSum(root, targetSum) << endl;

    return 0;
}