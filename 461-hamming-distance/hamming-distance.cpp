class Solution {
public:
    // Time complexity: O(log n)
    // Space complexity: O(1)
    int hammingDistance(int x, int y) {
        int xor_res = x ^ y;
        int count = 0;

        while (xor_res > 0) {
            xor_res = xor_res & (xor_res - 1);
            count++;
        }
        return count;
    }
};