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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root == nullptr) {
            return ans;
        }
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int count = q.size();
            vector<int> temp;
            
            // For even level: left to right traversal
            for(int i = 0; i < count; i++) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            if (level%2 != 0) {
                reverse(temp.begin(), temp.end());
            }
            for(int i = 0; i < temp.size(); i++) {
                cout<<temp[i]<<" ";
            }cout<<endl;
            ans.push_back(temp);
            level++;
        }
        return ans;
    }
};