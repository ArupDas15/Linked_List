class Solution {
public:
    int hammingWeight(uint32_t n) {
        int hamming_wt = 0;
        while(n > 0) {
            hamming_wt++;
            n &= (n - 1);
        }
        return hamming_wt;
    }
};