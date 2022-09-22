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
// Reference: https://www.youtube.com/watch?v=ssL3sHwPeb4&feature=youtu.be
// Time Complexity: O(n)
// Space complexity: 2*O(Height of the binary tree)
class BSTIterator{
    private:
    // reverse = tree -> push right node
    // reverse = false -> push left node
    bool reverse;
    stack<TreeNode*> st;
    public:
    BSTIterator(TreeNode* root,bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* cur_node = st.top();
        st.pop();
        if(reverse==false)
            pushAll(cur_node->right);
        else pushAll(cur_node->left);
        return cur_node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    void pushAll(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            if(reverse==false)
                root=root->left;
            else root=root->right;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();  
        int j=r.next();
        // Observe here that we cannot do l.hasNext()!=NULL && r.hasNext()!=NULL instead of i<j because then for i==j we will considering 
        // the same element twice and it might be equal to k and the code will return true where as the expected answer is false. 
        while(i<j){  
            if(i+j==k)return true;
            else if(i+j>k)
                j=r.next();
            else i=l.next();
        }
        return false;
    }
};
