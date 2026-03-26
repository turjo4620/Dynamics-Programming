#include <bits/stdc++.h>

using namespace std;

//question : given a string s, return the minimum number of insertions needed to make s a palindrome.
//intput: s = "abc"
//output: 2
//explanation: we can insert 'b' and 'a' at the end of the string to make it a palindrome "abcba" or we can insert 'c' and 'b' at the beginning of the string to make it a palindrome "cbabc".

class Solution {
public:

    //helper function to find longest common subsequence between two strings (used for LPS)
    int longestCommonSubseq(const string &text1, const string &text2, int i, int j, vector<vector<int>>& dp){

        if(i < 0 || j < 0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + longestCommonSubseq(text1, text2, i - 1, j - 1, dp);
        }

        return dp[i][j] = max(longestCommonSubseq(text1, text2, i - 1, j, dp), longestCommonSubseq(text1, text2, i, j - 1, dp));
        
    }

    //function to calculate longest palindromic subsequence
    int longestPalindromeSubseq(string s) {
        string org = s;
        reverse(s.begin(), s.end()); //reverse string to use LCS
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return longestCommonSubseq(org, s, org.size() - 1, s.size() - 1, dp);
    }

    //function to calculate minimum insertions to make palindrome
    int minInsertions(string s){
        int lps = longestPalindromeSubseq(s); //longest palindromic subsequence length
        return s.size() - lps; //minimum insertions = length of string - LPS
    }
};

int main(){
    Solution sol;

    string s = "abc";
    cout << "Minimum insertions to make \"" << s << "\" a palindrome: " << sol.minInsertions(s) << endl;

    s = "aebcbda";
    cout << "Minimum insertions to make \"" << s << "\" a palindrome: " << sol.minInsertions(s) << endl;

    return 0;
}