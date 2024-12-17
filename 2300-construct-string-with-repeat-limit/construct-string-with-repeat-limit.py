"""
Time complexity: O(n) for counting frequency
O(n*25) where n is the no. of characters in s.
Because the outer while loop will run atmost 26 times. THe inner loop which finds the next large character will
run 25 times in worst case assuming the next big character in s is 'a'. If the repeat limit is 1, then after inserting
a single character in result we have to use the inner loop.
"""
class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        freq = [0] * 26
        result = []
        current_char_idx = 25 # initially ponts to 'z'

        for char in s:
            freq[ord(char) - ord('a')] += 1

        while current_char_idx >= 0:
            if freq[current_char_idx] == 0:
                current_char_idx -= 1
                continue
            else:
                use = min(freq[current_char_idx], repeatLimit)
                result.append(chr(current_char_idx + ord('a')) * use)
                freq[current_char_idx] -= use

                if freq[current_char_idx] > 0:
                    next_large_char_idx = current_char_idx - 1
                    while next_large_char_idx >= 0 and freq[next_large_char_idx] == 0:
                        # Finds the next large character with non zero frequency
                        next_large_char_idx -= 1
                    if next_large_char_idx < 0:
                        break # construction of result further is not possible
                    result.append(chr(next_large_char_idx + ord('a')))
                    freq[next_large_char_idx] -= 1
        
        return "".join(result)