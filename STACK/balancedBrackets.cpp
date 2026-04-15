#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isbalance (string s){
    stack<char>st;
    if(s.length() % 2!=0) return false;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') st.push(s[i]);
        else{   // s[i] = ')'
            if(st.size()==0) return false;
            else st.pop(); 
        }
    }
    if(st.size()==0) return true;
    else return false;
}
int main(){
    string s = "()()() ";
    cout<<isbalance(s);
}