class Solution {
public:
    // Time Complexity: O(nm)
    // Space Complexity: O(n)
    // Whenever asked to do diagonal traversal in a tree or diagonal 
    // matrix etc. think of a solution involving a map.
    
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, stack<int>> mp;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                mp[i + j].push(nums[i][j]);
            }
        }
        for(auto it : mp) {
            // int key = it.first;
            while(!mp[it.first].empty()) {
                ans.push_back(mp[it.first].top());
                mp[it.first].pop();
            }
        }
        return ans;
    }
};