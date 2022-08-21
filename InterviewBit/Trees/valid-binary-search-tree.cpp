/*
Valid Binary Search Tree - EASY - https://www.interviewbit.com/problems/valid-binary-search-tree/

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
Both the left and right subtrees must also be binary search trees.
Example :

Input : 
   1
  /  \
 2    3

Output : 0 (False)


Input : 
  2
 / \
1   3

Output : 1 (True) 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

SOLUTION APPROACH :

        VIDEO : https://www.youtube.com/watch?v=yEwSGhSsT0U

Complete solution in the hints.
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int checkValid(TreeNode* root, int min, int max){
    if(root == NULL){
        return 1;
    }
    else if((root->val < max) && 
        (root->val > min) && 
        (checkValid(root->left, min, root->val)) &&
        (checkValid(root->right, root->val, max))){
        return 1;        
    }
    return 0;
} 

int Solution::isValidBST(TreeNode* A) {
    return checkValid(A, INT_MIN, INT_MAX);
}
