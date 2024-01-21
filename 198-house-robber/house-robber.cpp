class Solution {
public:
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

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return maxSub(nums, dp);  
    }
};