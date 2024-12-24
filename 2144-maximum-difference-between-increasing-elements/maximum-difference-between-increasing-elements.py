class Solution:
    # This is nothing but best time to buy and sell stock i.e. maximum difference between increasing elements.
    def maximumDifference(self, nums: List[int]) -> int:
        min_bp = nums[0]
        max_profit = 0

        for i in range(1, len(nums)):
            cur_profit = nums[i] - min_bp
            max_profit = max(max_profit, cur_profit)
            min_bp = min(min_bp, nums[i])
        return -1 if max_profit == 0 else max_profit
        