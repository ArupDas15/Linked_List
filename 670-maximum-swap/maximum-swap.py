class Solution:
    """STEPS
    1. Scan the integer from right to left
       and store the index of the max digit from the current position 
       which can be swapped in a vector named maxRightIdx.
    2. Scan the integer from left to right
       and if the digit at current position i is 
       less than the digit at maxRightIdx[i] then perform 
       the swap and output the ans.
    TC: O(n), SC: O(n)
    """
    def maximumSwap(self, num: int) -> int:
        numStr = list(str(num))
        n = len(numStr)
        maxRightIdx = [0]*n

        # First pass
        maxRightIdx[n - 1] = n - 1
        for i in range(n - 2, -1, -1):
            maxRightIdx[i] = (
                i
                if numStr[i] > numStr[maxRightIdx[i + 1]]
                else maxRightIdx[i + 1]
            )
        # Second pass
        for i in range(n):
            if numStr[i] < numStr[maxRightIdx[i]]:
                numStr[i], numStr[maxRightIdx[i]] = (
                    numStr[maxRightIdx[i]],
                    numStr[i]
                )
                return int("".join(numStr))
        return num