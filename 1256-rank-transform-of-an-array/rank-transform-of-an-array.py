class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        map = {}
        copy_arr = sorted(arr)
        rank = 1
        ans = []

        for i in range(0, len(copy_arr)):
            if i > 0 and copy_arr[i] > copy_arr[i - 1]:
                rank = rank + 1
            map[copy_arr[i]] = rank
        for i in range(0, len(arr)):
            ans.append(map[arr[i]])
        return ans
        