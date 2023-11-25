class Solution {
public:
    // Approach 2: Calculating prefix sum on the fly
    // time complexity: O(n)
    // space complexity: O(1)
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans;
        int leftsum = 0;
        int n = nums.size();
        int totalsum = accumulate(nums.begin(),nums.end(),0);

        for(int i = 0; i < n; i++) {
            int leftcount = i;
            int rightcount = n - 1 - i;
            int rightsum = totalsum - leftsum - nums[i];
            int left_half = (leftcount * nums[i]) - leftsum;
            int right_half = rightsum - (rightcount * nums[i]);

            ans.push_back(left_half + right_half);
            leftsum = leftsum + nums[i];
        }
        return ans;
    }
};
// Approach 1: Pre-computing prefix sum
// class Solution {
// public:
    // time complexity: O(n)
    // space complexity: O(n)
//     vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans;
//         vector<int>prefixsum(n,0);

//         prefixsum[0] = nums[0];
//         for(int i = 1; i < n; i++) {
//             prefixsum[i]=prefixsum[i-1]+nums[i];
//         }
//         for(int i = 0; i < n; i++) {
//             int leftcount = i;
//             int rightcount = n - 1 - i;
//             int left_half = leftcount > 0 ?
//                                 (leftcount*nums[i])-prefixsum[i-1]:0;
//             int right_half = (prefixsum[n-1]-prefixsum[i])-
//                                 (rightcount*nums[i]);
//             ans.push_back(left_half + right_half);
//         }
//         return ans;
//     }
// };