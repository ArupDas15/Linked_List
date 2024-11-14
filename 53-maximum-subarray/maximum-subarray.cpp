class Solution {
public:
    /* ALGORITHM
    1. Initialise a variable maxSum = INT_MIN
    2. Initialise sum to 0.
    3. Run a loop from 0 to nums.size() - 1.
       3.1. sum = sum + nums[i] >= 0
                maxSum = max(sum, maxSum);
    4. Return maxSum.
    Time Complexity: O(N)
    Space Complexity: O(1)
    */
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, sum = 0;
        for(int num : nums) {
            sum = sum + num;
            maxSum = max(maxSum, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxSum;
    }
};