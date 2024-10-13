class Solution:
    """   STEPS
    1. Initialise k to number of lists.
    2. Initialise left and right to first element in the list.
    3. Initialise a heap.
    4. Run a loop from o to k-1.
        4.1. left = min(left, current_list[0])
        4.2. right = max(right, current_list[0])
        4.3. insert element here current_list[0], current_list index, index of the element in current list to min_heap. 
    5. Initialise res to [left, right] 
    6. while(True): [Note: Iterate until one of the elements in the list go out of bound:]
    6.1. Extract the min element from min_heap.
            6.1.1. Heap pop: min_ele <-minimum element
                            list_idx <- min element list index i
                            idx <- index of the min element in the ith list.
    6.2. if idx+1 == len(nums[list_idx]) then return res.
    6.3. Initialise next_val to nums[list_idx][idx+1]
    6.4. Push next_val, list_idx, idx+1 to min_heap.
    6.5. left <- min element from min_heap
    6.6. right <- max(right, next_val)
    6.7. if res[1] - res[0] > right - left then res = [left,right]
    
    Time complexity: Let's say there are n elements in every list. since we compute the minimum out of k lists.
    The time complexity becomes O(nk). However, if we use a minheap the time complexity become O(nlogk).
    Space complexity: O(k)

    """
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        k = len(nums)
        left = right = nums[0][0]
        min_heap = []
        
        for i in range(0, k):
            left = min(left, nums[i][0])
            right = max(right, nums[i][0])
            heapq.heappush(min_heap, (nums[i][0], i, 0))
        res = [left, right]

        while(True):
            min_ele, list_idx, idx = heapq.heappop(min_heap)
            if idx+1 == len(nums[list_idx]):
                return res
            next_val = nums[list_idx][idx+1]
            heapq.heappush(min_heap, (next_val, list_idx, idx+1))
            left = min_heap[0][0]
            right = max(right, next_val)
            if res[1] - res[0] > right - left:
                res = [left, right]