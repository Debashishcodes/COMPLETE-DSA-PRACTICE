//leetcode-643
#include<iostream>
#include<math.h>
#include<climits>
using namespace std;
int main(){

    int arr[]={7,1,2,5,8,4,9,3,6};
    int n =sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    int maxsum=INT_MIN;
    int maxidx=0;
    int prevSum = 0;
    for(int i=0;i<k;i++){  //tno=k
        prevSum += arr[i];
    }
    maxsum = prevSum;
    int i = 1;
    int j = k;
    //sliding window
    while(j<n){     // tno=n-k
        int  currsum = prevSum + arr[j] - arr[i-1];
        if(maxsum<currsum){
            maxsum = currsum;
            maxidx = i;
        }
        prevSum = currsum;
        i++;
        j++;
    }
    cout<<maxsum<<endl;
    cout<<maxidx;
}