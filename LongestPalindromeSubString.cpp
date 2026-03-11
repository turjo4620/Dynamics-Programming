#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Approach : Dynamic Programming
    // Time Complexity: O(n^2) - we are calculating the longest palindrome substring for each index and for each index we are checking for the longest palindrome substring by expanding around the center
    // Space Complexity: O(n^2) - we are using a dp array to store the longest palindrome substring for each index
    //Memorization approach : solve the problem using recursion and store the results in a dp array to avoid redundant calculations
    // string longestPalindrome(string s) {
    //     vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    //     string longest = "";
    //     for(int i = 0; i < s.size(); i++){
    //         dp[i][i] = true;
    //         longest = s[i];
    //     }
    //     for(int i = s.size() - 1; i >= 0; i--){
    //         for(int j = i + 1; j < s.size(); j++){
    //             if(s[i] == s[j]){
    //                 if(j - i == 1 || dp[i + 1][j - 1]){
    //                     dp[i][j] = true;
    //                     if(longest.size() < j - i + 1){
    //                         longest = s.substr(i, j - i + 1);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return longest;

    // }

    //Tabulation approach : solving the problem in a bottom-up manner by filling the dp array from index 0 to n - 1
    // Time Complexity: O(n^2) - we are calculating the longest palindrome substring for each index and for each index we are checking for the longest palindrome substring by expanding around the center
    // Space Complexity: O(n^2) - we are using a dp array to store the longest palindrome substring for each index
        string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        string longest = "";
        for(int i = 0; i < s.size(); i++){
            dp[i][i] = true;
            longest = s[i];
        }
        for(int i = s.size() - 1; i >= 0; i--){
            for(int j = i + 1; j < s.size(); j++){
                if(s[i] == s[j]){
                    if(j - i == 1 || dp[i + 1][j - 1]){
                        dp[i][j] = true;
                        if(longest.size() < j - i + 1){
                            longest = s.substr(i, j - i + 1);
                        }
                    }
                }
            }
        }
        return longest;
    }
};