class Solution:
    def minLength(self, s: str, numOps: int) -> int:
        binary_arr = []
        for char in s:
            binary_arr.append(int(char))
        group_arr = []
        for binary_num, itr in groupby(binary_arr):
            group_size = len(list(itr))
            group_arr.append(group_size)

        def operationsCount(length):
            if length == 1:
                ops_for_odd_position_1s = sum([int(val == ind % 2) for ind, val in enumerate(binary_arr)])
                ops_for_even_position_1s = sum([int(val != ind % 2) for ind, val in enumerate(binary_arr)])
                return min(ops_for_odd_position_1s, ops_for_even_position_1s)
            return sum([ group_size // (length + 1) for group_size in group_arr])

        l = 1
        r = len(s)
        res = -1
        while l <= r:
            mid = (l + r) // 2
            if operationsCount(mid) > numOps:
                l = mid + 1
            else:
                r = mid - 1
                res = mid
        return res
        
    