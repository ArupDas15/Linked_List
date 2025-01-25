class Solution:
    # Time Complexity: O(N)
    # Space Complexity: O(1)
    """
    Approach: Dutch National Flag algorithm
    1. All array elements from 0 to low-1 are 0s.
    2. All array elements from low to mid-1 are 1s.
    3. All array elements from high+1 to n-1 are 2s.
    All array elements from mid to high represent the 
    unsorted part in the hypothetically sorted array.
    """
    def sortColors(self, nums: List[int]) -> None:
        low = mid = 0
        high = len(nums) - 1

        while mid <= high:
            if nums[mid] == 2:
                nums[high], nums[mid] = nums[mid], nums[high]
                high -= 1
            elif nums[mid] == 1:
                mid += 1
            else: # nums[mid] is 0
                nums[mid], nums[low] = nums[low], nums[mid]
                low += 1
                mid += 1
        
        return nums
        