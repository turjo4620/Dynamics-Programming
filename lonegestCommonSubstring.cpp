#include <bits/stdc++.h>

using namespace std;

//question : given two strings text1 and text2, return the longest common subsequence of text1 and text2. If there is no common subsequence, return an empty string "".
//input: text1 = "abcde", text2 = "ace"
//output: "ace"
//explanation: The longest common subsequence of text1 and text2 is "ace"
//substring : a substring is a contiguous sequence of characters within a string. For example, in the string "abcde", "abc" is a substring, but "ace" is not a substring because it is not contiguous. The longest common substring of text1 and text2 is the longest contiguous sequence of characters that appears in both strings. For example, if text1 = "abcde" and text2 = "ace", then the longest common substring is "a" because it is the longest contiguous sequence of characters that appears in both strings.


int LongestCommonSubstring(const string &text1, const string &text2, vector<vector<int>>& dp){
    int n = text1.size(), m = text2.size();

    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j <= m; j++){
        dp[0][j] = 0;
    }

    int longest = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(text1[i - 1] == text2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                longest = max(longest, dp[i][j]);
            }
            else{
                //as this is substring, we can't break it and continue, we have to start from the beginning of the substring, so we will set the dp value to 0
                dp[i][j] = 0;
            }
        }
    }

    return longest;
}

int main(){

    string text1 = "abcde";
    string text2 = "ace";

    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int result = LongestCommonSubstring(text1, text2, dp);

    cout << result << endl;

    return 0;
}