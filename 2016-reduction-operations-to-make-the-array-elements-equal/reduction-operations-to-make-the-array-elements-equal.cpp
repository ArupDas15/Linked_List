class Solution {
public:
    // time complexity: O(nlogn)
    // space complexity: O(logn)
    int reductionOperations(vector<int>& nums) {
        int ans = 0;

        sort(nums.begin(), nums.end());        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i-1]) {
                ans = ans + (nums.size() - i);
            }
        }
        return ans;
    }
};
