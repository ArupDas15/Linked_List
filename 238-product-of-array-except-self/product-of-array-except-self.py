class Solution:
    # Time complexity: O(n)
    # Space complexity: O(n)
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix_suffix_product = [1] * len(nums)
        prefix = suffix = 1

        for i in range(0, len(nums)):
            prefix_suffix_product[i] = prefix
            prefix = prefix * nums[i]
        for i in range(len(nums)-1, -1, -1):
            prefix_suffix_product[i] *= suffix
            suffix = suffix * nums[i]
        
        return prefix_suffix_product
