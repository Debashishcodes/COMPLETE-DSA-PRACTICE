#include<iostream>
#include<stack>
using namespace std;
int prio(char ch){
    if(ch =='+' || ch == '-') return 1;
    else return 2;
}
string solve(string val1,string val2,char op){
    // we have to store prefix in the answer
    //prefix is -> op val1 val2
    string s = "";
    s += val1;
    s += val2;
    s.push_back(op);
    return s;
}
int main(){
    string s = "(7+9)*4/8-3";
    stack<string>val;
    stack<char>op;
    for(int i = 0; i < s.length(); i++){
        //check if s[i] is a digit (0-9)
        int ascii = (int)(s[i]);
        if(ascii >= 48 && ascii <= 57){  //digit
            val.push(to_string(s[i] - 48));
        }
        else{   //s[i] it is -> (* / + - (,))
            if(op.size() == 0) op.push(s[i]);
            else if(s[i]=='(') op.push(s[i]);
            else if(op.top()=='(') op.push(s[i]);
            else if(s[i]==')'){
                while(op.top()!='('){
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    string ans = solve(val1,val2,ch);
                    val.push(ans);
                }
                op.pop();   //opening bracket pop 
            }
            else if(prio(s[i]) > prio(op.top())) op.push(s[i]);
            else{   //work = prio(s[i] < op.top()) 
               while(op.size()>0 && op.top()!='(' && prio(s[i]) <= prio(op.top())){
                    //i have to do val1 op val2
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    string ans = solve(val1,val2,ch);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    while(op.size()>0){
        char ch = op.top();
        op.pop();
        string val2 = val.top();
        val.pop();
        string val1 = val.top();
        val.pop();
        string ans = solve(val1,val2,ch);
        val.push(ans);
    }
    cout<<val.top();
}