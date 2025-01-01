class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        thrice_arr = [3*num for num in list(set(nums))]
        ans = (sum(thrice_arr) - sum(nums))//2
        return ans