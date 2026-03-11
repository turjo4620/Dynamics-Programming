#include <bits/stdc++.h>

using namespace std;

int main(){
    
    return 0;
}


class Solution {
public:

    //Memoization approach : solve the problem using recursion and store the results in a dp array to avoid redundant calculations
    // Time Complexity: O(m*n) - we are calculating the longest common subsequence for each index of text1 and text2 only once
    // Space Complexity: O(m*n) - we are using a dp array to store the longest common subsequence for each index of text1 and text2
    int helper(const string &text1, const string &text2, int i, int j, vector<vector<int>>& dp){

        //Base case : if we have reached the end of either text1 or text2, then the longest common subsequence is 0 because we cannot have a common subsequence if one of the strings is empty  
        if(i < 0 || j < 0){
            return 0;
        }

        //If we have already calculated the longest common subsequence for the current index of text1 and text2, then we can return the result from the dp array to avoid redundant calculations    
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //If the characters at the current index of text1 and text2 are the same, then we can include that character in the longest common subsequence and move to the next index of both text1 and text2
        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + helper(text1, text2, i - 1, j - 1, dp);
        }

        //If the characters at the current index of text1 and text2 are different, then we can either exclude the character at the current index of text1 and move to the next index of text1 or we can exclude the character at the current index of text2 and move to the next index of text2 and take the maximum of both options
        return dp[i][j] = max(helper(text1, text2, i - 1, j, dp), helper(text1, text2, i, j - 1, dp));
    }

    //Main function to calculate the longest common subsequence of text1 and text2
    // Time Complexity: O(m*n) - we are calculating the longest common subsequence for  each index of text1 and text2 only once
    // Space Complexity: O(m*n) - we are using a dp array to store the longest common subsequence for each index of text1 and text2
    int longestCommonSubsequence(string text1, string text2) {
        //We are using a dp array to store the longest common subsequence for each index of text1 and text2 to avoid redundant calculations
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));

        //We are calling the helper function to calculate the longest common subsequence for the last index of text1 and text2 because we want to calculate the longest common subsequence for the entire strings
        return helper(text1, text2, text1.size() - 1, text2.size() - 1, dp);
    }


    //Tabulation approach : solving the problem in a bottom-up manner by filling the dp array from index 0 to m - 1 and from index 0 to n - 1
    // Time Complexity: O(m*n) - we are calculating the longest common subsequence for  each index of text1 and text2 only once
    // Space Complexity: O(m*n) - we are using a dp array to store the  longest common subsequence for each index of text1 and text2
        int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
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
        return dp[n][m];
    }
};