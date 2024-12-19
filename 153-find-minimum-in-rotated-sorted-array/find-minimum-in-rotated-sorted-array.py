class Solution:
    # Time complexity: O(log n)
    # Space complexity: O(1)
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right  = len(nums)-1
        mid = (left + right) // 2
        while left <= right:
            mid = (left + right) // 2
            if (nums[left] < nums[mid]) and (nums[mid] < nums[right]):
                # We are not checking for equality becuase all the elements in nums is unique
                return nums[left]
            elif (nums[mid] < nums[right]):
                """"nums[mid ... right] is sorted so we move right to mid, 
                    when nums[mid] = nums[right] we have found the inflection point.
                    In the next iteration left = mid + 1 i.e. right + 1 and it will 
                    exit the while loop and return nums[mid]
                """
                right = mid
            else: left = mid + 1
        
        return nums[mid]