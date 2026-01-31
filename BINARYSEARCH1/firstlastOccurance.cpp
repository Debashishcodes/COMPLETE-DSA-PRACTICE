#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,2,3,3,3,3,3,4,4,5,5,9};
    int n = 13;
    int x = 3; // target

    // -------- FIRST OCCURRENCE --------
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            first = mid;          // possible answer
            high = mid - 1;       // move left to find earlier occurrence
        } 
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    // -------- LAST OCCURRENCE --------
    low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            last = mid;           // possible answer
            low = mid + 1;        // move right to find later occurrence
        } 
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << "First Occurrence: " << first << endl;
    cout << "Last Occurrence: " << last << endl;
}
