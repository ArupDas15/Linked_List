class Solution:
    def recursiveSoln(self, l, r, blocks, count, ans, k):
        # Base Case
        if r == len(blocks): return ans
        if blocks[r] == 'W':
            count +=1
        if r - l +  1 == k:
            ans = min(ans, count)
            if blocks[l] == 'W': count -= 1
            return self.recursiveSoln(l+1, r+1, blocks, count, ans, k)
        return self.recursiveSoln(l, r+1, blocks, count, ans, k)
    
    def minimumRecolors(self, blocks: str, k: int) -> int:
        return self.recursiveSoln(0,0, blocks, 0, k, k)

    

        