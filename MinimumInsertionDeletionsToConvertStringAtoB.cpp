#include <bits/stdc++.h>

using namespace std;

//Question: Given two strings text1 and text2, return the minimum number of steps required to make text1 and text2 the same. In one step, you can delete exactly one character in either string or insert exactly one character in either string.
//intput: text1 = "sea", text2 = "eat"
//output: 2
//Explanation: You can delete 's' from "sea" to get "ea", then insert 't' to get "eat".


int LongestCommonSubsequence(string tex1, string text2, int i, int j, vector<vector<int>>& dp){
    if(i < 0 || j < 0){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(tex1[i] == text2[j]){
        return dp[i][j] = 1 + LongestCommonSubsequence(tex1, text2, i - 1, j - 1, dp);
    }
    return dp[i][j] = max(LongestCommonSubsequence(tex1, text2, i - 1, j, dp), LongestCommonSubsequence(tex1, text2, i, j - 1, dp));
}

int minInsertionsDeletions(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    //2d vector we need here 
    //vector<vector<int>>dp(n, vector<int>(m1, -1)); because we need to store the longest common subsequence for each index of text1 and text2 to avoid redundant calculations
    int longestCommonSubsequence = LongestCommonSubsequence(text1, text2, n - 1, m - 1, dp);
    int insertions = m - longestCommonSubsequence;
    int deletions = n - longestCommonSubsequence;

    return insertions + deletions;
}


int main(){
    
    return 0;
}