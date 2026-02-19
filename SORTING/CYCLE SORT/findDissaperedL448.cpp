#include <iostream>
#include <algorithm>
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
        int correctidx = nums[i] - 1;

        if (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[correctidx])
            swap(nums[i], nums[correctidx]);
        else
            i++;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1)
            ans.push_back(i + 1);
    }

    for (int x : ans) cout << x << " ";
}
