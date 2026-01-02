#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the length of the array: ";
    cin>>n;

    int arr[n];
    cout<<"enter the elements of the array: ";  //2 7 4 5 9 8
    for(int i=0;i<=n-1;i++){
       cin>>arr[i];
    }
    int max = arr[0];       /// max = 8
    for(int i=0;i<=n-1;i++){
    if(max<arr[i]){
        max=arr[i];     // 
    }
    }
    cout<<"the maximum number is: "<<max;
}