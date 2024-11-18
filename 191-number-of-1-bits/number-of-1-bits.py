class Solution:
    # Time complexity: O(log n)
    # Space complexity: O(1)
    def hammingWeight(self, n: int) -> int:
        hamming_wt = 0

        while n > 0:
            n = n & (n - 1)
            hamming_wt += 1

        return hamming_wt
        