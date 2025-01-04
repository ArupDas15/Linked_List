class Solution:
    """Moore Voting algorithm"""
    """Apporach: Moore Voting Algorithm: This approach works in 2 steps:
        1. Find the last element which survives in the array.
        2. Check if the last element is the majority element 
        by performing a linear search. This step was not performed in this question,
        Since the question states that there always exists a majority element
        If the count of the candidate is greater than n / 2, 
        then it is the majority element. Otherwise, there is no majority element.
        Moore Voting Algorithm (also known as Boyer-Moore Majority Vote Algorithm) is 
        used to find the majority element that appears more than n / 2 times 
        in the array, where n is the size of the array.  It assumes that if a majority
        element exists, it will remain the candidate after processing all elements 
        because it will always "cancel out" the votes of the other elements.
    """
    # Time complexity: O(n)
    # Space complexity: O(1)
    def majorityElement(self, nums: List[int]) -> int:
        cnt = 0
        for i in range(len(nums)):
            if cnt == 0:
                cnt = 1
                el = nums[i]
            elif el != nums[i]:
                cnt -= 1
            else: cnt += 1
        return el
