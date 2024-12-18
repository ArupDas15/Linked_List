class Solution:
    """
    Since we have to find the largest subarray product 
    (keep in mind **continuous** array and **largest** product),
    we will find the prefix and suffix product and output the maximum out of the two
    while iterating through nums. 
    Time complexity : O(n)
    Space Complexity: O(1)
    """
    def maxProduct(self, nums: List[int]) -> int:
        prefix = suffix = 1
        ans = -float('inf')

        for i in range(len(nums)):
            prefix *= nums[i]
            suffix *= nums[len(nums) - i - 1]
            ans = max(ans, prefix, suffix)
            if prefix == 0:
                prefix = 1
            if suffix == 0:
                suffix = 1
        return ans
        