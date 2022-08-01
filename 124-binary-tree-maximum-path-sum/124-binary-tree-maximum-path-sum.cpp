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
    int solve(TreeNode* root, int &res){
        // Base Case: Empty binary tree.
        if(root == nullptr)
            return 0;
        // Hypothesis
        int left = solve(root->left, res);
        int right = solve(root->right, res);
        // Induction
        int temp_ans = max(max(left, right), 0) + root->val;
        int ans = max(temp_ans, left + root->val + right);
        res = max(res, ans);
        // Pass the maximum subtree sum upwards.
        return temp_ans;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};