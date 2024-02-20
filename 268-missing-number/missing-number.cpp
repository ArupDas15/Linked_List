class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int missing = 0;
        
        for (int i = 0; i < n; ++i) {  // O(n) time complexity
            missing ^= (i + 1) ^ nums[i];
        }
        
        return missing;
    }
};