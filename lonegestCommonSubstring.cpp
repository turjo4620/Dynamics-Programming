#include <bits/stdc++.h>

using namespace std;

int LongestCommonSubstring(const string &text1, const string &text2, int i, int j, vector<vector<int>>& dp){
    if( i == 0 || j == 0){
        return 0;
    }
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
}

int main(){

    
    
    return 0;
}