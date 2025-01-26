class Solution:
    # We are assuming that len(s) >= len(p)
    # time complexity: O(len(s))
    # space complexity: O(len(s))
    def findAnagrams(self, s: str, p: str) -> List[int]:
        # For 2 strings to be anagrams of each other, 
        # they should have the same elements with the same frequency.
        if len(p) > len(s):
            return []

        pdict, sdict = {}, {}

        for i in range(len(p)):
            pdict[p[i]] = 1 + pdict.get(p[i], 0)
            sdict[s[i]] = 1 + sdict.get(s[i], 0)
        
        l = 0
        ans = [0] if pdict == sdict else []

        for r in range(len(p), len(s)):
            sdict[s[r]] = 1 + sdict.get(s[r], 0)
            sdict[s[l]] = sdict[s[l]] - 1

            if sdict[s[l]] == 0: 
                sdict.pop(s[l])
            
            l += 1
            
            if sdict == pdict: 
                ans.append(l)
            
        return ans