#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int i = 0;
    while (i < n) {
        int correct = nums[i] - 1;
        if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[correct]) {
            swap(nums[i], nums[correct]);
        } else {
            i++;
        }
    }

    // Find the first missing positive
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << n + 1 << endl;
    return 0;
}
