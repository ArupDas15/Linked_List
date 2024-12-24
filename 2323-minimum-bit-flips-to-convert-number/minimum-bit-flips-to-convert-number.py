class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        num = start ^ goal
        cnt = 0

        while num != 0:
            cnt += 1
            num = num & (num-1)
        return cnt