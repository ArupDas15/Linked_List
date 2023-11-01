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
    int cur_streak = 0;
    int max_streak = 0;
    int prev = 100001;

    vector<int> findMode(TreeNode* root) {
        vector<int> ans;

        inorder_traversal(root, ans);
        return ans;
    }

    void inorder_traversal(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        inorder_traversal(root->left,ans);
        if (prev == root->val) {
            cur_streak++;
        } else {
            cur_streak = 1;
            prev = root->val;
        }
        if (cur_streak > max_streak) {
            max_streak = cur_streak;
            ans.clear();
            ans.push_back(root->val);
        } else if (cur_streak == max_streak) {
            ans.push_back(root->val);
        }
        inorder_traversal(root->right,ans);
    }
};