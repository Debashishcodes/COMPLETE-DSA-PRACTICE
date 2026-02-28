//leetcode - 209
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[]={2,3,1,2,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 7;
    int sum = 0;
    int len=0;
    int minlen=INT_MAX;

    int i = 0;
    int j = 0;
    while(j<n){
        sum = sum +arr[j];
        while(sum>=target){
            len = j-i+1;
            minlen = min(minlen,len);
            sum = sum - arr[i];
            i++;
        }
        j++;
    }
    cout<<minlen;

}
