class Solution {
public:
    // Time complexity: O(m⋅n⋅log⁡n)
    // Space complexity: O(n)
    bool check(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int diff = nums[1] - nums[0];

        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] - nums[i - 1] != diff) {
                return false;
            }
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int m = l.size();
        
        for(int i = 0; i < m; i++) {
            vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
            ans.push_back(check(arr));
        }
        return ans;
    }
};