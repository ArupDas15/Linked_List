class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        if startFuel >= target: return 0
        stations.sort()
        c,q,n = startFuel, [], 0
        for i in stations:
            if c >= target: return n
            while i[0] > c and q:
                c += -1*heapq.heappop(q)
                n += 1
            else:
                if i[0] <= c: heapq.heappush(q,-i[1])
                else: return -1
        while q and c < target:
            c += -1*heapq.heappop(q)
            n += 1
        else:
            if c >= target: return n
            else: return -1