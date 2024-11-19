class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(N)
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int begin = 0;
        int end = 0;
        long long curSum = 0;
        long long ans = 0;
        unordered_map<int, int> nums_to_idx;

        while (end < nums.size()) {
            // update the curSum to curSum + nums[end]
            curSum = curSum + nums[end];
            // Now check if nums[end] is duplicate or if window size exceeds k
            int lastOccurrence = 
                    (nums_to_idx.count(nums[end]) == 1) ? nums_to_idx[nums[end]] : -1;
            // if nums[end] is already in current window move begin forward until 
            // nums[end] is not in current window
            while (begin <= lastOccurrence || end - begin + 1 > k) {
                curSum -= nums[begin];
                begin++;
            }
            // There are no duplicates
             nums_to_idx[nums[end]] = end;
             
            if (end - begin + 1 == k) {
                ans = max(ans, curSum);
            }
            end++;
        }
        return ans;
    }
};