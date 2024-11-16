class Solution {
public:
    // Time Complexity: O(n)
    // Space complexity: O(1)
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int prefix = 1;
        int suffix = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            prefix = prefix * nums[i];
            suffix = suffix * nums[nums.size() - i - 1];
            ans = max (ans, max(prefix,suffix));
            if (prefix == 0) {
                prefix = 1;
            }
            if (suffix == 0) {
                suffix = 1;
            }
        }
        return ans;
    }
};