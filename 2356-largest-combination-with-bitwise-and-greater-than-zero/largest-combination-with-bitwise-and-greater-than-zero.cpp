class Solution {
public:
    /*
     The number of bits b required to represent a number \U0001d441 is: 
     b=⌊log N⌋+1. for numbers constrained to be less than or 
     equal to 10^7 (requiring a maximum of 24 bits), we only 
     need to check bit positions 0 to 23 when working with 
     32-bit integers to check which group of numbers share the 
     most significant bit at the same position.
    ALGORITHM:
    1. Initialize an array bitCount of size 24 with zeros.
    2. Run a loop from 0 to 23 to check which group of numbers share the 
     most significant bit at the same position:
        2.1 For each candidate in candidates:
            2.1.1: if ((candidate & (1<<i)) != 0):
                    2.1.1.1: increment bitcount[i]
    3. return *max_element(bitcount.begin().bitcount.end())

    Time Complexity: O(n)
    Space complexity: O(b) where b is the number of bits in candidates[i]
    in this case 24.
    */
    int largestCombination(vector<int>& candidates) {
        int bitcount[24] = {0};
        
        for (int i = 0; i < 24; i++) {
            for (int candidate : candidates) {
                if ((candidate & (1 << i)) != 0) {
                    bitcount[i]++;
                }
            }
        }
        return *max_element(bitcount,bitcount+24);      
    }
};