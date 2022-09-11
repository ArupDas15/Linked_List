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
// Reference: https://www.youtube.com/watch?v=80Zug6D1_r4
// time Complexity: O(n), Space Complexity: O(1).
// Based on Morris Traversal. Morris Traversal uses threaded binary tree.
/*
 Summary of the approach:
 In-order Morris Traversal:
🌳 1st case: if left is null, print current node and go right
🌳 2nd case: before going left, make right most node on left subtree connected to current node, then go left
🌳 3rd case: if thread is already pointed to current node, then remove the thread
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector < int > inorder;
        TreeNode* curr_node = root;
        // Time Complexity: O(n) Since we are traversing all the nodes in the given binary tree.
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

/*
Below is my observation regarding Morris Inorder Traversal:

We are visiting the left subtree thrice:

1. To mark the reference to the current node from the rightmost node of the left subtree of the current node.
2. To perform inorder traversal and store the key in the inoder vector.
3. To check if there exists a link to the current node, then remove the link and go to the right subtree of the current node.

It is the rightmost subtree in the binary tree, which is visited only once. So we can say the time complexity is O(3n), i.e. O(n).
*/
