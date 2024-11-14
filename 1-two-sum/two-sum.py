class Solution:
    # Time complexity: O(n)
    # Space complexity: O(n)
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = dict()
        for index in range(len(nums)):
            complement = target - nums[index]
            if complement in hashmap:
                return [index, hashmap[complement]]
            else:
                hashmap[nums[index]] = index
        return []
        