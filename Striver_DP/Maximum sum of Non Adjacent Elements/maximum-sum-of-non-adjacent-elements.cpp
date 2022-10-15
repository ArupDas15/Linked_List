// Problem: https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
// Recursive solution
/*
#include <bits/stdc++.h> 
int maxSub(int idx,vector<int> &nums){
    if(idx==0)return nums[idx]; // Base case
    if(idx<0)return 0; // Base case
    //pick
    int pick = nums[idx] + maxSub(idx-2,nums);
    //not pick
    int notpick = maxSub(idx-1,nums);
    return max(pick, notpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int idx = nums.size()-1;
    int sum = 0;
    int maxSum = INT_MIN;
    return maxSub(idx, nums);
}
*/
// Memoization
/*
#include <bits/stdc++.h> 
int maxSub(int idx,vector<int> &nums,vector<int>&dp){
    if(idx==0)return nums[idx];
    if(idx<0)return 0;
    if(dp[idx]!=-1)return dp[idx];
    //pick
    int pick = nums[idx] + maxSub(idx-2,nums,dp);
    //not pick
    int notpick = maxSub(idx-1,nums,dp);
    return dp[idx] = max(pick, notpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int idx = nums.size()-1;
    int sum = 0;
    int maxSum = INT_MIN;
    vector<int>dp(nums.size(),-1);
    return maxSub(idx, nums,dp);
}
*/
// Tabulation
/*
#include <bits/stdc++.h> 
int maxSub(vector<int> &nums,vector<int>&dp){
    dp[0] = nums[0];
    
    int pick = 0, notpick = 0;
    for(int i = 1; i < nums.size(); i++){
        if(i-2>=0)
             pick = nums[i] + dp[i-2];
        else 
            pick = nums[i];
        notpick = 0 + dp[i-1];
        dp[i] = max(pick, notpick);
    }
    return dp[nums.size()-1];
}
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int>dp(nums.size(),-1);
    return maxSub(nums, dp);
}
*/

// Space optimisation
// time complexity: O(n)
// space complexity: O(1)
#include <bits/stdc++.h> 
int maxSub(vector<int> &nums,vector<int>&dp){
    int prev = nums[0];
    int prev2 = 0;
    int pick, notpick, curi;
    for(int i = 1; i < nums.size(); i++){
        if(i-2>=0)
             pick = nums[i] + prev2;
        else 
            pick = nums[i];
        notpick = 0 + prev;
        curi = max(pick, notpick);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int>dp(nums.size(),-1);
    return maxSub(nums, dp);
}
