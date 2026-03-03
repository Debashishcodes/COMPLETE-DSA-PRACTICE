#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[]={0,1,1,1,0,1,1,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 1 ; //max i can delete 1 element so k = 1
    int flip = 0;
    int len;
    int maxlen = INT_MIN;
    int i = 0;
    int j = 0;
    while(j<n){
        if(arr[j]==1) j++;
        else{
            if(flip < k){
                flip++;
                j++;
            }
            else{  //flips == k
                len = j-i;
                maxlen=max(len,maxlen);
                //i ko just uske aage wale 0 se ek index aage le jao
                while(arr[i]==1){
                    i++; //after this 100% arr[i] = 0;
                }
                i++;
                j++;
            }
        }
        len = j-i;
        maxlen=max(len,maxlen);
    }
    cout<<maxlen-1;
}