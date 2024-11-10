class Solution:
    # Time Complexity: O(n)
    # Space Complexity: O(1)
    def updateFreq(self, bitFreq, number, val):
        for i in range(32):
            if number & (1 << i):
                bitFreq[i] += val
    
    def getNumber(self, bitFreq):
        number = 0
        for i in range(32):
            if bitFreq[i] > 0:
                number = number | (1 << i)
        return number

    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        if max(nums) >= k:
            return 1
        left = right = 0
        curOR = 0
        n = len(nums)
        bitFreq = [0] * 32
        shortestlen = float('inf')

        while right < n:
            self.updateFreq(bitFreq, nums[right], 1)
            curOR = self.getNumber(bitFreq)

            while left < right and curOR >= k:
                self.updateFreq(bitFreq, nums[left], -1)
                curOR = self.getNumber(bitFreq)
                shortestlen = min(shortestlen, right - left + 1)
                left += 1
            
            right += 1
        return -1 if shortestlen == float('inf') else shortestlen