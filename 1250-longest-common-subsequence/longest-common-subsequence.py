class Solution:
    def lcs(self, ind1: int, ind2: int, s: str, t: str, dp: list[list[int]]) -> int:
        if ind1 < 0 or ind2 < 0: return 0
        if dp[ind1][ind2] != -1: return dp[ind1][ind2]
        if s[ind1] == t[ind2]: dp[ind1][ind2] = 1 + self.lcs(ind1-1,ind2-1, s, t, dp)
        else: dp[ind1][ind2] = max(self.lcs(ind1-1,ind2, s, t, dp), self.lcs(ind1,ind2-1, s, t, dp))
        return dp[ind1][ind2]
    
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [[-1 for _ in range(len(text2))] for _ in range(len(text1))]
        return self.lcs(len(text1) - 1, len(text2) - 1, text1, text2, dp)
