class Solution {
public:
/*     STEPS
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
    The time complexity becomes O(nk). However, if we use a minheap the time complexity become O(nlogk) where logk is the time taken for insertion.
    Space complexity: O(k) because we store k elements in the min_heap at every iteration.
*/
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        int left = nums[0][0];
        int right = nums[0][0];
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> min_heap;
        vector<int> res{2, 0};
        for(int i = 0; i < k; i++) {
            left = min(left, nums[i][0]);
            right = max(right, nums[i][0]);
            min_heap.push(make_tuple(nums[i][0], i, 0));
        }
        res[0] = left;
        res[1] = right;
        while(true) {
            auto [min_ele, list_idx, idx] = min_heap.top();
            min_heap.pop();

            if (idx + 1 == nums[list_idx].size()) {
                return res;
            }
            int next_val = nums[list_idx][idx + 1];
            min_heap.push(make_tuple(next_val, list_idx, idx + 1));
            left = get<0>(min_heap.top());
            right = max(right, next_val);
            if (res[1] - res[0] > right - left) {
                res[0] = left;
                res[1] = right;
            }
        }
    }
};