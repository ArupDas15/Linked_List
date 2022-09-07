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

// Approach: We will pass the left and right root of the subtree and perform root, left, right traversal for left subtree while simultanouesly performing 
// root, right, left traversal for the right subtree and checking if the root at both the left and right subtree contain the same value in the node.
// We are doing the traversal in this way because we want the root node to be the same around the center of the tree (i.e. the root node of the binary tree).

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
