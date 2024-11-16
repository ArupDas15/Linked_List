class Solution {
public:
    /*
    There is a point in the array called the inflection point at which:
            1. All the elements to the left of the inflection point are sorted.
            2. All the elements to the right of the inflection point including 
               the inflection point are sorted.
        if nums[mid] < nums[right] then nums[mid ... right] is sorted. In this case,
        we shift right to mid because we need to find the inflection point including nums[mid].
        otherwise, left = mid + 1 because we know that nums[mid] is not the inflection point for sure.
        when left == right we stop.
    Time Complexity: O(log n) since we are using Binary Search.
    Space Complexity: O(n)
    */
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;

        while(left <= right) {
            if ((nums[left] < nums[mid]) and (nums[mid] < nums[right])) {
                // if search space is sorted then the inflection point 
                // is the minimum value thus return nums[left].
                return nums[left];
            }
            // check if nums[mid ... right] is sorted.
            if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
            mid = (left + right) / 2;
        }
        return nums[mid];
    }
};