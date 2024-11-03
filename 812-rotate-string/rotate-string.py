class Solution:
    # Time Complexity: O(n)
    # Space Complexity: O(n)
    # This question ideally requires the knowledge of KMP algorithm.
    def rotateString(self, s: str, goal: str) -> bool:
        return len(s) == len(goal) and s in goal + goal
        