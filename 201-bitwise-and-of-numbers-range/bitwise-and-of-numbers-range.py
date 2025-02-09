class Solution:
    # Time complexity: O(1) Since left and right are 32 bits the right shift operation will atmost happen 32 times.
    # Space complexity: O(1)
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        count = 0

        while left != right:
            left = left >> 1
            right = right >> 1
            count += 1

        return left << count