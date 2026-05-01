#include<iostream>
#include<stack>
using namespace std;

string solve(string val1,string val2,int op){
    string s = "";
    s+= val1;
    s.push_back(op);
    s+= val2;
    return s;
}

int main(){
    string s = "-/*+79483"; //prefix
    stack<string>val;
    for(int i = s.length()-1; i >= 0 ; i--){
        //check if s[i] is a digit (0-9)
        int ascii = (int)(s[i]);
        if(ascii >= 48 && ascii <= 57){  //digit
            val.push(to_string(s[i] - 48));
        }
        else{   // s[i] it is-> (* , / , + , - )
            string val1 = val.top();
            val.pop();
            string val2 = val.top();
            val.pop();
            string ans = solve(val1,val2,s[i]);
            val.push(ans);
        }
    }
    cout<<val.top();
}