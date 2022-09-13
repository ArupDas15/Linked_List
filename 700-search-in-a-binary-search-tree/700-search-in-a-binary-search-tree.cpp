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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)return NULL;
        TreeNode* cur_node=root;
        while(cur_node!=NULL&&cur_node->val!=val){
            if(cur_node->val<val)
                cur_node=cur_node->right;
            else if (cur_node->val>val)
                cur_node=cur_node->left;
        }
        if(cur_node!=NULL&&cur_node->val==val)return cur_node;
        return NULL;
    }
};