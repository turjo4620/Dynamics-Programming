class Solution {
public:

    //Memoization
    // Time Complexity: O(n) - we are calculating the Fibonacci number for each index only once
    // Space Complexity: O(n) - we are using a dp array to store the Fibonacci number for each index

    // int helper(int n, vector<int>&dp){
    //     if(n <= 1){
    //         return n;
    //     }
    //     if(dp[n] != -1){
    //         return dp[n];
    //     }
    //     return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    // }
    // int fib(int n) {
    //     if(n <= 1){
    //         return n;
    //     }
    //     vector<int>dp(n + 1, -1);
    //     return helper(n, dp);
    // }

    //Tabulation
    // Time Complexity: O(n) - we are calculating the Fibonacci number for each index only
    // Space Complexity: O(n) - we are using a dp array to store the Fibonacci number for each index

        // int fib(int n) {
        // vector<int>dp(n + 1, 0);
        // if(n <= 1){
        //     return n;
        // }
        // dp[0] = 0;
        // dp[1] = 1;
        // for(int i = 2; i <= n; i++){
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // }
        // return dp[n];
    // }

    //Space Optimization
    // Time Complexity: O(n) - we are calculating the Fibonacci number for each index only
    // Space Complexity: O(1) - we are using only two variables to store the Fibonacci number for the previous two indices
    
        int fib(int n) {
        if(n <= 1){
            return n;
        }
        int prev2 = 0, prev = 1;
        for(int i = 2; i <= n; i++){
            int curr = prev2 + prev;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};