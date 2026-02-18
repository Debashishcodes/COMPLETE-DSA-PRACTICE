#include<iostream>
using namespace std;
int main(){
    int arr[]={4,1,5,2,6,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    int i=0;
    while(i<n){
        int correctPosition = arr[i] - 1;
        if(i==correctPosition) i++;
        else swap(arr[i],arr[correctPosition]);
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}