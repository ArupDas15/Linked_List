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
If the left height(height from the root to the left most leaf node) and right height (height 
from the root to the right most leaf node) of the tree is equal then we do not need to traverse 
the perfect binary subtree any further down. Since we are given as input a complete binary tree
the right subtree will in worst case be a perfect binary tree and we will need to traverse all
the nodes in the left subtree (O(log N) nodes). While finding the height of the tree we will
do O(log N) work. So the total time complexity of this algorithm will be: O(log N)^2.

Space Complexity: O(log N) due to the recursive calls made to calculate the height of the left
and right subtree.
*/
// Reference (Striver): https://www.youtube.com/watch?v=u-yWemKGWO0&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=33

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
        // Find the height from the root node to the left most leaf node.
        int lh = findLeftHeight(root);
        // Find the height from the root node to the right most leaf node.
        int rh = findRightHeight(root);
        // if the left height and right height are equal then it is perfect binary tree and we can directly apply the formula (2^h-1).
        if(lh==rh)
            return(pow(2,lh)-1);
        // We will recursively find all the perfect binary subtrees in the given complete binary tree.
        else return countNodes(root->left)+1+countNodes(root->right) ;
    }
};
