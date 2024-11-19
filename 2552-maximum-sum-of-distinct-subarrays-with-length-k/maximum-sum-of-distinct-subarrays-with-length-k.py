class Solution:
    """
    ALGORITHM
    1. create a hashmap nums_to_idx = {}
    2. initialise curSum to 0, ans = float('-inf')
    3. initialise begin = end = 0
    4. while end < len(nums):
        4.2. curSum = curSum + nums[end]
        4.2. while begin <= nums_to_idx.get(nums[end], -1) or end-begin+1 > k:
            4.2.1. curSum -= nums[begin]
            4.2.2. increment begin
        4.3. nums_to_idx[nums[end]] = end
        4.4. if end-begin+1==k: ans = max(ans,curSum)
        4.5. increment end
    """
    # Time complexity: O(n)
    # Space complexity: O(1)
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        nums_to_idx = dict()
        curSum = 0
        begin = end = 0
        ans = 0

        while end < len(nums):
            curSum = curSum + nums[end]
            while begin <= nums_to_idx.get(nums[end], -1) or end-begin+1 > k:
                curSum -= nums[begin]
                begin += 1
            # nums[end] is unique so insert it into the hashmap
            nums_to_idx[nums[end]] = end
            # check if window size is k and update ans
            if end - begin + 1 == k:
                ans = max(ans, curSum)
            end += 1
        return ans