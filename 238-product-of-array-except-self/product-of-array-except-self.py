class Solution:
    # Time Complexity: O(n)
    # Space Complexity: O(1) -> The output array does not 
    # count as extra space for space complexity analysis.
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefixSuffixProduct = [1] * len(nums)
        prefixProduct = suffixProduct = 1

        for i in range(len(nums)):
            prefixSuffixProduct[i] *= prefixProduct
            prefixProduct *= nums[i]
        for i in range(len(nums) - 1, -1, -1):
            prefixSuffixProduct[i] *= suffixProduct
            suffixProduct *= nums[i]
        return prefixSuffixProduct
         