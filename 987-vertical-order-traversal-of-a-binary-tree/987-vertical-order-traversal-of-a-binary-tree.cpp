/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Time Complexity: O(n), Space Complexity: O(n)
// Reference: https://www.youtube.com/watch?v=q_a6lpbKJdw&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=22
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //queue -> <Key,<Vertical,level>>
        queue<pair<TreeNode*,pair<int,int>>> q;
        // Map -> Vertical: map -> level: multiset{Key}>
        map<int,map<int,multiset<int>>> mp;
        q.push({root,{0,0}}); //initial vertical and level
        pair<TreeNode*,pair<int,int>> p;
        while (q.empty()==false) {
            p = q.front();
            q.pop();
            TreeNode* curr_node = p.first;
            int vertical = p.second.first;
            int level = p.second.second;
            // Insert the key to multiset. By using a multiset we are able to insert multiple duplicate keys into a particular vertical (row) and level (column). 
            mp[vertical][level].insert(curr_node -> val); 
            // Push the left child of the curr_node into the queue.
            if (curr_node -> left) {
                q.push({curr_node -> left,{vertical - 1, level + 1}});
            }
            if (curr_node -> right) {
                q.push({curr_node -> right,{vertical + 1,level + 1}});
            }
        }
        
        vector < vector < int >> ans;
        for (auto p: mp) {
            vector < int > col;
            for (auto q: p.second) {
                // Appends a set to the end of the col vector.
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
}
};
