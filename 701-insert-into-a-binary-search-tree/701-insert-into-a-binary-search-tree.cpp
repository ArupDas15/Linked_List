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

// Approach: Find where the new node can be placed and insert it over there.
// Time complexity: O(log n) assuming we have a height balanced binary search tree.
// Space complexity: O(1)
// Reference: https://www.youtube.com/watch?v=FiFiNvM29ps

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)return new TreeNode(val);
        TreeNode* cur_node=root;
        while(true){
            if(cur_node->val<=val){
                if(cur_node->right!=NULL)cur_node=cur_node->right;
                else{
                    cur_node->right=new TreeNode(val);
                    return root;
                }
            }
            else {
                if(cur_node->left!=NULL)cur_node=cur_node->left;
                else{
                    cur_node->left=new TreeNode(val);
                    return root;
                }
            }
        }
    }
};
