class Solution:
    # Time Complexity: O(n^2)
    # Space compleixty: O(1) not considering ans because that is in the return argument of the function.
    def stringMatching(self, words: List[str]) -> List[str]:
        ans = []
        for idx, word in enumerate(words):
            for i in range(len(words)):
                if i != idx and word in words[i]:
                    ans.append(word)
                    break
        return ans