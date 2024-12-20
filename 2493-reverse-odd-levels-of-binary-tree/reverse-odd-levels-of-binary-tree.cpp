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
    TreeNode* reverseOddLevels(TreeNode* root) {
        DFS(root->left, root->right, 0);
        return root;
    }
    void DFS(TreeNode* left_child, TreeNode* right_child, int level) {
        if (!left_child || !right_child) {
            return;
        }
        if (level % 2 == 0) {
            int temp = left_child->val;
            left_child->val = right_child->val;
            right_child->val = temp;
        }
        DFS(left_child->left, right_child->right, level + 1);
        DFS(left_child->right, right_child->left, level + 1);
    }
};