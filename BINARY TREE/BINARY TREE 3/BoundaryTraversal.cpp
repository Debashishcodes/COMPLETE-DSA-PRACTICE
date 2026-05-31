#include<iostream>
#include<algorithm>
#include<climits>
#include<queue>
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
void leftBoundary(Node * root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    cout<<root->val<<" ";
    leftBoundary(root->left);
    if(root->left == NULL){
        leftBoundary(root->right);
    }
}
void rightBoundary(Node * root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    rightBoundary(root->right);
    if(root->right == NULL){
        rightBoundary(root->left);
    }
    cout<<root->val<<" ";
}
void leafNodes(Node * root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        cout<<root->val<<" ";
        return;
    }
    leafNodes(root->left);
    leafNodes(root->right);
}
void boundaryTraversal(Node * root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    leftBoundary(root->left);
    leafNodes(root);
    rightBoundary(root->right);
}
Node* buildTree(int arr[], int n){
    if(n == 0) return NULL;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while(i < n){
        Node* curr = q.front();
        q.pop();
        if(arr[i] != INT_MIN){
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;
        if(i >= n) break;
        if(arr[i] != INT_MIN){
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,INT_MIN,28,INT_MIN,INT_MIN};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node* root = buildTree(arr, n);
    
    boundaryTraversal(root);

}