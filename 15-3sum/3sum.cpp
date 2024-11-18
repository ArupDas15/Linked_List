class Solution {
public:
    /* ALGORITHM
    1. Sort the array becasue we do not want to store duplicates and we are using
       2 pointer technique so sorting can help to avoid returning duplicate triplets into the solution.
    2. Initialise vector<vector<int>> ans to store the solutions.
    3. Iterate using i over nums array.
        3.1. if nums[i] == nums[i - 1] increment i (so as to skip duplicate triplet).
        3.2. Initialise j = i + 1 and k = nums.size() - 1
        3.3. while j < k:
            3.3.1. Initialise sum = nums[i] + nums[j] + nums[k]
            3.3.2. If sum == 0 add the triplet to ans, increment j and decrement k. 
                   Now check if nums[j] == nums[j-1] then keep incrementing j until false so as to avoid duplicate triplet.
                   Similarly, check if mnums[k] == nums[k + 1] then keep decrementing k until false so as to avoid duplicate triplet.
            3.3.3. If sum < 0 increase j
            3.3.3. If sum > 0 decrease k
    */
    // Time complexity: O(n^2)
    // Space complexity: O(number of unique triplets)
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (( j < k) && (nums[j] == nums[j - 1])) {
                        j++;
                    }
                    while ((j < k) && (nums[k] == nums[k + 1])) {
                        k--;
                    }
                } else if (sum < 0) {
                    j++;
                } else { // sum > 0
                    k--;
                }
            }
        }
        return ans;
    }
};