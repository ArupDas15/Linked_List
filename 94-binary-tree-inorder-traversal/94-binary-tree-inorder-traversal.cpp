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
// Based on Morris Traversal. Morris Traversal uses threaded binary tree.
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector < int > inorder;
        TreeNode* curr_node = root;
        while(curr_node!=NULL){
            // Case 1: There exists no left subtree for the given node.
            if(curr_node->left==NULL){
                inorder.push_back(curr_node->val);
                curr_node=curr_node->right;
            }
            else{
                TreeNode* leftSubtree_node = curr_node->left;
                // Find the rightmost node of the left subtree and connect it to current
                // node. Amortised Time complexity: O(n) i.e. even though we run this
                // while loop for every node in total its time complexity will be O(n).
                while(leftSubtree_node->right!=NULL && leftSubtree_node->right!=curr_node){
                    leftSubtree_node=leftSubtree_node->right;
                }
                // Case 2: Connect the rightmost node of the left subtree to the current
                // node.
                if(leftSubtree_node->right==NULL){
                    leftSubtree_node->right=curr_node;
                    curr_node=curr_node->left;
                }
                // Case 3: Since the rightmost node of the left subtree is connected to the 
                // current node, it means that the left subtree is already visited. So we
                // can push the current node into the inorder vector and move to the right
                // subtree of the current node.
                else{
                    leftSubtree_node->right=NULL;
                    inorder.push_back(curr_node->val);
                    curr_node=curr_node->right;
                }
            }// end of outer else-construct.
        }// end of while-loop.
 
        return inorder;
    }
};