class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, res = INT_MAX;

        for(int left = 0, right  = 0; right < nums.size() && left <= right; right++) {
            sum = sum + nums[right];
            while(sum >= target) {
                res = min(res, right - left + 1);
                sum = sum - nums[left];
                left++;
            }
        }
        return res == INT_MAX?0:res;
    }
};