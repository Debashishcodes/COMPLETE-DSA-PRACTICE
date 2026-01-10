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
    cout<<"enter the array elements: ";
    for(int i = 0;i<=m-1;i++){
        for(int j = 0;j<=n-1;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    int trans[n][m];
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=m-1;j++){
            trans[i][j]=arr[j][i];
        }
        cout<<endl;
    }
    for(int i=0;i<=n-1;i++){
        for(int j =0;j<=m-1;j++){
            cout<<trans[i][j]<<" ";
        }
        cout<<endl;
    }
}