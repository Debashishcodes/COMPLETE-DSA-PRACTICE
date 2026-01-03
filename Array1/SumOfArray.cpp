#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the size of the array: ";
    cin>>n;
    int arr[n];
    //input
    cout<<"enter the elements of the array: ";      // 2 5 7 8 6 4 3 1 
    for(int i=0;i<=n-1;i++){
        cin>>arr[i];
    }
    //output
    int sum = 0;
    for(int i=0;i<=8-1;i++){
    sum = sum + arr[i];
    }
    cout<<"the sum is :"<<sum<<endl;
}
