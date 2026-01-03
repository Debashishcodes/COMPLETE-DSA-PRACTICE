#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter array length: ";
    cin>>n;

    int arr[n];
    cout<<"enter array elements: ";
    for(int i=0;i<n;i++){
    cin>>arr[i];
    }

    int product = 1;
    for(int i=0;i<n;i++){
        product = product * arr[i];
    }
    cout<<product;
}