class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        minheap = []

        for interval in intervals:
            if minheap and interval[0] > minheap[0]:
                heapq.heappop(minheap)
            heapq.heappush(minheap, interval[1])
        return len(minheap)
        