#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"enter the number of rows: ";
    cin>>m;
    int n;
    cout<<"enter the number of columns: ";
    cin>>n;
    int arr[m][n];
    cout<<"enter array elements:";
    for(int i = 0;i<=m-1;i++){
        for(int j = 0;j<=n-1;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    //transpose 
    for(int j =0;j<=n-1;j++){
        for(int i=0;i<=m-1;i++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}