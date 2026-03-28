#include <bits/stdc++.h>

using namespace std;

/*
question: given two arrays weight[] and value[] of size n, where weight[i] is the weight of the ith item and value[i] is the value of the ith item, and an integer capacity, return the maximum value that can be obtained by putting items in a knapsack of capacity. You can either include the item in the knapsack or exclude it from the knapsack. You cannot include the same item more than once.
input: n = 4, weight = [2, 3, 4,5], value = [3, 4, 5, 6], capacity = 5
output: 7
explanation: We can include the first item and the second item in the knapsack to get a total weight of 2 + 3 = 5 and a total value of 3 + 4 = 7. We can also include the third item in the knapsack to get a total weight of 4 and a total value of 5. We can also include the fourth item in the knapsack to get a total weight of 5 and a total value of 6. So, the maximum value that can be obtained is 7.

*/


//approach 1: Recursion
// Time Complexity: O(2^n) - we are calculating the Fibonacci number for each index multiple times
// Space Complexity: O(n) - we are using a recursive stack to calculate the Fibonacci number for each index 

// int knapsack(int n, vector<int>& weight, vector<int>& value, int capacity) {
//     if(n == 0){
//         if(capacity >= weight[0]){
//             return value[0];
//         }
//         else{
//             return 0;
//         }
//     }
//     int not_take = knapsack(n - 1, weight, value, capacity);
//     int take = INT_MIN;
//     if(capacity >= weight[n]){
//         take = value[n] + knapsack(n - 1, weight, value, capacity - weight[n]);
//     }
//     return max(take, not_take);

// }

// //approach 2: Memoization

int knapsackMemoization(int n, vector<int>& weight, vector<int>& value, int capacity, vector<vector<int>>& dp) {
    if(n == 0){
        if(capacity >= weight[0]){
            return value[0];
        }
        else{
            return 0;
        }
    }
    if(dp[n][capacity] != -1){
        return dp[n][capacity];
    }
    int not_take = knapsackMemoization(n - 1, weight, value, capacity, dp);
    int take = INT_MIN;
    if(capacity >= weight[n]){
        take = value[n] + knapsackMemoization(n - 1, weight, value, capacity - weight[n], dp);
    }
    return dp[n][capacity] = max(take, not_take);

}


//approach 3: Tabulation

int knapsackTabulation(int n, vector<int>& weight, vector<int>& value, int capacity, vector<vector<int>> &dp) {
    
    for(int w = weight[0]; w <= capacity; w++){
        dp[0][w] = value[0];
    }


    for(int i = 1; i < n; i++){
        for(int j = 0; j <= capacity; j++){
            int not_take = dp[i - 1][j];
            int take = INT_MIN;
            if(j >= weight[i]){
                take = value[i] + dp[i - 1][j - weight[i]];
            }
            dp[i][j] = max(take, not_take);
        }
    }

    return dp[n - 1][capacity];
}


int main(){
    int n; 
    cin>>n;
    vector<int>value(n);
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        value[i] = a;
    }
    int w;
    cin>>w;
    vector<int>weight(w);
    for(int i = 0; i < w; i++){
        int b; 
        cin>>b;
        weight[i] = b;
    }
    int capacity;
    cin>>capacity;
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    cout<<knapsackTabulation(n, weight, value,capacity, dp);
    cout<<endl<<endl;
    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[0].size(); j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}