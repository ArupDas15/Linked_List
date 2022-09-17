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
// Time Complexity: O(n) since you are visiting every node for BST validation.
// Space complexity: O(n)
// Reference: https://www.youtube.com/watch?v=f-sj7I5oXEI
// Apporach: We specify a range for every node to check if it satisfies the properties of a BST. 

class Solution {
public:
    bool checkBST(TreeNode* root, long int maxVal, long int minVal){
        if(root==NULL)return true;
        // We do not want duplicate values in the BST so we have <= and >= condition over here.
        if(root->val<=minVal||root->val>=maxVal)return false;
        return (checkBST(root->left,root->val,minVal)) && (checkBST(root->right,maxVal,root->val));
    }
    bool isValidBST(TreeNode* root) {
        // We a re specifying LONG_MAX (2^32-1) and LONG_MIN (-2^31+1) instead of INT_MAX (2^15-1) and INT_MIN (-2^15+1) becuase -2^31 <= Node.val <= 2^31 - 1.
       return checkBST(root,LONG_MAX, LONG_MIN);
    }
};
