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