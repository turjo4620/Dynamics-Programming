#include <bits/stdc++.h>

using namespace std;

int unboundedKnapsack(int n, int max_weight, vector<int>&value, vector<int>&weight, vector<vector<int>>&dp){
    if(n == 0){
        return (int)(max_weight / weight[0]) * value[0]; 
    }

    if(dp[n][max_weight] != -1)return dp[n][max_weight];

    int not_take = 0 + unboundedKnapsack(n - 1, max_weight, value, weight, dp);
    int take = INT_MIN;
    if(weight[n] <= max_weight){
        take = value[n] + unboundedKnapsack(n, max_weight - weight[n], value, weight, dp);
    }
    return dp[n][max_weight] = max(take, not_take);

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
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    cout<<unboundedKnapsack(n - 1, capacity, value,weight, dp); 
    cout<<endl<<endl;


    return 0;
}