#include <bits/stdc++.h>

using namespace std;

//question : given a string s, return the longest palindromic substring in s.
//input: s = "babad"
//output: "aba"
//explanation: "aba" is a palindrome substring of "babad" and it is the longest one. Note that "aba" is also a valid answer.


class Solution {
public:
    string longestPalindrome(string s) {

        string rev = s;
        reverse(rev.begin(), rev.end());

        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        int longestLen = 0;
        string longest = "";

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){

                if(s[i - 1] == rev[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                    int len = dp[i][j];

                    int start_original = i - len;
                    int start_reverse  = n - j;

                    // important validation
                    if(start_original == start_reverse){
                        if(len > longestLen){
                            longestLen = len;
                            longest = s.substr(start_original, len);
                        }
                    }
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }

        return longest;
    }
};

int main(){
    
    return 0;
}

//video dekha lagbe re