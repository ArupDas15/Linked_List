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
private:
    vector<int> ans;
public:
    void getinorder(TreeNode* root) {
        if(root == nullptr)return;
        getinorder(root->left);
        ans.push_back(root->val);
        getinorder(root->right);
    }
    // Time Complexity: O(n) - You are travelling through all the nodes.
    // Space Complexity: O(n)
    vector<int> inorderTraversal(TreeNode* root) {
        getinorder(root);
        return ans;
    }
};