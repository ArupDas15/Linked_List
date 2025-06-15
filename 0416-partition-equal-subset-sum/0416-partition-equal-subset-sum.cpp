class Solution {
public:
    bool subSetSum(vector<int>& nums, int target, int ind, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (ind == 0) return nums[ind] == target;
        if (dp[ind][target] != -1) return dp[ind][target];

        bool notTaken = subSetSum(nums, target, ind-1, dp);
        bool Taken = false;

        if (nums[ind] <= target) {
            Taken = subSetSum(nums, target - nums[ind], ind-1, dp);
        }
        return dp[ind][target] = Taken | notTaken;
    }
    bool canPartition(vector<int>& nums) {
        int S = accumulate(nums.begin(), nums.end(), 0);
        if (S % 2 == 1) return false;
        S = S / 2;
        vector<vector<int>> dp (nums.size(), vector<int>(S+1, -1));

        return subSetSum(nums, S, nums.size()-1, dp);
    }
};