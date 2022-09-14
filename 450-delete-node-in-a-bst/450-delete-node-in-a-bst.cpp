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
    TreeNode* getSuccessor(TreeNode* root){
        TreeNode* cur_node=root->right;
        while(cur_node != NULL && cur_node->left != NULL){
            cur_node=cur_node->left;
        }
        return cur_node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(root->val>key){
            root->left = deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right = deleteNode(root->right,key);
        }
        else{ // root->val == key
            // Case 1: root node is a leaf node. So simply remove the root node.
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            // Case 2: A: The root node only contains a left child.
            else if(root->right==NULL){
                TreeNode* temp = root;
                root=root->left;
                delete temp;
                return root;
            }
            // Case 2: B: The root node only contains a right child.
            else if(root->left==NULL){
                TreeNode* temp = root;
                root=root->right;
                delete temp;
                return root;
            }
            // Case 3: The root node is an internal node having both left and right child.
            else{
                TreeNode* succ=getSuccessor(root);
                root->val = succ->val;
                root->right = deleteNode(root->right,succ->val);
            }
        }
        return root;
    }
};