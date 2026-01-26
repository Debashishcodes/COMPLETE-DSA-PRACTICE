#include<iostream>
#include<climits>
using namespace std;
void printmax(int arr[],int n,int idx,int max){
    if(idx==n){
        cout<<max;
        return;
    }
    if(max<arr[idx]) max=arr[idx];
    printmax(arr,n,idx+1,max);
}
int main(){
    int arr[]={1,2,4,15,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    printmax(arr,n,0,INT_MIN);
}