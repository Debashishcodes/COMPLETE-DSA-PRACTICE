#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reverse(queue<int>&q){
    stack<int>st;
    //empty the queue into stack 
    while(q.size()>0){
        int x = q.front();
        q.pop();
        st.push(x);
    } 
    //empty the stack into queue
    while(st.size()>0){
        int x = st.top();
        st.pop();
        q.push(x);
    }
}
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
    reverse(q);
    display(q);
}