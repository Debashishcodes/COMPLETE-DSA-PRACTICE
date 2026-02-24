#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int m;
    cin >> m;
    vector<int> queries(m);
    for (int i = 0; i < m; i++) {
        cin >> queries[i];
    }

    vector<int> ans(m);

    // sort nums
    sort(nums.begin(), nums.end());

    // make prefix sum in nums
    for (int i = 1; i < n; i++) {
        nums[i] += nums[i - 1];
    }

    // process each query
    for (int i = 0; i < m; i++) {
        int q = queries[i];
        int lo = 0, hi = n - 1;
        int maxlen = 0;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > q) {
                hi = mid - 1;
            } else {
                maxlen = mid + 1;
                lo = mid + 1;
            }
        }
        ans[i] = maxlen;
    }

    // print answer vector
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
