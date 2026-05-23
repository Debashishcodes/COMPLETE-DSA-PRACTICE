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
bool isSameTree(Node * p, Node * q){
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false;
    if(p->val != q->val) return false;

    if(p->val != q->val) return false;
        
    bool LSTans = isSameTree(p->left , q->left);
    if(LSTans == false) return false;

    bool RSTans = isSameTree(p->right , q->right);
    if(RSTans ==  false) return false;

    return true;
}

int main(){
    Node * a = new Node(1);
    Node * b = new Node(2);
    Node * c = new Node(3);

    a->left = b;
    a->right = c;

    Node * d = new Node(1);
    Node * e = new Node(2);
    Node * f = new Node(3);
    d->left = e;
    d->right = f;

    bool result = isSameTree(a,d);
    cout << "Are the trees the same? " << (result ? "Yes" : "No") << endl;

    return 0;
}