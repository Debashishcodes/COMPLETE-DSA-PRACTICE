#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter number of array: ";
    cin>>n;

    int arr[n];
    //input
    cout<<"enter the elements of the array: ";
    for(int i=0;i<=n-1;i++){
        cin>>arr[i];
    }
    int x;
    cout<<"enter the element you want to search: ";
    cin>>x;

    //output
    bool flag=false;
    for(int i=0;i<=n-1;i++){
        if(arr[i]==x){
            flag = true;
            break;
        }
    }
    if(flag ==true)
    cout<<"element is present";
    else
    cout<<"element is not 4present";
}