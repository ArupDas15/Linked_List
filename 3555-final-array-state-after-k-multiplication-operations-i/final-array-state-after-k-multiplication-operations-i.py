# time complexity: O(N + klog(n))
# space complexity: O(n)
class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        heap = [(value, idx) for idx, value in enumerate(nums)]
        heapq.heapify(heap)

        while heap and k > 0:
            _, idx = heapq.heappop(heap)
            nums[idx] = nums[idx] * multiplier
            heapq.heappush(heap, (nums[idx], idx))
            k -= 1
        
        return nums