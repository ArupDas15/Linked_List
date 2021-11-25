class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];
        for(int i=0;i<nums.size();i++){
            if (sum < 0){
                sum = 0;
            }
            if (sum + nums[i] > maxi){
                maxi = sum+nums[i];
            }
            sum += nums[i];
        }
        return maxi;
    }
};