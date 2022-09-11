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
    vector<int> preorderTraversal(TreeNode* root) {
         vector < int > preorder;
        TreeNode* curr_node = root;
        // Time Complexity: O(n) Since we are traversing all the nodes in the given binary tree.
        while(curr_node!=NULL){
            // Case 1: There exists no left subtree for the given node.
            if(curr_node->left==NULL){
                preorder.push_back(curr_node->val);
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
                // node, add the current node into into preorder vector and move to left
                // subtree of the current node.
                if(leftSubtree_node->right==NULL){
                    leftSubtree_node->right=curr_node;
                    preorder.push_back(curr_node->val);
                    curr_node=curr_node->left;
                }
                // Case 3: Since the rightmost node of the left subtree is connected to the 
                // current node, it means that the left subtree is already visited. So we
                // move to the right subtree of the current node.
                else{
                    leftSubtree_node->right=NULL;
                    curr_node=curr_node->right;
                }
            }// end of outer else-construct.
        }// end of while-loop.
 
        return preorder;
    }
};