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
// Efficient Solution using Hashing: Time Complexity: O(n), Space Complexity: O(n)
// construct Unique Binary Tree from Inorder and Preorder Traversal: https://github.com/ArupDas15/Linked_List/blob/master/Binary-Tree-from-Inorder-and-Preorder.cpp 
class Solution {
public:
    // Create a new Node and return its address
    TreeNode* newNode(int data)
    {
	    TreeNode* temp = new TreeNode();
	    temp->val = data;
	    temp->left = temp->right = NULL;
	    return temp;
    }
    
    TreeNode* cTree(unordered_map<int,int>&ump,vector<int>& postorder, int is, int ie, int &postIndex){
        if(is>ie)return NULL;
        TreeNode*root=newNode(postorder[postIndex--]);
        int inIndex = ump[root->val];
        root->right = cTree(ump,postorder,inIndex+1,ie,postIndex);
        root->left = cTree(ump,postorder,is,inIndex-1,postIndex);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	if (inorder.size() != postorder.size())
            return NULL;
        int n=inorder.size();
        unordered_map<int,int>ump;
        for(int i=0;i<n;i++){
            ump[inorder[i]]=i;
        }
        int postIndex=n-1;
        return cTree(ump,postorder,0,n-1,postIndex);
    }
};
