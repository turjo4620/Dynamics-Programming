#include <bits/stdc++.h>

using namespace std;

int main(){
    
    Solution obj;

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "Length of LIS: " << obj.lengthOfLIS(nums) << endl;

    return 0;
}


class Solution {
public:
    int helper(int index, int prev, vector<int>&nums, vector<vector<int>>&dp){
        int n = nums.size();
        if(index == n){
            return 0;
        }
        if(dp[index][prev + 1] != -1) return dp[index][prev + 1];

        int not_take = helper(index + 1, prev, nums, dp);

        int take = 0;  
        if(prev == -1 || nums[index] > nums[prev]){
            take = 1 + helper(index + 1, index, nums, dp);
        }

        int len = max(take, not_take);
        return dp[index][prev + 1] = len;

    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return helper(0, -1, nums, dp);
    }
};