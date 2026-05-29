#include<iostream>
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

