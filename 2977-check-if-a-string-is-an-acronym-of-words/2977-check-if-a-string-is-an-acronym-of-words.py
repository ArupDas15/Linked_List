class Solution:
    # Time Complexity: O(n)
    # Space complexity: O(n)
    def isAcronym(self, words: List[str], s: str) -> bool:
        acronym = ''

        for word in words:
            acronym += word[0]
        return acronym == s