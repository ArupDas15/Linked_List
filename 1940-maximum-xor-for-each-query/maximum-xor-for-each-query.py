class Solution:
    """
    When we are doing XOR between two numbers A and B,
    the maximum result of the XOR will be the 2^ maximum number of bits in A and B.
    So, the largest maximum result we can get is 2^maximumbit - 1.
    Thus, if A^B = 2^maximumbit - 1 and we need to find B so B = A ^ (2^maximumbit - 1).
    ALGORITHM:
    STEP 1: Find the prefix XOR of nums.
    STEP 2: 
       answer[0] = prefixXOR[n-1]^(2^maximumbit - 1)
       answer[1] = prefixXOR[n-2]^(2^maximumbit - 1)
       ...
       answer[n - 1] = prefixXOR[0]^(2^maximumbit - 1) 
    Time Complexity: O(n)
    Space complexity: O(n)
    """
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        prefixXOR = [0] * len(nums)
        maximumXOR = 2**maximumBit - 1
        answer = [0] * len(nums)

        prefixXOR[0] = nums[0] 
        for i in range(1, len(nums)):
            prefixXOR[i] = prefixXOR[i - 1] ^ nums[i]
        for i in range(len(nums)):
            answer[i] = prefixXOR[i] ^ maximumXOR
        return answer[::-1]
