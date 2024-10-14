class Solution:
    # NOTE: Python uses min heap by default 
    # where as C++ uses max heap bby default.
    # Time Complexity: O(nlogn +klogn)
    # Space Complexity: O(n)
    def maxKelements(self, nums: List[int], k: int) -> int:
        max_heap = []
        sum = 0
        for i in range(len(nums)):
            heapq.heappush(max_heap, -nums[i])
        while(k):
            k -= 1
            ele = -heapq.heappop(max_heap)
            sum += ele
            heapq.heappush(max_heap, -ceil(ele / 3))
        return sum