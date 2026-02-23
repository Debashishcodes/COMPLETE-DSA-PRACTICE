#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int satisfaction[] = {-1, -8, 0, 5, -9};
    int n = sizeof(satisfaction) / sizeof(satisfaction[0]);

    // sort array
    sort(satisfaction, satisfaction + n);

    vector<int> suff(n);

    // making suffix array
    suff[n - 1] = satisfaction[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suff[i] = satisfaction[i] + suff[i + 1];
    }

    // finding pivot index
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (suff[i] >= 0) {
            idx = i;
            break;
        }
    }

    if (idx == -1) return 0;

    // max like-time coefficient
    int x = 1;
    int maxSum = 0;
    for (int i = idx; i < n; i++) {
        maxSum += satisfaction[i] * x;
        x++;
    }

    cout << maxSum;
}
