#include<iostream>
using namespace std;
int main(){
    int nums[]={10,5,2,6};
    int n = sizeof(nums)/sizeof(nums[0]);
    int k = 100;
    if (k <= 1) return 0;   // no product can be < 1

    int left = 0;
    long long product = 1;
    int count = 0;

    for (int right = 0; right < n; right++) {
        product *= nums[right];   // expand window
        // shrink window if product >= k
        while (product >= k) {
            product /= nums[left];
            left++;
        }
        // all subarrays ending at 'right'
        count += (right - left + 1);
    }
    cout<<count;
}