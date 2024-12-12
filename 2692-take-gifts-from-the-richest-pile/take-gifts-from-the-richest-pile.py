class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        heap = [-1*elem for elem in gifts]
        heapify(heap)

        while k > 0:
            max_element = -1*heappop(heap)
            heappush(heap, -1*math.isqrt(max_element))
            k -= 1
        
        return -1*sum(heap)