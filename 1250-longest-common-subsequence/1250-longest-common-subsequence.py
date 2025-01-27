class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        prev = [0 for _ in range(len(text2)+1)]
        cur = [0 for _ in range(len(text2)+1)]
        
        # RECURSION CASES
        for i in range(1, len(text1)+1):
            for j in range(1, len(text2)+1):
                if text1[i-1] == text2[j-1]: 
                    # if there is a match
                    cur[j] = 1+prev[j-1]
                else: # if not match
                    cur[j] = max(prev[j], cur[j-1])
            prev = cur[:]
        return prev[len(text2)]
