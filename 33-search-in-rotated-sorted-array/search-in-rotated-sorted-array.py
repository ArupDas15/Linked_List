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
            # check if right half is sorted.
            if nums[mid] < nums[right]:
                # check if target lies in sorted right half
                if (target >= nums[mid]) and (target <= nums[right]):
                    # Narrow the searh space by moving left to mid + 1
                    left = mid + 1
                else:
                    right = mid - 1
            # if the right half isn;t sorted then the left half is definitely sorted.
            else:
                # check if target lies in sorted left half
                if (target >= nums[left]) and (target <= nums[mid]):
                    # Narrow the search soace by moving right to mid - 1.
                    right = mid - 1
                else:
                    left = mid + 1
        return -1
        