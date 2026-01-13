#include<iostream>
using namespace std;
int main(){
int m;
cout<<"enter row number: ";
cin>>m;
int n;
cout<<"enter column number: ";
cin>>n;

int arr[m][n];
cout<<"enter array elements: ";
for(int i=0;i<=m-1;i++){
    for(int j=0;j<=n-1;j++){
        cin>>arr[i][j];
    }
}
cout<<endl;
int minr=0,minc=0;
int maxr=m-1,maxc=n-1;

while(minr<=maxr&&minc<=maxc){
    //right
    for(int j=minc;j<=maxc;j++){
        cout<<arr[minr][j]<<" ";
    }
    minr++;
    if(minr>maxr || minc>maxc) break;
    //bottom
    for(int i=minr;i<=maxr;i++){
        cout<<arr[i][maxc]<<" ";
    }
    maxc--;
    if(minr>maxr||minc>maxc) break;
    //left
    for(int j=maxc;j>=minc;j--){
        cout<<arr[maxr][j]<<" ";
    }
    maxr--;
    if(minr>maxr||minc>maxc) break;
    //up
    for(int i=maxr;i>=minr;i--){
        cout<<arr[i][minc]<<" ";
    }
    minc++;
}
}