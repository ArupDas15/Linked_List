class Solution {
public:
    // time complexity: O(n)
    // space complexity: O(n)
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int>prefixsum(n,0);

        prefixsum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefixsum[i]=prefixsum[i-1]+nums[i];
        }
        for(int i = 0; i < n; i++) {
            int leftcount = i;
            int rightcount = n - 1 - i;
            int left_half = leftcount > 0 ?
                                (leftcount*nums[i])-prefixsum[i-1]:0;
            int right_half = (prefixsum[n-1]-prefixsum[i])-
                                (rightcount*nums[i]);
            ans.push_back(left_half + right_half);
        }
        return ans;
    }
};