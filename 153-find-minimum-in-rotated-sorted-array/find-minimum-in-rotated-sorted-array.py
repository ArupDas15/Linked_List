class Solution:
    """ There is a point in the array called the inflection point at which:
            1. All the elements to the left of the inflection point are sorted.
            2. All the elements to the right of the inflection point including 
               the inflection point are sorted.
        if nums[mid] < nums[right] then nums[mid ... right] is sorted. In this case,
        we shift right to mid because we need to find the inflection point including nums[mid].
        otherwise, left = mid + 1 because we know that nums[mid] is not the inflection point for sure.
        when left == right we stop.
    """
    # Time complexity: O(log n)
    # Space complexity: O(1)
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        mid = (left + right) // 2

        while left != right:
            if nums[mid] < nums[right]:
                right = mid
            else:
                left = mid + 1
            mid = (left + right) // 2
        return nums[mid]