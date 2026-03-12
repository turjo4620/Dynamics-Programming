#include <bits/stdc++.h>

using namespace std;

/* 
Question : given two strings text1 and text2, return the minimum number of steps required to make text1 and text2 the same. In one step, you can delete exactly one character in either string or insert exactly one character in either string.
intput: text1 = "sea", text2 = "eat"
output: 2
Explanation: You can delete 's' from "sea" to get "ea", then insert 't' to get "eat".

*/


class Solution {
public:
    int longestCommonSubsequence(string s1, string s2, int i, int j, vector<vector<int>>&dp){
        if(i < 0 || j < 0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + longestCommonSubsequence(s1, s2, i - 1, j - 1, dp);
        }
        
        return dp[i][j] = max(longestCommonSubsequence(s1, s2, i - 1, j, dp), longestCommonSubsequence(s1, s2, i, j - 1, dp));
    }

    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        int lcs = longestCommonSubsequence(word1, word2, m - 1 , n - 1, dp);
        if(m == lcs){
            return n - m;
        }
        else if(n == lcs){
            return m - n;
        }
        else{
            return m + n - 2*lcs;
        }
    }
};


int main(){
    
    return 0;
}