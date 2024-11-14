class Solution {
public:
    /* ALGORITHM:
    1. create a dictionary umap of key-> nums[i], val -> index (i), initalise ans = []
    2. iterate over nums:
        2.1. if umap[target - nums[i]] and umap[target - nums[i]] != current num index exists.
            2.1.1. store umap[nums[i]].val and umap[target - nums[i]].val in ans
    3. return ans 
    Time complexity: O(n)
    Space complexity: O(n)
    */ 
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map: key-> nums[i], val -> index (i)
        unordered_map<int,int> umap;
        vector<int> ans(2,0);
        // Time compleity: O(n)
        for(int index = 0; index < nums.size(); index++) {
            umap[nums[index]] = index;
        }
        for(int i = 0; i < nums.size(); i++) {
            if ((umap.find(target - nums[i]) != umap.end()) && 
                (umap[target - nums[i]] != i)) {
                ans[0] = i;
                ans[1] = umap[target - nums[i]];
                break;
            }
        }
        return ans;
    }
};