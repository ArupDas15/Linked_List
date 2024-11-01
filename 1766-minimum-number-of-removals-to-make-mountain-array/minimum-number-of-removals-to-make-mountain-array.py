class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        # Denotes the LIS ending at index i
        LIS = [1] * len(nums)
        # Denotes the LDS starting at index i
        LDS = [1] * len(nums)
        min_removals = float("inf")

        for i in range(len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:
                    LIS[i] = max(LIS[i], 1 + LIS[j])
        for i in range(len(nums) - 1, -1, -1):
            for j in range(i+1, len(nums)):
                if nums[i] > nums[j]:
                        LDS[i] = max(LDS[i], 1 + LDS[j])
        # return len(nums) + 1 - (max(LIS)+max(LDS))
        for i in range(len(nums)):
            # This condition is necessary because if either value is 1
            # then a valid mountain array cannot be formed.
            if LIS[i] > 1 and LDS[i] > 1:
                min_removals = min(
                    min_removals, len(nums) + 1 - LIS[i] - LDS[i] 
                )
        
        return min_removals if min_removals != float("inf") else 1