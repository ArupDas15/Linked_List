class Solution {
public:
    // Brian Kernighan's Algorithm to 
    // count the number of set bits (1s) in an integer's binary representation.
    // Time Complexity: O(log n)
    // Space Complexity: O(1)
    int countSetBits(int n) {
        int count = 0;
        while (n != 0) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
    // Time complexity: O(m * log n), 
    // where n is the value of the largest number in the array
    // and we have m elements in nums.
    // Space complexity: O(m), where m is the size of the input array nums.
    bool canSortArray(vector<int>& nums) {
        vector<vector<int>>segments;
        int cur_setbitcount = 0;
        int prev_setbitcount = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            cur_setbitcount = countSetBits(nums[i]);
            if (prev_setbitcount == cur_setbitcount) {
                segments.back().push_back(nums[i]);
            } else {
                vector<int> segment;
                segment.push_back(nums[i]);
                segments.push_back(segment);
                prev_setbitcount = cur_setbitcount;   
            }
        }
        for (int i = 0 ; i < segments.size() - 1; i++) {
            if (*max_element(segments[i].begin(),segments[i].end())
            > *min_element(segments[i+1].begin(),segments[i+1].end())) {
                return false;
            }
        }
        return true;
    }
};