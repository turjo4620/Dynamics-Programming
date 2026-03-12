#include <bits/stdc++.h>
using namespace std;


/*
Question : given three strings s1, s2 and s3, return true if s3 is an interleaving of s1 and s2, and false otherwise. An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:
    s = s1 + s2 + ... + sn
    t = t1 + t2 + ... + tm
    |n - m| <= 1
    The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
output: true
explanation: One way to obtain s3 is:
- Take "aa" from s1 and "d" from s2. Now we have "aad".
- Take "b" from s1 and "bb" from s2. Now we have "aadbb".
- Take "c" from s1 and "c" from s2. Now we have "aadbbcc".
- Take "a" from s1 and "a" from s2. Now we have "aadbbcbca".
- Take "c" from s1. Now we have "aadbbcbcac".   
*/



class Solution {
public:

    bool helper(const string &s1, const string &s2, const string &s3,
        int i, int j, vector<vector<int>> &dp) {

        if(i == s1.size() && j == s2.size()) {
            return true;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int k = i + j;
        bool ans = false;

        if(i < s1.size() && s1[i] == s3[k]) {
            ans = ans || helper(s1, s2, s3, i + 1, j, dp);
        }

        if(j < s2.size() && s2[j] == s3[k]) {
            ans = ans || helper(s1, s2, s3, i, j + 1, dp);
        }

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {

        int n = s1.size();
        int m = s2.size();

        if(n + m != s3.size()) {
            return false;
        }

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return helper(s1, s2, s3, 0, 0, dp);
    }
};

int main() {

    Solution sol;

    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";

    cout << sol.isInterleave(s1, s2, s3) << endl;

    return 0;
}