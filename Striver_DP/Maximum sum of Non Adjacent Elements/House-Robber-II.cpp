// Reference: https://www.youtube.com/watch?v=3WaxQMELSkw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=7
// https://leetcode.com/problems/house-robber-ii/description/ 

class Solution {
public:
    int maxSub(vector<int> &nums){
        int prev = nums[0];
        int prev2 = 0;
        int pick, notpick, curi;
        for(int i = 1; i < nums.size(); i++){
            if(i-2>=0)pick = nums[i] + prev2;
            else pick = nums[i];
        notpick = 0 + prev;
        curi = max(pick, notpick);
        prev2 = prev;
        prev = curi;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
           vector<int>temp1,temp2;
           int n = nums.size();
           if(n==1)return nums[0];
           for(int i=0;i<n;i++){
               if(i != 0) temp1.push_back(nums[i]);
               if(i != n-1) temp2.push_back(nums[i]);
            }
        return max(maxSub(temp1), maxSub(temp2));    
    }
};
