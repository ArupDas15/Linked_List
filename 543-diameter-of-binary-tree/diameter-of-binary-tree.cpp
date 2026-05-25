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
    int solve(TreeNode* root, int& global_max) {
        if (!root) return 0;
        int left = 0;
        int right = 0;
        // Recurse if left child exists
        if (root->left) left = solve(root->left, global_max);
        // Recurse if right child exists
        if (root->right) right = solve(root->right, global_max);
        global_max = max(max(1+max(left, right), 1+left+right), global_max);
        return 1+max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int global_max = 0;
        solve(root, global_max);
        return global_max-1;
    }
};