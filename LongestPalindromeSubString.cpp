
#include <bits/stdc++.h>

using namespace std;

int main(){
    
    return 0;
}

string longestPalindromeDP(const string& s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    int start = 0, maxLen = 1;

    // All single chars are palindromes
    for (int i = 0; i < n; i++) dp[i][i] = true;

    // Check pairs
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i+1]) {
            dp[i][i+1] = true;
            start = i;
            maxLen = 2;
        }
    }

    // Check lengths 3 and above
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
                if (len > maxLen) {
                    start = i;
                    maxLen = len;
                }
            }
        }
    }

    return s.substr(start, maxLen);
}