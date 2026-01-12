#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, p, q;

    cout << "Enter rows of 1st matrix: ";
    cin >> n;
    cout << "Enter columns of 1st matrix: ";
    cin >> m;

    cout << "Enter rows of 2nd matrix: ";
    cin >> p;
    cout << "Enter columns of 2nd matrix: ";
    cin >> q;

    if (m != p) {
        cout << "Matrix can't be multiplied (columns of 1st != rows of 2nd)" << endl;
        return 0;
    }
    // Declare matrices
    int a[n][m], b[p][q], res[n][q];

    cout << "Enter elements of 1st matrix:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    cout << "Enter elements of 2nd matrix:" << endl;
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
            cin >> b[i][j];

    // Initialize result matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < q; j++)
            res[i][j] = 0;

    // Matrix multiplication
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < m; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    // Print result
    cout << "Resultant matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}