#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int minInsertionsToAlphabetical(const string& s) {
    string target = "abcdefghijklmnopqrstuvwxyz";
    int n = s.size(), m = target.size();
    
    // Initialize DP table
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // Fill DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == target[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // LCS length is dp[n][m]
    int lcsLength = dp[n][m];
    return 26 - lcsLength;
}

int main() {
    // Test cases
    string s1 = "xyzabcdefghijklmnopqrstuvw";
    string s2 = "aiemckgobjfndlhp";
    
    cout << minInsertionsToAlphabetical(s1) << endl; // Output: 3
    cout << minInsertionsToAlphabetical(s2) << endl; // Output: 20
    
    return 0;
}
