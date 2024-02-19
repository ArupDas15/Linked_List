class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        int sum = 0;
        bool negflg = true;

        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                negflg = false;
                break;
            } else {
                maxi = max(maxi, nums[i]);
            }
        }
        if(negflg) return maxi;

        for(int i = 0; i < n; i++) {
            sum = sum + nums[i];
            if(sum < 0) sum = 0;
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};