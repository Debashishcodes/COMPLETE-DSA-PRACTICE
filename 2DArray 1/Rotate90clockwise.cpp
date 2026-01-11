#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter row/column number: ";
    cin>>n;
    cout<<"enter the elements: ";
    int arr[n][n];
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=n-1;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    //transposing  the matrix
    for(int i=0;i<=n-1;i++){
        for(int j=i+1;j<=n-1;j++){
           int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    for(int i=0;i<=n-1;i++){
        for(int j =0;j<=n-1;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    // reversing the transposed matrix
    for(int k =0;k<n;k++){
        int i=0;
        int j=n-1;
        while(i<=j){
            int p=arr[k][i];
            arr[k][i]=arr[k][j];
            arr[k][j]=p;
            i++;
            j--;
        }
    }
    cout<<endl;
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=n-1;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}