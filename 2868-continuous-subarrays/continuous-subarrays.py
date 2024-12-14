class Solution:
    """
    Algorithm: Use a frequency dictionary to store the frequency of every element in the sliding window.
    Begin the sliding window with left=right=0 and run a loop until right < len(nums).
    Inside the loop, first increment freq[nums[right]] += 1 and then check while max(dict) - min(dict) > 2 increment left and decrement freq
    Time complexity: O(n)
    Space complexity: O(1)
    The sorted map stores elements within the current window. Since the difference between any two elements in a valid 
    window cannot exceed 2, the maximum number of unique elements (k) possible in the map at any time is 3. Therefore, the space complexity is constant, O(1).
    """
    def continuousSubarrays(self, nums: List[int]) -> int:
        freq = defaultdict(int)
        left = right = 0
        count = 0

        while right < len(nums):
            freq[nums[right]] += 1

            while max(freq) - min(freq) > 2:
                freq[nums[left]] -= 1
                if freq[nums[left]] == 0:
                    del freq[nums[left]]
                left +=1
            
            count += right - left + 1
            right += 1
        
        return count