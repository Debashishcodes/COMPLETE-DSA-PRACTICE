#include<iostream>
#include<vector>
using namespace std;

vector<int>merge(vector<int>&v1,vector<int>&v2){
    int n = v1.size(); //4
    int m = v2.size(); //6
    vector<int>v3(m+n);//10
    int i = 0; // v1
    int j = 0; //v2
    int k = 0; // resultant
    while(i<=n-1 && j<=m-1){
        if(v1[i]<v2[j]){
            v3[k] = v1[i];
            i++;
            k++;
        }
        else{   //v2[j]<v1[i];
            v3[k] = v2[j];
            j++;
            k++;
        }
    }
    //for remaining 
    if(i==n){       // v1 ki sare elements uthachuka hun
        while(j<=m-1){
            v3[k] = v2[j];
            k++;
            j++; 
        }
    }
    if(j==n){       // v2 ki sare elements uthachuka hun
        while(i<=n-1){
            v3[k]= v1[i];
            k++;
            i++; 
        }
    }
    return v3;
}
int main(){
    vector<int>v1;
    v1.push_back(1);
    v1.push_back(4);
    v1.push_back(5);    
    v1.push_back(8);

    for(int i = 0; i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    vector<int>v2;
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(10);
    v2.push_back(12);

    for(int i = 0; i<v2.size();i++){
        cout<<v2[i]<<" ";
    }
    cout<<endl;

    vector<int>v = merge(v1,v2);
    for(int i = 0; i<v.size();i++){
        cout<<v[i]<<" ";
    }
}