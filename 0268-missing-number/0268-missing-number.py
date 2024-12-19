class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        missing = 0

        for i in range(0, len(nums)):
            missing = missing ^ nums[i] ^ (i+1)
        return missing