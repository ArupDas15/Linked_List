class Solution:
    """
        Since the array is sorted and we need to search for an element target,
        we are going to use the Binary Search Algorithm.
        Time Complexity: O(log n)
        Space Complexity: O(1)
    """ 
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        
        while left <= right:
            mid = (left + right) // 2
            
            if nums[mid] == target:
                return mid
            else: # Assuming targer lies in nums, determine where target lies
                if nums[mid] < nums[right]:
                    # nums[mid ... right] is sorted.
                    if nums[mid] <= target and target <= nums[right]:
                        left = mid + 1
                    else: right = mid - 1
                else: # left half of the array is sorted.
                # Assuming target lies in nums, if target does not lie in right 
                # half of the array it will definitely lie in left half of the array.
                    if nums[left] <= target and target <= nums[mid]:
                        right = mid - 1
                    else:
                        left = mid + 1
        return -1
