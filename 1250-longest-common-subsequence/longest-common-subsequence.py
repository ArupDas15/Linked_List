class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [[0 for _ in range(len(text2)+1)] for _ in range(len(text1)+1)]
        # prev = [0 for _ in range(len(text2)+1)]
        # cur = [0 for _ in range(len(text2)+1)]
        # BASE CASE: using index shifting technique.
        # for i in range(len(text1)):
        #     dp[i][0] = 0
        # for j in range(len(text2)):
        #     dp[0][j] = 0 
        # RECURSION CASES
        for i in range(1, len(text1)+1):
            for j in range(1, len(text2)+1):
                if text1[i-1] == text2[j-1]: 
                    # if there is a match
                    dp[i][j] = 1+dp[i-1][j-1]
                else: # if not match
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return dp[len(text1)][len(text2)]
