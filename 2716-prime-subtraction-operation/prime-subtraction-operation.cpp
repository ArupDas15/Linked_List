class Solution {
public:
    // Time Compelxity: O(n+mloglogm) where m is the maximum element
    // space complexity: O(m)    
    bool primeSubOperation(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        int curValue = 1;
        int index = 0;
        // Create and initialise a sieve array
        vector<int> sieve(maxElement + 1, 1);
        
        sieve[0] = sieve[1] = 0;
        for (int i = 2; i*i <= maxElement+1; i++) {
            if(sieve[i] == 1) {
                for (int j = i*i; j <= maxElement; j += i) {
                    sieve[j] = 0;
                }
            }
        }
        while (index < nums.size()) {
            int difference = nums[index] - curValue;
            if (difference < 0) {
                return false;
            }
            if (sieve[difference] == 1 or difference == 0) {
                index++;
                curValue++;
            } else {
                curValue++;
            }
        }
        return true;
    }
};