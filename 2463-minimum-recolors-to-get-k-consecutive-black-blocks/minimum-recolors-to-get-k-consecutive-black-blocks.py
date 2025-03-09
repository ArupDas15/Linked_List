class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        l = 0
        r = 0
        count = 0
        ans = len(blocks)

        def recursiveSoln(l, r, blocks, count, ans):
            # Base Case
            if r == len(blocks): return ans
            if blocks[r] == 'W':
                count +=1
            if r - l +  1 == k:
                ans = min(ans, count)
                if blocks[l] == 'W': count -= 1
                return recursiveSoln(l+1, r+1, blocks, count, ans)
            return recursiveSoln(l, r+1, blocks, count, ans)
        return recursiveSoln(0,0, blocks, 0, k)    

        