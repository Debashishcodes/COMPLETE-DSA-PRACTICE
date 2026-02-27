//leetcode 1052
#include<iostream>
using namespace std;
int main(){
    int arr[]={1,0,1,2,1,1,7,5};
    int grumpy[]={0,1,0,1,0,1,0,1};
    int n =sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    int maxloss=0;
    int prevloss=0;
    for(int i=0;i<k;i++){
        if(grumpy[i]==1) prevloss += arr[i];
    }
    maxloss=prevloss;
    int maxidx=0;
    //sliding window
    int i=1;
    int j=k;
    while(j<n){
        int currloss = prevloss ;
        if(grumpy[j]==1) currloss += arr[j];
        if(grumpy[i-1]==1) currloss -= arr[i-1];
        if(maxloss<currloss){
            maxloss=currloss;
            maxidx=i;
        }
        prevloss = currloss;
        i++;
        j++;
    }
    //filling zeros in the grumpy array window
    for(int i=maxidx;i<maxidx+k;i++){
        grumpy[i]=0;
    }
    //sum of satifaction
    int sum = 0;
    for(int i=0;i<n;i++){
        if(grumpy[i]==0){
            sum+=arr[i];
        }
    }
    cout<<sum;
}