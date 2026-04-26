#include<iostream>
#include<stack>
using namespace std;
int prio(char ch){
    if(ch =='+' || ch == '-') return 1;
    else return 2;
}
int solve(int val1,int val2,char ch){
    if(ch=='+') return val1+val2;
    else if(ch=='-') return val1-val2;
    else if(ch=='*') return val1*val2;
    else return val1/val2;
}
int main(){
    string s = "2+6*4/8-3";
    stack<int>val;
    stack<char>op;
    for(int i = 0; i < s.length(); i++){
        //check if s[i] is a digit (0-9)
        int ascii = (int)(s[i]);
        if(ascii >= 48 && ascii <= 57){  //digit
            val.push(s[i] - 48);
        }
        else{   //s[i] it is -> (* / + -)
            if(op.size() == 0) op.push(s[i]);
            else if(prio(s[i]) > prio(op.top())) op.push(s[i]);
            else{   //work = prio(s[i] < op.top()) 
                while(op.size()>0 && prio(s[i]) <= prio(op.top())){
                    //i have to do val1 op val2
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1,val2,ch);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    while(op.size()>0){
        char ch = op.top();
        op.pop();
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        int ans = solve(val1,val2,ch);
        val.push(ans);
    }
    cout<<val.top();
}