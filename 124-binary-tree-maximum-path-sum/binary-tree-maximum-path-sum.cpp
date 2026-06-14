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
    int find_maxtPathSum(TreeNode* root, int& global_max) {
        if (!root) {
            // return 0 if null node
            return 0;
        }
        int left = find_maxtPathSum(root->left, global_max);
        int right = find_maxtPathSum(root->right, global_max);
        // Determine the candidate answer => 
        // max path sum from all the recursive calls until now.
        global_max = max(global_max, root->val + max(0,left) + max(0, right));
        return max(0, root->val + max({0,left,right}));
    }
    int maxPathSum(TreeNode* root) {
        int global_max = INT_MIN;
        find_maxtPathSum(root, global_max);
        return global_max;
    }
};