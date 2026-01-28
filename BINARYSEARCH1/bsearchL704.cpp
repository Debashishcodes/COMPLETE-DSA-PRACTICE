#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
    int main() {
        vector<int> nums = {4,5,6,7,0,1,2};
        int target = 0; 
        int result = search(nums, target);
        cout << "Index of target " << target << " is: " << result << endl;
        return 0;
    }