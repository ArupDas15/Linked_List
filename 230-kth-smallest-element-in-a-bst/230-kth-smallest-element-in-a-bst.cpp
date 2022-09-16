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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        stack<TreeNode*>st;
        st.push(root);
        count = 1;
        TreeNode* cur_node =root->left;
        a: while(cur_node!=NULL){
            st.push(cur_node);
            cur_node=cur_node->left;
        }
        while(!st.empty()){
            auto element = st.top();
            st.pop();
            if(count==k){
                count=element->val;
                break;
            }
                
            count++;
            cur_node=element->right;
            goto a;
        }
        return count;
    }
};