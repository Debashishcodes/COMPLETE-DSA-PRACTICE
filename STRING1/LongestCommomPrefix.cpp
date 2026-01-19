#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<string>v;
    v.push_back("flower");
    v.push_back("flow");
    v.push_back("flight");
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" "<<endl;
    }
    cout<<endl;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" "<<endl;
    }
    //compare the 1st and last string
    string m = v[0];
    string n = v[v.size()-1];
    string ans = " ";

    for(int i=0;i<v.size();i++){
        if(m[i]==n[i]){
            ans = ans + m[i];
        }
        else{
            break;
        }
    }
    cout<<"longest common prefix : "<<ans<<endl;
}
