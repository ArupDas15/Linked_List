class Solution:
    def invert(self, s: str) -> str:
        inverted_str = ""
        for char in s:
            if char == '0':
                inverted_str += '1'
            else:
                inverted_str += '0'
        return inverted_str

    def findKthBit(self, n: int, k: int) -> str:
        s = [""] * n
        s[0] = "0"

        for i in range(1, n):
            reversed_str = self.invert(s[i - 1])[::-1]  # Invert and reverse the string
            s[i] = s[i - 1] + "1" + reversed_str

        if 0 <= k - 1 < len(s[n - 1]):
            return s[n - 1][k - 1]