class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0

        for i in range(len(nums)):
            ans = ans ^ nums[i]
        return ans