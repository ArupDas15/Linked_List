class Solution:
    # Time complexity: O(log n)
    # Space complexity: O(1)
    def hammingWeight(self, n: int) -> int:
        count = 0

        while n > 0:
            n = n & (n - 1)
            count += 1

        return count
        