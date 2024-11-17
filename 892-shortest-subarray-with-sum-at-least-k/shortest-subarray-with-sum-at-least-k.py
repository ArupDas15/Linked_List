class Solution:
    # Time Complexity: O(nlogn)
    # Space Complexity: O(n)
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        # Initialise a min-heap to keep track of prefix sum to be removed from current window.
        min_heap = [] # An element in min_heap is a tuple: (prefix_sum, end_idx)
        curSum = 0
        # Initialise res to a very large positive value.
        res = float('inf')

        for r in range(len(nums)):
            curSum += nums[r]

            if curSum >= k:
                res = min(res, r + 1)
            # Find the minimum subarray length ending at r
            while min_heap and curSum - min_heap[0][0] >= k:
                prefix, end_idx = heapq.heappop(min_heap)
                res = min(res, r - end_idx)
            
            heapq.heappush(min_heap, (curSum, r))

        return -1 if res == float('inf') else res