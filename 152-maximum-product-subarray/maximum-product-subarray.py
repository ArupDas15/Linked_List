class Solution:
    # Time complexity: O(n)
    # Space complexity: O(1)
    def maxProduct(self, nums: List[int]) -> int:
        ans = float('-inf')
        prefix = 1
        suffix = 1

        for i in range(len(nums)):
            prefix *= nums[i]
            suffix = suffix * nums[len(nums) - i - 1]
            ans = max(ans, max(prefix, suffix))
            if prefix == 0:
                prefix = 1
            if suffix == 0:
                suffix = 1
        return ans