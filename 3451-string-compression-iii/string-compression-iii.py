class Solution:
    # Time complexity: O(n)
    # Time complexity: O(1)
    def compressedString(self, word: str) -> str:
        comp = []  # Use a list for efficient string building since string concatenation can be costly.
        n = len(word)

        i = 0
        while i < n:
            current_char = word[i]
            count = 0

            # Count consecutive characters
            while i < n and word[i] == current_char and count < 9:
                count += 1
                i += 1

            comp.append(str(count))  # Append the count to the list
            comp.append(current_char)  # Append the character to the list

        return ''.join(comp)  # Convert the list to string