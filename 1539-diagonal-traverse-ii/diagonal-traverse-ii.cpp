class Solution {
public:
    // Time Complexity: O(n) where n is the number of elements in the 2D arr.
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
            int key = it.first;
            while(!mp[key].empty()) {
                ans.push_back(mp[key].top());
                mp[key].pop();
            }
        }
        return ans;
    }
};
