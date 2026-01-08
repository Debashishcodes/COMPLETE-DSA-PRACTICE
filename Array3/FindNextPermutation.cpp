#include<iostream>
#include<vector>
using namespace std; 

void reverse(vector<int>& nums, int i, int j)
{
    while(i < j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++;
        j--;
    }
}
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int idx = -1;
    // Step 1: Find pivot index
    for(int i = n - 2; i >= 0; i--) {
        if(nums[i] < nums[i + 1]) {
            idx = i; //(idx=1)
            break;
        }
    }
    // Step 2: If no pivot, reverse entire array
    if(idx == -1) {
        reverse(nums, 0, n - 1);
        return;
    }
    // Step 3: Find just greater element than idx value
    int j = -1;
    for(int i = n - 1; i > idx; i--) {
        if(nums[i] > nums[idx]) {
            j = i;
            break;
        }
    }
    // Step 4: Swap pivot and just greater element
    swap(nums[idx], nums[j]);

    // Step 5: Reverse the suffix
    reverse(nums, idx + 1, n - 1);
}
int main(){
    vector<int> nums = {4,2,6,5};
    nextPermutation(nums);

    for(int num : nums) {
        cout << num << " ";
    }
    return 0;
}
