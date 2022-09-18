/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Time Complexity: O(n), Space Complexity: O(n) for the recursive calls.
// Code to find LCA in a Binary Search Tree: https://github.com/ArupDas15/Linked_List/blob/master/235-lowest-common-ancestor-of-a-binary-search-tree/235-lowest-common-ancestor-of-a-binary-search-tree.cpp

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val==p->val||root->val==q->val) return root;
        TreeNode* lca1=lowestCommonAncestor(root->left, p, q);
        TreeNode* lca2=lowestCommonAncestor(root->right, p, q);
        if(lca1!=NULL && lca2!=NULL) return root;
        if(lca2==NULL)return lca1;
        else return lca2;
    }
};
