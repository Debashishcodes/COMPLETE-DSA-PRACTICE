#include<iostream>
using namespace std;
int main(){
    int n,capacity;
    cin>>n>>capacity;
    int* weights=new int[n];
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    int left=0,right=0;
    for(int i=0;i<n;i++){
        if(weights[i]>left) left=weights[i];
        right+=weights[i];
    }
    while(left<right){
        int mid=(left+right)/2;
        int sum=0,days=1;
        for(int i=0;i<n;i++){
            if(sum+weights[i]>mid){
                days++;
                sum=weights[i];
            }else{
                sum+=weights[i];
            }
        }
        if(days>capacity){
            left=mid+1;
        }else{
            right=mid;
        }
    }
    cout<<left<<endl;
    delete[] weights;
    return 0;
}