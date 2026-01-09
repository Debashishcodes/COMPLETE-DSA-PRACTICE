#include<iostream>
#include<climits>
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
    for(int i=0;i<=m-1;i++){
        for(int j = 0;j<=n-1;j++){
            cin>>arr[i][j];
        }
    }
    int max=INT_MIN;
    for(int i=0;i<=m-1;i++){
        for(int j = 0;j<=n-1;j++){
            if(max<arr[i][j])
            max=arr[i][j];
        }
    }
    cout<<" largest element is: "<< max<<endl;

    int smax=INT_MIN;
    for(int i=0;i<=m-1;i++){
        for(int j = 0;j<=n-1;j++){
            if(smax<arr[i][j]&&arr[i][j]!=max){
                smax=arr[i][j];
            }
        }
    }
    cout<<"the 2nd max is: "<<smax;
}