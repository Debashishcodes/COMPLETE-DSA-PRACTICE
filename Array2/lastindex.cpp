#include<iostream>
#include<vector>
using namespace std;
int main(){

    vector<int>v;

    int n;
    cout<<"enter vector length: ";
    cin>>n;

    cout<<"enter vector elements: ";  //8 5 6....
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);// v[0]=8,v[1]=5,.....
    }
    int x ;
    cout<<"enter the element you want to search its last index: ";
    cin>> x;

    int idx=-1;
    for(int i=v.size()-1;i>=0;i--){
        if(v[i]==x){
            idx=i;
            break;
        }
    }
    cout<<idx;
}