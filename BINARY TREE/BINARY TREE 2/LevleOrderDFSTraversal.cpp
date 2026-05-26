#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node * left ;
    Node * right;
    Node(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};
// Print the levle/height of the tree
int levle(Node * root){
    if(root == NULL) return 0;
    int leftHeight = levle(root->left);
    int rightHeight = levle(root->right);
    int ans = max(leftHeight, rightHeight) + 1;
    return ans;
}
// Print the Nth level of the tree / print all nodes at a specific level (left to right)  
// leetcode 102
void NthLevel(Node * root,int curr ,int level){
    if(root == NULL) return;
    if(curr == level){
        cout<<root->val<<" ";
        return;
    }
    NthLevel(root->left,curr+1,level);
    NthLevel(root->right,curr+1,level);
}
// Print the Nth level of the tree / print all nodes at a specific level(right to left)
void NthLevelReverse(Node * root,int curr,int level){
    if(root == NULL) return;
    if(curr == level){
        cout<<root->val<<" ";
        return;
    }
    NthLevelReverse(root->right,curr+1,level);
    NthLevelReverse(root->left,curr+1,level);
}
// Print the level order traversal of the tree using DFS 
void LevleOrder(Node * root){
    int n = levle(root);
    for(int i = 1; i <= n; i++){
        NthLevel(root,1,i);
        cout<<endl;
    }
}
int main(){
    Node * a = new Node(1);
    Node * b = new Node(2);
    Node * c = new Node(3); 
    Node * d = new Node(4); 
    Node * e = new Node(5);
    Node * f = new Node(6);
    Node * g = new Node(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    cout<<levle(a);  // 3
    cout<<endl;
    NthLevel(a,1,3);  // 4 5 6 7 
    cout<<endl;
    LevleOrder(a);    // 1   2 3   4 5 6 7
    

}