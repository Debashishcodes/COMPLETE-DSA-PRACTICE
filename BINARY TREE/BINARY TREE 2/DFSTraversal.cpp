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
// leetcode 144
void PreOrder(Node * root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
// leetcode 94
void InOrder(Node * root){
    if(root == NULL) return;
    InOrder(root->left);
    cout<<root->val<<" ";
    InOrder(root->right);
}
// leetcode 145
void PostOrder(Node * root){
    if(root == NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->val<<" ";
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
    PreOrder(a);
    cout<<endl;
    InOrder(a);
    cout<<endl;
    PostOrder(a);
}