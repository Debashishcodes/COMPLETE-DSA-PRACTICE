#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the length of the array: ";
    cin>>n;

    int arr[n];
    cout<<"enter the elements of the array: ";
    for(int i=0;i<=n-1;i++){
       cin>>arr[i];
    }
    int max = arr[0];
    for(int i=0;i<=n-1;i++){
    if(max<arr[i]){
        max=arr[i];
    }
    }
    int smax=arr[0];
    for(int i=0;i<=n-1;i++){
    if(arr[i]!=max&&smax<arr[i]){
        smax=arr[i];
    }
}
    cout<<"the maximum number is: "<<max<<endl;
    cout<<"the 2ndmaximum number is: "<<smax<<endl;
}