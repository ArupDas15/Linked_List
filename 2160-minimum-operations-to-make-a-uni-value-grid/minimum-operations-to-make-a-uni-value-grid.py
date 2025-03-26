class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        num_arr = [ele for row in grid for ele in row]
        ans = 0
        
        num_arr.sort()
        median_ele = num_arr[len(num_arr) // 2]
        for ele in num_arr:
            if ele%x != median_ele%x: 
                return -1
            else: ans += abs(ele - median_ele)//x

        return ans