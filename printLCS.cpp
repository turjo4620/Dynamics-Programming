#include <bits/stdc++.h>

using namespace std;


//question : given two strings text1 and text2, return the longest common subsequence of text1 and text2. If there is no common subsequence, return an empty string "".
//input: text1 = "abcde", text2 = "ace"
//output: "ace"
//explanation: The longest common subsequence of text1 and text2 is "ace"   

//solution : we can use dynamic programming to solve this problem. We can create a dp array of size (m + 1) x (n + 1) where m is the length of text1 and n is the length of text2. The value of dp[i][j] will be the length of the longest common subsequence of text1[0...i-1] and text2[0...j-1]. We can fill the dp array using the following rules:
    // if text1[i - 1] == text2[j - 1], then dp[i][j] = 1 + dp[i - 1][j - 1]
    // else, dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) 
    // After filling the dp array, the length of the longest common subsequence will be stored in dp[m][n]. We can then backtrack through the dp array to find the longest common subsequence string.

// Tabolation approach : solving the problem in a bottom-up manner by filling the dp array from index 0 to m - 1 and from index 0 to n - 1
// Time Complexity: O(m*n) - we are calculating the longest common subsequence for  each index of text1 and text2 only once
// Space Complexity: O(m*n) - we are using a dp array to store the  longest common subsequence for each index of text1 and text2        

string printLCS(const string &text1, const string &text2, int i, int j, vector<vector<int>>&dp){
    string lcs = "";
    if(i < 0 || j < 0){
        return lcs;
    }

    int n = text1.size(), m = text2.size();
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j <= m; j++){
        dp[0][j] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(text1[i - 1] == text2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int len = dp[n][m];
    for(int i = 0; i < len; i++){
        lcs += '$';
    }
    int index = len - 1;
    i = n, j = m;

    //backtracking through the dp array to find the longest common subsequence string
    
    while(i > 0 && j > 0){
        if(text1[i - 1] == text2[j - 1]){
            lcs[index] = text1[i - 1];
            index--;
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){
            i--;
        }
        else{
            j--;
        }
    }
    return lcs;

}
int main(){
    
    return 0;
}