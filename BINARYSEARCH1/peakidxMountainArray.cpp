#include <iostream>
using namespace std;
int main(){
    int arr[]={1,3,5,4,3,2,1,0};
    int n = 8;
    int idx = -1; 
    
    //worst case -> o(n)
    // for(int i = 1;i<=n-2;i++){
    //     if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]){
    //         idx = i;
    //         break;
    //     }
    // }
    // cout<<idx;
        
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1]){
            cout<< mid;
            break;
            }
            else if(arr[mid]>arr[mid+1]) high = mid - 1;
            else low = mid+1;
        }
        
}