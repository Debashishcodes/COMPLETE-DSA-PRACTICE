#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void display(queue<int>&q){
    int n = q.size();  // 6
    for(int i=1;i<=n;i++){
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}
int main(){
    queue<int>q;
    // push, pop ,front, back 
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40); 
    q.push(50);
    q.push(60); 
    display(q);
}