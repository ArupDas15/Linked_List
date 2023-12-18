class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int maxProductDifference(vector<int>& nums) {
        int largest = INT_MIN;
        int smallest = INT_MAX;
        int second_largest = INT_MIN;
        int second_smallest = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > largest) {
                second_largest = largest;
                largest = nums[i];
            } else if(nums[i] > second_largest) {
                second_largest = nums[i];
            }
            if(nums[i] < smallest) {
                second_smallest = smallest;
                smallest = nums[i];
            } else if(nums[i] < second_smallest) {
                second_smallest = nums[i];
            }
        }
        return ((largest * second_largest) - (smallest * second_smallest));
    }
};