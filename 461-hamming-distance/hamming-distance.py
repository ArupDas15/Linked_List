class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        xor_res = x ^ y
        count = 0
        
        while xor_res > 0:
            xor_res = xor_res & (xor_res-1)
            count += 1
        return count