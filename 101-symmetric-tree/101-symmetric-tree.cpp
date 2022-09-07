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
    bool checkSymmetric(TreeNode* leftSubtreeRoot,TreeNode* rightSubtreeRoot){
        if(leftSubtreeRoot==NULL||rightSubtreeRoot==NULL)return leftSubtreeRoot==rightSubtreeRoot;
        
        if(leftSubtreeRoot->val!=rightSubtreeRoot->val) return false;
        return (checkSymmetric(leftSubtreeRoot->left,rightSubtreeRoot->right)&&checkSymmetric(leftSubtreeRoot->right,rightSubtreeRoot->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return checkSymmetric(root->left,root->right);
    }
};