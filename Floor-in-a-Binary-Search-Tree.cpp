/*
Floor in BST - MEDIUM - https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0

You are given a BST with N nodes and a value 'X'. find the greatest value node of the BST which is smaller than or equal to 'X'.
Note: 'X' is not smaller than the smallest node of the BST.

*/
// Time complexity: O(n) if the tree is skewed.
// Space complexity: O(1)
// Reference: https://www.youtube.com/watch?v=xm_W1ub-K-w

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    int floor_val=-1;
    while(root!=NULL){
        if(root->val==X){
            return X;
        }
        else if(root->val>X){
            root=root->left;
        }
        else{
            floor_val=root->val;
            root=root->right;
        }
    }
    return floor_val;
}
