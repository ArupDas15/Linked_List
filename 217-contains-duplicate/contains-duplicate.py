class Solution:
    # Time compelxity: O(n)
    # Space complexity: O(n)
    def containsDuplicate(self, nums: List[int]) -> bool:
        hash_table = set()
        
        for i in range(len(nums)):
            if nums[i] not in hash_table:
                hash_table.add(nums[i])
            else:
                return True
        return False
        