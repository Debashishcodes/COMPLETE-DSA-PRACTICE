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
    int min = arr[0];
    for(int i=0;i<=n-1;i++){
    if(min>arr[i]){
        min=arr[i];
    }
    }
    cout<<"the minimum number is: "<<min;
}