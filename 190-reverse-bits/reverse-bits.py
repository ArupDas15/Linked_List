class Solution:
    # Time complexity: O(1)
    # Space complexity: O(1)
    def reverseBits(self, n: int) -> int:
        res = 0

        for i in range(32):
            bit = (n >> i) & 1
            res = res | (bit << (31-i))
        
        return res