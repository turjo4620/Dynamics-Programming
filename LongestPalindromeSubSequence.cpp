#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int longestPalindromeSubseq(const string &text1, const string &text2, int i, int j, vector<vector<int>>& dp){

        if(i < 0 || j < 0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + longestPalindromeSubseq(text1, text2, i - 1, j - 1, dp);
        }

        return dp[i][j] = max(longestPalindromeSubseq(text1, text2, i - 1, j, dp), longestPalindromeSubseq(text1, text2, i, j - 1, dp));
        
    }

    int longestPalindromeSubseq(string s) {
        string org = s;
        reverse(s.begin(), s.end());
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return longestPalindromeSubseq(org, s, org.size() - 1, s.size() - 1, dp);
    }
};


int main(){

    return 0;
}