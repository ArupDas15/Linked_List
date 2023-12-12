class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)    
    int maxProduct(vector<int>& nums) {
        int max1 = 0;
        int max2 = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > max1) {
                max2 = max1;
                max1 = nums[i];
            } else {
                max2 = max(max2, nums[i]);
            }
        }
        return (max1 - 1) * (max2 -1);
    }
};