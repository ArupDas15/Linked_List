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
        // Base Case.
        if(root == nullptr)
            return 0;
        // Hypothesis
        int left = solve(root->left, res);
        int right = solve(root->right, res);
        int temp_ans = 1 + max(left, right);
        int ans = max(temp_ans, 1 + left + right);
        res = max(res, ans);
        // Pass the maximum subtree length higher up.
        return temp_ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        solve(root, res);
        // Number of edges between any two nodes in a Directed Acyclic Graph
        // like binary tree is number of nodes in the path - 1.
        return res-1;
    }
};