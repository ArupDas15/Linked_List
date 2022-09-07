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
// Time Complexity: O(n), Space Complexity: O(n)
// Reference: https://www.youtube.com/watch?v=nKggNAiEpBE&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=26
class Solution {
public:
    bool checkSymmetric(TreeNode* leftSubtreeRoot,TreeNode* rightSubtreeRoot){
        if(leftSubtreeRoot==NULL||rightSubtreeRoot==NULL)
            return leftSubtreeRoot==rightSubtreeRoot;
        
        if(leftSubtreeRoot->val!=rightSubtreeRoot->val) 
            return false;
        
        return (checkSymmetric(leftSubtreeRoot->left,rightSubtreeRoot->right) && checkSymmetric(leftSubtreeRoot->right,rightSubtreeRoot->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        
        return checkSymmetric(root->left,root->right);
    }
};
