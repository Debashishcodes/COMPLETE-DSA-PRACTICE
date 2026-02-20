#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int i = 0;
    while(i<n){
        int correctidx = nums[i];
        if(nums[correctidx]==nums[i]){
            cout<< nums[i];
            break;
        }
        else if (correctidx ==i) i++;
        else swap(nums[i],nums[correctidx]);
    }       
    return 0;
}