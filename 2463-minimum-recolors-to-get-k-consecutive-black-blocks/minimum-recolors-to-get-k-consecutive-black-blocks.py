class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        l = 0
        r = 0
        count = 0
        ans = len(blocks)
        for r in range(len(blocks)):
            if blocks[r] == 'W':
                count += 1
            if r - l +  1 == k:
                ans = min(ans, count)
                if blocks[l] == 'W': count -= 1
                l += 1
        return ans
            
        