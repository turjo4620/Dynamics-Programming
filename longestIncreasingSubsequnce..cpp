#include <bits/stdc++.h>

using namespace std;


int longestIncreasingSubsequence(int index, int prev, vector<int>&vec){
    if(index == vec.size()){
        return 0;
    }
    vector<vector<int>>dp(vec.size(), vector<int>(-1, vec.size() + 1));
    if(dp[index][prev+1] != -1)return dp[index][prev + 1];

    int not_take = longestIncreasingSubsequence(index + 1, prev, vec);
    int take;
    if(prev != -1 || vec[index] > vec[prev]){
        take = 1 + longestIncreasingSubsequence(index + 1, index, vec);
    }
    int len = max(not_take, take);
    return dp[index][prev + 1] = len;
}


int main(){
    
    return 0;
}