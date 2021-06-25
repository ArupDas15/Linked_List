/* APPROACH 
1) Sort input array in increasing order. 
2) If all elements are positive, then return the product of the last two numbers. 
3) Else return a maximum of products of the first two and last two numbers. 
Time complexity: O(nlogn)
Space complexity: O(1)
The sort() internally uses IntroSort. In more details it is implemented using hybrid of QuickSort, HeapSort and InsertionSort.
By default, it uses QuickSort but if QuickSort is doing unfair partitioning and taking more than N*logN time, it switches to HeapSort 
and when the array size becomes really small, it switches to InsertionSort.
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return max((nums[0]-1)*(nums[1]-1),(nums[nums.size()-1]-1)*(nums[nums.size()-2]-1));
    }
};
