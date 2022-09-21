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
// Reference: https://www.youtube.com/watch?v=D2jMcmxU4bs&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=52
// Approach: We are going to use the iterative inorder traversal but store only the root and 
// the left most elements of the root in the BST into a stack. This way whenever we do 
// next() call, the lowest value node will be there in the stack top which we can easily pop 
// in O(1) time. After popping a node we will push all the nodes to the left of the right 
// child of the popped node as well as the right child node into the stack.

// Time Complexity: O(1). It is O(1) time complexity because we are storing at max O(n) 
// nodes and next() will call for n nodes in the worst case. Since every call will take O(1)
// time so n next() calls will take n*O(1)=O(n) time.
// Space complexity: O(Height of the BST) ~ O(n)
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    int next() {
        TreeNode* cur_node = st.top();
        st.pop();
        pushAllLeft(cur_node->right);
        return cur_node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    void pushAllLeft(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
