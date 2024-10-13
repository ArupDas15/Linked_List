class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        s1 = sentence1.split(" ")
        s2 = sentence2.split(" ")
        l1, r1, r2 = 0, len(s1) - 1, len(s2) - 1

        if len(s1) > len(s2):
            # We always assume len(s1) < len(s2)
            return self.areSentencesSimilar(sentence2, sentence1)
        while l1 < len(s1) and s1[l1] == s2[l1]:
            l1 += 1
        while r1 >= 0 and s1[r1] == s2[r2]:
            r1 = r1 - 1
            r2 = r2 - 1
        return r1 < l1        