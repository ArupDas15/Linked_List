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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        stack<TreeNode* >s1;// Contains elements which have to be printed in natural order left-to-right.
        stack<TreeNode* >s2;// Contains elements which have to be printed in reverse order right-to-left.
        s1.push(root);
        while(!s1.empty()||!s2.empty()){
            vector<int>temp_ans;
            while(!s1.empty()){
                TreeNode*cur_node=s1.top();
                s1.pop();
                temp_ans.push_back(cur_node->val);
                if(cur_node->left!=NULL)
                    s2.push(cur_node->left);
                if(cur_node->right!=NULL)
                    s2.push(cur_node->right);
            }
            if(temp_ans.size()>0){ // If we do not check for size of temp answer then an empty vector will get inserted into ans vector.
                ans.push_back(temp_ans);
                temp_ans.clear();//Time Complexity: O(N) 
            }
            while(!s2.empty()){
                TreeNode*cur_node=s2.top();
                s2.pop();
                temp_ans.push_back(cur_node->val);
                if(cur_node->right!=NULL)
                    s1.push(cur_node->right);
                if(cur_node->left!=NULL)
                    s1.push(cur_node->left);
            }
            if(temp_ans.size()>0){
                ans.push_back(temp_ans);
                temp_ans.clear();//Time Complexity: O(N) 
            }
        }
        
        return ans;
    }
};