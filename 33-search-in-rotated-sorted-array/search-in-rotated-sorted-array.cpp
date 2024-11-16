class Solution {
public:
    /*
    The array was originally sorted in ascending order. Now that the the array is
    rotated one section of the array is definitely sorted in ascending order. So
    we can divide the search space into two, determine which half is sorted and check
    for the target in the sorted half. If the target is not present in the sorted
    half then we eliminate the sorted section and check for the target in the unsorted
    section. This way we use Binary Search to dividing the search space into two and check
    the sorted space for the target.
    Time complexity: O(log n)
    Space complexity: O(1)
    */
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        while(left <= right) {
            mid = (left + right) / 2;

            if (nums[mid] == target){
                return mid;
            }
            // First check if the right half of the array is sorted.
            // Since the array elements are unique we don't check for <= case.
            if (nums[mid] < nums[right]) {
                if ((target >= nums[mid]) and (target <= nums[right])) {
                    // Since target is in sorted right half update left to mid.
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                // if right half is not sorted then left half is definitely sorted.
                if ((target >= nums[left]) and (target <= nums[mid])) {
                    // Since target is in sorted left half update right to mid.
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};