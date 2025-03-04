# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    # Time Complexity: O(log n)
    # Space Complexity: O(1)
    def firstBadVersion(self, n: int) -> int:
        l = 1
        h = n
        ans = n
        while l <= h:
            mid = l + (h - l) // 2
            if isBadVersion(mid):
                h = mid - 1
                ans = min(ans, mid)
            else: l = mid + 1
        return ans
        