class Solution {
public:
    // Time Complexity: O(nlogn)
    // Space Complexity: O(logn)
    int minPairSum(vector<int>& nums) {
        int ans = INT_MIN;

        sort(nums.begin(),nums.end());
        for(int i = 0, j = nums.size() - 1; 
            i < nums.size()/2 && j >= nums.size()/2; 
            i++, j--) {
            ans = max(ans,nums[i] + nums[j]);
        }
        return ans;
    }
};
