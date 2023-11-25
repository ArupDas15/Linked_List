class Solution {
public:
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