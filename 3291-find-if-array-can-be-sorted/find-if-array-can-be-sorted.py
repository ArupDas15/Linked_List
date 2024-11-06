class Solution:
    def countSetBits(self, n: int) -> int:
        count = 0
        while n != 0:
            n = n & (n - 1)
            count += 1
        return count
    """
    Approach
        1. Split the array into segments. Each segment contains 
           consecutive elements with the same number of set bits.
        2. From left to right, the previous segment’s largest 
           element should be smaller than the current segment’s smallest element.

    Time complexity: O(m * log n), 
    where n is the value of the largest number in the array
    and we have m elements in nums.
    Space complexity: O(m), where m is the size of the input array nums.
    """
    def canSortArray(self, nums: List[int]) -> bool:
        segments = [] 
        prev_setbitcount = -1

        for num in nums:
            cur_setbitcount = self.countSetBits(num)
            if cur_setbitcount == prev_setbitcount:
                segments[-1].append(num)
            else:
                segments.append([num])
                prev_setbitcount = cur_setbitcount
        
        for i in range(len(segments) - 1):
            if max(segments[i]) > min(segments[i + 1]):
                return False
        return True