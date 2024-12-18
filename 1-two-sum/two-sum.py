class Solution:
    # Time complexity: O(n)
    # Space complexity: O(n)
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = dict()
        for idx, ele in enumerate(nums):
            if (hashmap.get(target - ele) is not None) and (hashmap[target - ele] != idx):
                return [idx, hashmap[target-ele]]
            else:
                hashmap[ele] = idx
        
        return []
        