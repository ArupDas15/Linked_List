class Solution:
    # Time complexity: O(n)
    # Space complexity: O(1)
    # We are going to use prefix sum logic.
    def waysToSplitArray(self, nums: List[int]) -> int:
        arr_sum = sum(nums)
        left = right = count = 0

        for i in range(0, len(nums) - 1):
            left += nums[i]
            right = arr_sum - left
            if left >= right:
                count += 1
        return count