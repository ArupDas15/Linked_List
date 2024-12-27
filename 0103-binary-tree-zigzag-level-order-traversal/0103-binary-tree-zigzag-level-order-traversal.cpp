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
    // Time Complexity: O(n)
    // Space complexity: O(2^h)=O(2^(log n)) in worst case when the tree is balanced = O(n)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        int count=0;
        vector<vector<int>>ans;
        if(root==nullptr)return ans;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>v;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node!=nullptr)
                    v.push_back(node->val);
                if(node->left!=nullptr)
                    q.push(node->left);
                if(node->right!=nullptr)
                    q.push(node->right);    
            }
            if (count%2!=0)
                reverse(v.begin(),v.end());
            ans.push_back(v);
            count++;
        }
        return ans;
    }
};