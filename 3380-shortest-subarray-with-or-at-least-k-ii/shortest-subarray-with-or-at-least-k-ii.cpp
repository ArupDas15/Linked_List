class Solution {
public:
    void updateFreq(vector<int>& bitFreq, int number, int val) {
        for(int i = 0 ; i < 32; i++) {
            if (number & (1 << i)) {
                bitFreq[i] += val;
            }
        }
    }
    int getNumber(vector<int>& bitFreq) {
        int number = 0;
        for(int i = 0 ;i < 32; i++) {
            if (bitFreq[i] > 0) {
                number = (number | (1 << i));
            }
        }
        return number;
    }
    // Time Complexity: O(n)
    // Space complexity: O(1)
    /* APPROACH:
    1. Create an arr of size 32 since 0 <= nums[i] <= 10^9 so 32 bits are enough.
    2. We are going to use sliding window technique where in as we increment 
       the right pointer we increment the indices representing the set bits in
       the integer pointed to by the right pointer and as we increment the left 
       pointer we decrement the indices representing the set bits in the integer 
       previously pointed to by the left pointer.
    3. Run a loop until right < nums.size().
       a.) We are going to incrmeent the right pointer until the curOR result is < k.
       b.) We are going to increment the left pointer until the curOR result is >= k.
    */
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if (*max_element(nums.begin(), nums.end()) >= k) {
            return 1;
        }
        int left = 0;
        int right = 0;
        int curOR = 0;
        int shortestlen = INT_MAX;
        int n = nums.size();
        vector<int> bitFreq(32, 0);

        while (right < n) {
            updateFreq(bitFreq, nums[right], 1);
            curOR = getNumber(bitFreq);

            while(left < right and curOR >= k) {
                shortestlen = min(shortestlen, right - left + 1);
                updateFreq(bitFreq, nums[left], -1);
                left++;
                curOR = getNumber(bitFreq);
            }
            right++;
        }
        return shortestlen == INT_MAX? -1: shortestlen;
    }
};