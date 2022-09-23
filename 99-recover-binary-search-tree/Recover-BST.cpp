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
// Naive Approach: Obtain the inorder traversal of the BST. Sort the inorder tracersal. Compare elements of BST while doing unorder traversal with sorted inorder traversal. Wherever the elements do not match just change it with the correct value from the sorted traversal.
// The time complextiy for this approach is O(n)+O(nlog n)+O(n) and space complexity is O(n).

// Reference: https://www.youtube.com/watch?v=ZWGW7FminDM&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=53
// Time Complexity: O(Height of the BST)
// Space Complexity: O(Height of the BST) but if we use morris inorder traversal we can reduce space complexity to O(1).
class Solution {
public:
    TreeNode * first;
    TreeNode * prev;
    TreeNode * middle;
    TreeNode * last;
    void inorder(TreeNode* root){
        if(root==NULL)return;
        inorder(root->left);
        // We have detected a violation.
        if(prev!=NULL && (root->val< prev->val)){
            // if it is a first violation
            if(first==NULL){
                first=prev;
                middle=root;
            }
            // Second violation detected.
            else{
                last=root;
            }
        }
        // Mark the cur_node as prev.
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        // Case 1: The nodes to be swapped are not adjacent to each other.
        if(first && last)
            swap(first->val, last->val);
        // Case 2: The nodes to be swapped are adjacent to each other.
        else if(first && middle)
            swap(first->val, middle->val);
    }
};
