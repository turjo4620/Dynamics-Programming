#include <bits/stdc++.h>
using namespace std;

// you have to return the maximum sum of non-adjacent elements in the array
// like if the array is [3, 2, 7, 10] then the maximum sum of non-adjacent elements is 13 (3 + 10) and if the array is [3, 2, 5, 10, 7] then the maximum sum of non-adjacent elements is 15 (3 + 5 + 7).

//How to print a subsequence of an array in C++?
//What is a subsequence of an array?
//A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements. For example, if the array is [1, 2, 3], then the subsequences are [], [1], [2], [3], [1, 2], [1, 3], [2, 3], and [1, 2, 3].

//sublist vs subsequence
//A sublist is a contiguous portion of a list, while a subsequence is a sequence that can be derived from the list by deleting some or no elements without changing the order of the remaining elements. For example, if the list is [1, 2, 3], then the sublists are [], [1], [2], [3], [1, 2], [2, 3], and [1, 2, 3], while the subsequences are [], [1], [2], [3], [1, 2], [1, 3], [2, 3], and [1, 2, 3].

//How to print the subsequence of an array 
// recursive approach :
// take and not take approach

// int subsequence_print(int index, vector<int>& nums, vector<int>& subsequence){
//     int n = nums.size();
//     // base case - if index is greater than or equal to the size of the array, then we have reached the end of the array and we can print the subsequence
//     if(index >= n) {
//         cout << "Subsequence: ";
//         for(int i = 0; i < n; i++){ 
//             if(nums[i] != -1) cout << nums[i] << " ";
//         }
//     }
//     // take the current element and move to the next non-adjacent element
//     subsequence.push_back(nums[index]);
//     subsequence_print(index + 1, nums, subsequence);
//     // not take the current element and move to the next element
//     subsequence.pop_back();
//     subsequence_print(index + 1, nums, subsequence);    
// }
// int main(){
//     vector<int> nums = {1, 2, 3};
//     vector<int> subsequence;
//     subsequence_print(0, nums, subsequence);
//     return 0;
// }



//memorization approach : solve the problem using recursion and store the results in a dp array to avoid redundant calculations
// time complexity : O(n) - we are calculating the maximum sum of non-adjacent elements for each index only once
// space complexity : O(n) - we are using a dp array to store the maximum sum of non-adjacent elements for each index

int maximumNonAdjacentSum(int index, vector<int> &nums, vector<int> &dp){
    // base case - if the array is empty, then the maximum sum of non-adjacent elements is 0
    if(index == 0) return nums[0];

    // base case - if the index is less than 0, then we have reached the end of the array and we can return 0
    if(index < 0) return 0; 

    //pick the current element and move to the next non-adjacent element
    int pick = nums[index] + maximumNonAdjacentSum(index - 2, nums, dp);

    //not pick the current element and move to the next element
    int notPick = 0 + maximumNonAdjacentSum(index - 1, nums, dp);

    //memorization - if the value is already calculated, then return the value from the dp array
    if(dp[index] != -1) return dp[index];

    // return the maximum of the two choices
    return dp[index] = max(pick, notPick);
}

//Tabolation approach : solving the problem in a bottom-up manner by filling the dp array from index 0 to n - 1
// time complexity : O(n) - we are calculating the maximum sum of non-adjacent elements for each index only once
// space complexity : O(n) - we are using a dp array to store the maximum sum of non-adjacent elements for each index

int maximumNonAdjacentSum(vector<int> &nums){
    // base case - if the array is empty, then the maximum sum of non-adjacent elements is 0
    if(nums.size() == 0) return 0;

    // base case - if the array has only one element, then the maximum sum of non-adjacent elements is the value of that element
    if(nums.size() == 1) return nums[0];

    // create a dp array to store the maximum sum of non-adjacent elements for each index
    int n = nums.size();
    vector<int> dp(n, -1);

    // base case - the maximum sum of non-adjacent elements for the first index is the value of the first element
    dp[0] = nums[0];

    // fill the dp array using the tabulation approach
    for(int i = 1; i < n; i++){
        //pick the current element and move to the next non-adjacent element
        int pick = nums[i];
        if(i > 1) pick += dp[i - 2];

        //not pick the current element and move to the next element
        int notPick = 0 + dp[i - 1];

        // return the maximum of the two choices
        dp[i] = max(pick, notPick);
    }
    //why n - 1 ? because we are filling the dp array from index 0 to n - 1, so the last index of the dp array is n - 1
    return dp[n - 1];
}

//space optimization approach : we can optimize the space complexity of the tabulation approach by using two variables to store the maximum sum of non-adjacent elements for the previous two indices instead of using a dp array
// time complexity : O(n) - we are calculating the maximum sum of non-adjacent elements for each index only once
// space complexity : O(1) - we are using only two variables to store the maximum sum of non-adjacent elements for the previous two indices

int maximumNonAdjacentSum(vector<int> &nums){
    // base case - if the array is empty, then the maximum sum of non-adjacent elements is 0
    if(nums.size() == 0) return 0;

    // base case - if the array has only one element, then the maximum sum of non-adjacent elements is the value of that element
    if(nums.size() == 1) return nums[0];

    // create two variables to store the maximum sum of non-adjacent elements for the previous two indices
    int prev = nums[0];
    int prev2 = 0;

    // fill the dp array using the tabulation approach
    for(int i = 1; i < nums.size(); i++){
        //pick the current element and move to the next non-adjacent element
        int pick = nums[i];
        if(i > 1) pick += prev2;

        //not pick the current element and move to the next element
        int notPick = 0 + prev;

        // return the maximum of the two choices
        int curr = max(pick, notPick);

        // update the previous two variables for the next iteration
        prev2 = prev;
        prev = curr;
    }
    //why prev ? because we are updating the previous variable with the current variable for the next iteration, so at the end of the loop, the previous variable will contain the maximum sum of non-adjacent elements for the last index of the array
    return prev;
}



int main(){
    
    return 0;
}