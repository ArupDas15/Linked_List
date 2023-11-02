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
    int count = 0;

    int averageOfSubtree(TreeNode* root) {
        postorder_traversal(root);
        return count;
    }

    // return node_sum, node_count
    pair<int, int> postorder_traversal(TreeNode* root) {
        int avg = 0;
        int node_sum = 0;
        int node_count = 0;
        pair<int, int> left; 
        pair<int, int> right;

        if(root == nullptr) {
            return {0, 0};
        }
        left = postorder_traversal(root->left);
        right = postorder_traversal(root->right);
        node_count = left.second + right.second + 1;
        node_sum = left.first + right.first + root->val;
        avg = node_sum / node_count;
        if (root->val == avg) {
            count++;
        }
        return {node_sum, node_count};
    }
};