class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(log n)
    int maxFrequency(vector<int>& nums, int k) {
        int left = 0, ans = 1;
        long int sum = 0;
        
        // sort the array.
        sort(nums.begin(), nums.end());
        for(int right = 0; right < nums.size(); right++) {
            sum = sum + nums[right];
            while(((long)nums[right]) * (right - left + 1) - sum > k) {
                sum = sum - nums[left];
                left++;
            }
            // update the ans as per the current valid sliding window.
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};