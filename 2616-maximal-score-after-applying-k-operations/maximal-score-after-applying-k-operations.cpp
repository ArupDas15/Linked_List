class Solution {
public:
    /* STEPS
    1. initialise a max heap by inserting all the elements in nums. -> O(nlogn)
    2. Iterate k times. -> O(klogn)
        2.1. ele = Pop max ele.
        2.2. Add ele to ans
        2.3. insert ceil(ele/3) to max heap.
    3. Return ans
    NOTE:  To ensure that any remainder in the division causes 
    the result to round up (i.e., taking the ceiling), 
    you can add n−1 to the numerator, where n is the divisor.
    ceil(ele / 3.0) != ceil((float)ele / 3.0) because 
    ceil((float)ele / 3.0) is also floating-point but 
    may be impacted by how ele is cast and calculated. 
    If ele is very large, the conversion to float may 
    introduce precision issue. Yo can observe this issue with
    nums = [756902131,995414896,95906472,149914376,387433380,848985151]
    and k = 6. The expected output is 3603535575 but if you ceil((float)ele/3.0)
    you get 3603535580.
    Time Complexity: O(nlogn + klogn)
    Space Complexity: O(n)
    */
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
            ele = ceil(ele / 3.0);
            max_heap.push(ele);
        }
        return ans;
    }
};
