"""
Time complexity: To determine the frequency is O(n) where n is length of string s
heapify operation will take O(n) time.
The max heap will contain k nodes where k is unique characters in s
If we perform a heap pop and heap push for every character in the string in worst case assuming the repeatLimit is 1
then we perform O(n) heap operations with every heap operation taking O(log k) time.
Thus, the time complexity is: O(nlogk)

Space complexity: O(log k) because there are only k unique characters so there will be only k nodes.
"""
class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        max_heap = [(-ord(c), cnt) for c, cnt in Counter(s).items()]
        heapq.heapify(max_heap)
        result = []

        while max_heap:
            large_char, cnt = heapq.heappop(max_heap)
            char = chr(-large_char)
            use = min(cnt, repeatLimit)
            result.append(char * use)
            if cnt > use and max_heap:
                next_large_char, next_cnt = heapq.heappop(max_heap)
                result.append(chr(-next_large_char))
                if next_cnt > 1:
                    heapq.heappush(max_heap,(next_large_char, next_cnt-1))
                heapq.heappush(max_heap, (large_char, cnt-use))
         
        return "".join(result)