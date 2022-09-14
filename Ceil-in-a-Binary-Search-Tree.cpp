/*
Ceil from BST- EASY - https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0

Given a binary search tree and an integer 'x' return the ceil value of the interger 'x'.

*/

// Time complexity: O(n) if the tree is skewed.
// Space complexity: O(1)
// Reference: https://www.youtube.com/watch?v=KSsk8AhdOZA

/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    int ceil_val=-1;
    while(node!=NULL){
        if(node->data==x){
            return x;
        }
        else if(node->data>x){
            ceil_val=node->data;
            node=node->left;
        }
        else node=node->right;
    }   
    return ceil_val;
}

