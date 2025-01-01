class Solution {
public:
    // time complexity: O(n)
    // space complexity: O(n)
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(int num : nums) {
            ans = ans ^ num;
        }
        return ans;
    }
};