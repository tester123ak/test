#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Initialize the DP table
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == a[n - j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Length of the longest palindromic subsequence
    int lps_length = dp[n][n];
    cout << "The length of the longest palindromic subsequence is: " << lps_length << endl;

    // Reconstruct the longest palindromic subsequence
    vector<int> lps;
    int i = n, j = n;
    while (i > 0 && j > 0) {
        if (a[i - 1] == a[n - j]) {
            lps.push_back(a[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Print the longest palindromic subsequence
    cout << "The longest palindromic subsequence is: that the particular  ";
    for (int k = lps.size() - 1; k >= 0; k--) {
        cout << lps[k] << " ";
    }
    cout << endl;

    return 0;
}