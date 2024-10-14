class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int,vector<int>> max_heap;
        long long ans = 0;
        for(int i = 0 ; i < nums.size(); i++) {
            max_heap.push(nums[i]);
        }
        while(k>0) {
            int ele = max_heap.top();
            max_heap.pop();
            k--;
            ans = ans + (long long) ele;
            ele = (ele + 2) / 3;
            max_heap.push(ele);
        }
        return ans;
    }
};