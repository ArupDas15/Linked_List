# Time complexity: 
# Each heap operation (push and pop) takes O(logn), and we perform 
#  these operations \U0001d45b times. So the total complexity for heap 
#  operations is O(nlogn).
# Space complexity: O(n)

class Solution:
    def findScore(self, nums: List[int]) -> int:
        n = len(nums)
        score = 0
        count = 0
        visited = [False] * n
        heap = []

        for i in range(n):
            heapq.heappush(heap, (nums[i], i))
        
        while count < n:
            val, idx = heapq.heappop(heap)
            if not visited[idx]:
                visited[idx] = True
                count += 1
                score += val
            else: continue
            if (idx > 0) and (not visited[idx-1]):
                visited[idx-1] = True
                count += 1
            if (idx < n-1) and (not visited[idx+1]):
                visited[idx+1] = True
                count += 1
        
        return score



        