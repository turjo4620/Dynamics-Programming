#include <bits/stdc++.h>

using namespace std;

/*
Question : coin change problem : given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money, return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1. You may assume that you have an infinite number of each kind of coin.
input: coins = [1,2,5], amount = 11
output: 3
explanation: 11 = 5 + 5 + 1
*/

// recursive + memoization

int CoinChange(const vector<int> &coins, int index, int amount, vector<vector<int>> &dp) {
    if(amount == 0) {
        return 0;
    }
    if(index < 0) {
        return INT_MAX;
    }

    if(dp[index][amount] != -1) {
        return dp[index][amount];
    }


    int not_take = CoinChange(coins, index - 1, amount, dp);
    int take = INT_MAX;
    int checker = CoinChange(coins, index, amount - coins[index], dp);
    if(coins[index] <= amount && checker != INT_MAX) {
        take = 1 + checker;
    }
    return dp[index][amount] = min(take, not_take);
}

int main(){
    
    vector<int> coins = {1, 2, 5};
    int amount = 11;    
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = CoinChange(coins, n - 1, amount, dp);
    if(ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }   

    return 0;
}


// time complexity : O(n * amount)
// space complexity : O(n * amount) + O(amount) for recursive stack space

// tabulation

int CoinChangeTabulation(const vector<int> &coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));

    for(int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }

    for(int j = 1; j <= amount; j++) {
        if(j % coins[0] == 0) {
            dp[0][j] = j / coins[0];
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= amount; j++) {
            int not_take = dp[i - 1][j];
            int take = INT_MAX;
            if(coins[i] <= j && dp[i][j - coins[i]] != INT_MAX) {
                take = 1 + dp[i][j - coins[i]];
            }
            dp[i][j] = min(take, not_take);
        }
    }

    return dp[n - 1][amount] == INT_MAX ? -1 : dp[n - 1][amount];
}

// time complexity : O(n * amount)
// space complexity : O(n * amount)
