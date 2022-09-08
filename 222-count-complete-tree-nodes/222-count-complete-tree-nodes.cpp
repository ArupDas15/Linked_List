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
/* 
Approach: We will use the idea that for a perfect binary tree the number of nodes is 2^h-1.
If the left height and right height of the tree is equal then we do not need to traverse the
perfect binary subtree any further down. Since we are given as input a complete binary tree
the right subtree will in worst case be a perfect binary tree and we will need to traverse all
the nodes in the left subtree (O(log N) nodes). While finding the height of the tree we will
do O(log N) work. So the total time complexity of this algorithm will be: O(log N)^2.

Space Complexity: O(log N) due to the recursive calls made to calculate the height of the left
and right subtree.
*/

class Solution {
public:
    int findLeftHeight(TreeNode* root){
        int count=0;
        while(root!=NULL){
            count++;
            root=root->left;
        }
        return count;
    }    
    int findRightHeight(TreeNode* root){
        int count=0;
        while(root!=NULL){
            count++;
            root=root->right;
        }
        return count;
    }    
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);
        if(lh==rh)
            return(pow(2,lh)-1);
        else return countNodes(root->left)+1+countNodes(root->right) ;
    }
};