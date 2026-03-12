#include <bits/stdc++.h>

using namespace std;

//question : given a rod of length n and an array price[] of size n, where price[i] is the price of a rod of length i + 1, return the maximum profit that can be obtained by cutting the rod and selling the pieces. You can cut the rod in any number of pieces and sell them. You can also sell the rod without cutting it.
//input: n = 4, price = [1, 5, 8,
//9]
//output: 10
//explanation: We can cut the rod into two pieces of length 2 and 2 and sell them to get a profit of 5 + 5 = 10. We can also cut the rod into four pieces of length 1 and sell them to get a profit of 1 + 1 + 1 + 1 = 4. We can also sell the rod without cutting it to get a profit of 8. So, the maximum profit that can be obtained is 10.

//approach 1: Recursion
// Time Complexity: O(2^n) - we are calculating the Fibonacci number for each index multiple times
// Space Complexity: O(n) - we are using a recursive stack to calculate the Fibonacci number for each index

int rodCutting(int n, vector<int>& price) {
    if(n <= 0){
        return 0;
    }
    int maxProfit = INT_MIN;

    for(int i = 1; i <= n; i++){
        maxProfit = max(maxProfit, price[i] + rodCutting(n - i, price));
    }
    return maxProfit;
}

//approach 2: Memoization
// Time Complexity: O(n^2) - we are calculating the Fibonacci number for each index only once and for each index we are iterating through all the possible cuts
// Space Complexity: O(n) - we are using a dp array to store the Fibonacci number for each index and a recursive stack to calculate the Fibonacci number for each index

int rodCuttting(int n, vector<int>& price, vector<int> &dp){
    if(n == 0){
        return 0;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int maxProfit = INT_MIN;

    for(int j = 1; j <= n; j++){
        maxProfit = max(maxProfit, price[j] + rodCuttting(n - j, price, dp));
    }

    return dp[n] = maxProfit;
}


//approach 3: Tabulation
// Time Complexity: O(n^2) - we are calculating the Fibonacci number for each index
// Space Complexity: O(n) - we are using a dp array to store the Fibonacci number for each index

int rodCuttingTabulation(int n, vector<int>& price){
    vector<int>dp(n + 1, 0);

    // why n + 1 ? because we are using 1-based indexing for the price array and we want to store the maximum profit for each index from 0 to n

    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        int maxProfit = INT_MIN;
        for(int j = 1; j <= i; j++){
            maxProfit = max(maxProfit, price[j] + dp[i - j]);
        }
    }

}




int main(){
    
    return 0;
}