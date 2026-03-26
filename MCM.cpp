#include <bits/stdc++.h>

using namespace std;

long long f(int i, int j, vector<int>&value, vector<vector<long long>>&dp){
    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    long long min_steps = INT_MAX;

    for(int k = i; k <= j- 1; k++){
        long long steps = value[i - 1] * value[k] * value[j] + f(i, k, value, dp) + f(k + 1, j, value, dp);
        min_steps = min(min_steps, steps);
    }

    return dp[i][j] = min_steps;

}

int MCM(vector<int>&arr, int N){

    vector<vector<long long>>dp(N, vector<long long>(N, -1));
    return f(1, N-1, arr, dp);
}



int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        vec[i] = a;
    }
    cout<<MCM(vec, n);
   
    return 0;
}