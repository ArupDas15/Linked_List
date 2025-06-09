class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp = {} #(index, total)
        def backtrack(ind, total):
            if ind == len(nums):
                if total == target: return 1 
                else: return 0
            if (ind, total) in dp:
                return dp[(ind, total)]
            dp[(ind, total)] = backtrack(ind+1, total + nums[ind]) +\
                               backtrack(ind+1, total - nums[ind])
            return dp[(ind, total)]
        return backtrack(0,0)