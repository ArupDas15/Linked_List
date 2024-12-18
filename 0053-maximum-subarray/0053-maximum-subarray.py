class Solution:
    # Time Complexity: O(n)
    # Space Complexity: O(1)
    """ 
    CODE LOGIC
    We will apply Kadane's Algoruthm to find the maximum sum of a subarray.
    We will use two variables sum = 0 and maxSum = -infinity
    We will iterate nums[i] from 0 to len(nums)
        We will add nums[i] to sum.
        Determine if sum is max sum we have ofund till now and assign maxsum to sum if that is the case.
        if sum < 0 i.e. if it is negative then we reset sum to 0. this way even if the next number is 
        negative and is potentially the largest in the nums list then we can find it and assign it to maxsum int he next step.
        Also by resetting sum to 0, if the next number is postive we are not going to reduce its contribution to the sum,
    """
    def maxSubArray(self, nums: List[int]) -> int:
        sum = 0
        maxSum = -float('inf')

        for i in range(0, len(nums)):
            sum += nums[i]
            maxSum = max(maxSum, sum)
            if sum < 0:
                sum = 0
        
        return maxSum
        