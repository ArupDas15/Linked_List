class Solution {
public:
    /* APPROACH
    1. USe a hash data structure like unordered_set and insert 
      nums[i] if it is not encountered before.
    2. If nums[i] is already int he set then return true -> presence of duplicate
    3. After all elements have been inserted intot he set, return false.
    // Time complexity: O(n)
    // Space complexity: O(n)
    */
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        
        for(int i = 0; i < nums.size(); i++) {
            if (uset.find(nums[i]) == uset.end()) {
                uset.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};