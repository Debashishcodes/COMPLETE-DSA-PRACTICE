#include<iostream>
#include<vector>
using namespace std;

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        if (n == 2) { // example -> 3 1
            if (target == nums[0]) return 0;
            else if (target == nums[1]) return 1;
            else return -1;
        }

        // STEP-01 find pivot index
        int pivot = -1; // smallest element
        while (low <= high) {
            int mid = low + (high - low) / 2; 
            if (mid == 0) {
                low = mid + 1;
                continue;
            } else if (mid == n - 1) {
                high = mid - 1;
                continue;
            }

            if (nums[mid] < nums[mid + 1] && nums[mid] < nums[mid - 1]) {
                pivot = mid;
                break;
            } else if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
                pivot = mid + 1;
                break;
            } else if (nums[mid] > nums[high]) low = mid + 1;
            else high = mid - 1;
        }

        if (pivot == -1) { // already sorted, no rotation
            low = 0;
            high = n - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums[mid] == target) return mid;
                else if (nums[mid] > target) high = mid - 1;
                else low = mid + 1;
            }
            return -1;
        }

        // STEP-02
        if (target >= nums[0] && target <= nums[pivot - 1]) {
            low = 0;
            high = pivot - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums[mid] == target) return mid;
                else if (nums[mid] > target) high = mid - 1;
                else low = mid + 1;
            }
        } else {
            low = pivot;
            high = n - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums[mid] == target) return mid;
                else if (nums[mid] > target) high = mid - 1;
                else low = mid + 1;
            }
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