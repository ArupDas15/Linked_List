class Solution {
public:
    int maxCrossSubArraySum(vector<int>& nums, int l, int r, int mid) {
        int temp_sum = 0;
        int cross_sum = 0;
        int max_left_sub_sum = INT_MIN;
        int max_right_sub_sum = INT_MIN;

        for(int i = mid; i >= l; i--) {
            temp_sum += nums[i];
            max_left_sub_sum = max(max_left_sub_sum, temp_sum);
        }
        temp_sum = 0;
        for(int i = mid + 1; i <= r; i++) {
            temp_sum += nums[i];
            max_right_sub_sum = max(max_right_sub_sum, temp_sum);
        }
        cross_sum = max_left_sub_sum + max_right_sub_sum;
        return cross_sum;
    }
    int maxSubArraySum(vector<int>& nums, int l, int r) {
        if(l == r) return nums[l];
        int mid = l + ((r - l) / 2);
        int left_sum =  maxSubArraySum(nums, l, mid);
        int right_sum = maxSubArraySum(nums, mid + 1, r);
        int cross_sum = maxCrossSubArraySum(nums, l, r, mid);
        return (left_sum > right_sum)? ((left_sum > cross_sum) ? left_sum : cross_sum) : ((right_sum > cross_sum) ? right_sum : cross_sum);
    }
    int maxSubArray(vector<int>& nums) {
        return maxSubArraySum(nums, 0, nums.size() - 1);
    }
};