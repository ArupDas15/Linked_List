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
// Check out Striver's solution, it is almost the same but instead of maxlevel he has used ans.size()==level concept. Basically he is using lesser number of arguments in 
// the function call.

// Time Complexity: O(n), Space Complexity: O(Height of the binary tree)~ O(n)
class Solution {
public:
    void getrightSideView(TreeNode* root, int & maxlevel, int level, vector<int>&ans)     {
        if(root==NULL)return ;
        if(maxlevel<level){
            ans.push_back(root->val);
            maxlevel=level;
        }
        getrightSideView(root->right,maxlevel,level+1,ans);
        getrightSideView(root->left,maxlevel,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
       vector<int>ans;
        int maxlevel=0;
        if(root==NULL)return ans;
        getrightSideView(root,maxlevel, 1, ans);
        return ans;
    }
};
