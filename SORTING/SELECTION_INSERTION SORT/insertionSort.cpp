#include<iostream>
using namespace std;int main(){
    int arr[]={5,3,1,4,2};
    int n = 5;
    for(int i =0;i<=n-1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i = 1;i<=n-1;i++){
        int j = i;
        while(j>=1){
          if(arr[j]>=arr[j-1]) break;
          else if(arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
          }  
        }
    }
    for(int i =0;i<=n-1;i++){
        cout<<arr[i]<<" ";
    }
}