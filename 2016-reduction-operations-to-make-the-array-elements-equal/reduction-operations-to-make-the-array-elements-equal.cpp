class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int ans = 0, up = 0;

        sort(nums.begin(), nums.end());        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i-1]) {
                up++;
            }
            ans = ans + up;
        }
        return ans;
    }
};