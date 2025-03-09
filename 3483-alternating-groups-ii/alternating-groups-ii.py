class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        l = 0
        r = 1
        count = 0

        while l < len(colors):
            if colors[r%len(colors)] == colors[(r-1)%len(colors)]: l = r
            if r - l + 1 == k: 
                count += 1
                l += 1
            r += 1
        return count