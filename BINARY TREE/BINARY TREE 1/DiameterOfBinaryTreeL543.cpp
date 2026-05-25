#include<iostream>
using namespace std;

// Definition of Node
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// height function
int levle(Node * root){
    if(root == NULL) return 0;

    int leftHeight = levle(root->left);
    int rightHeight = levle(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// diameter function
int diameterOfBinaryTree(Node* root){
    if(root == NULL) return 0;

    int dia = levle(root->left) + levle(root->right);

    int leftDia = diameterOfBinaryTree(root->left);
    int rightDia = diameterOfBinaryTree(root->right);

    return max(dia, max(leftDia, rightDia));
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int result = diameterOfBinaryTree(root);

    cout << "Diameter of Binary Tree: " << result << endl;

    return 0;
}