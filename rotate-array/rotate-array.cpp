class Solution {
public:
void reverse_array(vector<int>& nums, int start, int end){
        int temp;
        while (start < end){
           // Swap elements at start index and end index  
            temp = nums[start];  
            nums[start] = nums[end];
            nums[end] = temp;
            start = start + 1;
            end = end - 1;
    }
}
void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse_array(nums, 0, nums.size() - k - 1);
        reverse_array(nums, nums.size() - k, nums.size() - 1);
        reverse_array(nums, 0, nums.size() - 1);
}
};