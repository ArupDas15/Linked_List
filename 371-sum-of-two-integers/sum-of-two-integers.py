class Solution:
    """
    ALGORITHM
    // The XOR operation adds bits without considering the carry.
    // AND (&) and left shift (<<): Used to calculate the carry.
    // The number of recursive calls is proportional to the number 
    // of bits in the larger number. the time complexity is constant
    // (O(1) for bitwise operations)
    // Time complexity: O(log(max(a, b)))
    // The space complexity is determined by the recursion depth
    // Space complexity: O(log(max(a, b)))
    """
    def getSum(self, a: int, b: int) -> int:
        # 32-bit mask to avoid overflow issues
        mask = 0xFFFFFFFF
        # Handle cases where a or b might overflow
        while b != 0:
            a, b = (a ^ b) & mask, ((a & b) << 1) & mask
        
        # If a is negative, convert it to a signed 32-bit integer
        return a if a <= 0x7FFFFFFF else ~(a ^ mask)