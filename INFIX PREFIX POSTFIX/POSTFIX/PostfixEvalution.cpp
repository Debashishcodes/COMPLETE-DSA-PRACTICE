#include<iostream>
#include<stack>
using namespace std;

int solve(int val1,int val2,char ch){
    if(ch=='+') return val1+val2;
    else if(ch=='-') return val1-val2;
    else if(ch=='*') return val1*val2;
    else return val1/val2;
}

int main(){
    string s = "79+4*8/3-"; //postfix
    stack<int>val;
    for(int i = 0; i < s.length(); i++){
        //check if s[i] is a digit (0-9)
        int ascii = (int)(s[i]);
        if(ascii >= 48 && ascii <= 57){  //digit
            val.push((s[i] - 48));
        }
        else{   // s[i] it is-> (* , / , + , - )
            int val2 = val.top();
            val.pop();
            int val1 = val.top();
            val.pop();
            int ans = solve(val1,val2,s[i]);
            val.push(ans);
        }
    }
    cout<<val.top();
}