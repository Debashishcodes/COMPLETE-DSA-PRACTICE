#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    int n = arr.size();
    stack<int> st;
    int ngi[n];

    ngi[n-1] = n;
    st.push(n-1);

    for(int i = n-2; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        if(st.empty()) ngi[i] = n;
        else ngi[i] = st.top();

        st.push(i);
    }

    vector<int> ans;

    for(int i = 0; i <= n-k; i++) {
        int maxVal = arr[i];
        int j = i;

        while(j < i + k) {
            maxVal = arr[j];
            j = ngi[j];
        }

        ans.push_back(maxVal);
    }

    return ans;
}

int main() {
    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter window size k: ";
    cin >> k;

    vector<int> result = maxSlidingWindow(arr, k);

    cout << "Sliding Window Maximums:\n";
    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}