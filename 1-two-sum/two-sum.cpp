class Solution {
public:
    /* ALGORITHM
    1. We create a hash table with key-> nums[i] and val-> index (i)
    2. During every insert in the hash table we check if target-nums[i] already esits.
        2.1.1 If it exists we return the pair, otherwise we insert nums[i].
    Time complexity: O(n)
    Space complexity: O(n)
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        // key-> nums[i] and val-> index (i)
        unordered_map<int,int> umap;
        for(int index = 0; index < nums.size(); index++) {
            if (umap.find(target - nums[index]) != umap.end()) {
                return vector<int> {
                    index, umap[target - nums[index]]
                    };
            } else {
                umap[nums[index]] = index;
            }
        }
        return vector<int> ();


    }
};