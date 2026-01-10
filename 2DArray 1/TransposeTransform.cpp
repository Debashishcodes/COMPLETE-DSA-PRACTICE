#include<iostream>
using namespace std;
int main(){
    
    int m;
    cout<<"enter the number of rows & columns: ";
    cin>>m;
    int arr[m][m];
    cout<<"enter array elements:";
    for(int i = 0;i<=m-1;i++){
        for(int j = 0;j<=m-1;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    //transpose in the same matrix
    for(int i = 0;i<=m-1;i++){
        for(int j =i+1;j<=m-1;j++){
            int temp = arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    for(int i = 0;i<=m-1;i++){
        for(int j = 0;j<=m-1;j++){
            cout<<arr[i][j]<<" ";  
        }
    cout<<endl;
    }
}