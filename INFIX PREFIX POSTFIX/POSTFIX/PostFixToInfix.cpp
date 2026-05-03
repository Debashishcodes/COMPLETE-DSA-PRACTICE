#include<iostream>
#include<stack>
using namespace std;

string solve(string val1,string val2,int ch){
    string s = "";
    s+=val1;
    s.push_back(ch);
    s+=val2;
    return s;
}
int main(){
    string s = "79+4*8/3-"; //postfix
    stack<string>val;
    for(int i = 0; i < s.length(); i++){
        //check if s[i] is a digit (0-9)
        int ascii = (int)(s[i]);
        if(ascii >= 48 && ascii <= 57){  //digit
            val.push(to_string(s[i] - 48));
        }
        else{   // s[i] it is-> (* , / , + , - )
            string val2 = val.top();
            val.pop();
            string val1 = val.top();
            val.pop();
            string ans = solve(val1,val2,s[i]);
            val.push(ans);
        }
    }
    cout<<val.top();
}