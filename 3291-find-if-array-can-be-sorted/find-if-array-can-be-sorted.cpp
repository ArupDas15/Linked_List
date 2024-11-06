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
    /* ----------------------------
        1. Split the array into segments. Each segment contains 
           consecutive elements with the same number of set bits.
        2. From left to right, the previous segment’s largest 
           element should be smaller than the current segment’s smallest element.
    */
    // Time complexity: O(m * log n), 
    // where n is the value of the largest number in the array
    // and we have m elements in nums.
    // Space complexity: O(m), where m is the size of the input array nums.
    bool canSortArray(vector<int>& nums) {
        // List to hold segments of numbers with the same number of set bits
        vector<vector<int>>segments;
        // Initialize with an impossible set bit count
        int cur_setbitcount = -1;
        int prev_setbitcount = -1;
        
        for(int i = 0; i < nums.size(); i++) {
            cur_setbitcount = countSetBits(nums[i]);
            if (prev_setbitcount == cur_setbitcount) {
                segments.back().push_back(nums[i]);
            } else {
                //  Create segments of numbers with the same number of set bits
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
