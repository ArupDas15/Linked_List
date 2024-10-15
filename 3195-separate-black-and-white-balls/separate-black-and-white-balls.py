class Solution:
    # Time complexity: O(n)
    # Space Complexity: O(1)
    def minimumSteps(self, s: str) -> int:
        ans = 0
        first, second = 0, len(s) - 1
        
        while first < second:
            if s[first] == '1':
                while first < second and s[second] == '1':
                    second -= 1
                if s[second] == '0':
                    ans += (second - first)
                    second -= 1
            first += 1    
        return ans
        