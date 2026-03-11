#include <bits/stdc++.h>

using namespace std;


// question : given a string s, return the minimum number of insertions needed to make s a palindrome.
//intput: s = "abc"
//output: 2
//explanation: we can insert 'b' and 'a' at the end of the string to make it a palindrome "abcba" or we can insert 'c' and 'b' at the beginning of the string to make it a palindrome "cbabc".


// solution : we can find the longest palindromic subsequence of the string and then subtract the length of the longest palindromic subsequence from the length of the string to get the minimum number of insertions needed to make the string a palindrome.

//explanation : the longest palindromic subsequence of the string is the longest subsequence of the string that is a palindrome. For example, if the string is "abc", then the longest palindromic subsequence is "a" or "b" or "c" and the length of the longest palindromic subsequence is 1. So, the minimum number of insertions needed to make the string a palindrome is 3 - 1 = 2.
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
    int minInsertions(string s) {

        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int longestPalindromicSubseq = longestPalindromeSubseq(s, rev, n - 1, n - 1, dp);
        return n - longestPalindromicSubseq;
        
    }
};





int main(){
    
    return 0;
}