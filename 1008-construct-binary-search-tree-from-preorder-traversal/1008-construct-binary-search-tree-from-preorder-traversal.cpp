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
    
    // Reference: (Striver) youtube.com/watch?v=UmJT3j26t1I&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=49
    
    // This question is similar to building a binary tree from the preorder traversal and 
    // inorder traversal, where we can obtain the inorder traversal by just sorting the 
    // preorder vector(this takes O(nlog n) time) and then we can use the concept of Range 
    // of a node[Lower Limit, Higher Limit] to construct the tree. This will all together 
    // take O(n log n) + O(n) time. We can optimise this further by observing that the Lower 
    // Limit(root value) is already known to us, we just need to find the upper limit. By 
    // doing this, in the worst case we are visiting a node three times. So our time compleixty 
    // becomes O(3n) ~ O(n).
    
    // Space Complexity: O(n)
    TreeNode* buildTree(vector<int>&preorder,int &i, int ub){
        if(i == preorder.size() || preorder[i] > ub)
            return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left = buildTree(preorder, i, root->val);
        root->right = buildTree(preorder, i, ub);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return buildTree(preorder, i, INT_MAX);
    }
};
