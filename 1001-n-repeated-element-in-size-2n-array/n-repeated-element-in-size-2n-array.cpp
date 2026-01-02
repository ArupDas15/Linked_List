class Solution {
public:

    int repeatedNTimes(vector<int>& nums) {
        // the repeated number occurence is dence; it fills half the array
        // Case: 1 - the repeated number is adjacent
        // case 2 - the repeated number is non-adjacent
        for(int i=0;i+1 < nums.size(); i++) {
           if(nums[i] == nums[i+1]) return nums[i];
           if(i+2 < nums.size() and nums[i] == nums[i+2]) return nums[i];
           if(i+3 < nums.size() and nums[i] == nums[i+3]) return nums[i];
        }
        return -1;
    }
    // int repeatedNTimes(vector<int>& nums) {
    // Time Complexity: O(n), space complexioty: O(N)
    //     set<int> s;

    //     for(int i=0;i <= nums.size(); i++) {
    //         if(s.find(nums[i]) == s.end()) {
    //             s.insert(nums[i]);
    //         } else return nums[i];
    //     }
    //     return -1;
    // }
};