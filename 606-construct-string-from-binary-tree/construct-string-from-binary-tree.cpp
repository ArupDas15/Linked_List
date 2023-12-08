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
    // Time Complexity: O(n)
    // Space Complexity: O(n)    
    void printPreorder(TreeNode* node,string& ans) {
        if (node == nullptr) {
            ans.append("()");
            return;
        } else {
            ans.append(to_string(node->val));
        }

        if(node->left != nullptr and node->right == nullptr) {
            // if left subtree exists and right subtree does not - ignore 
            // right subtree
            ans.append("(");
            // Recur on left subtree
            printPreorder(node->left, ans);
            ans.append(")");
        } else if(node->left == nullptr and node->right != nullptr) {
            // if left subtree does not exists and right subtree does -
            // do not ignore left subtree
            ans.append("()(");
            // Recur on right subtree
            printPreorder(node->right, ans);
            ans.append(")");
        } else if (node->left != nullptr and node->right != nullptr) {
            // if left and right subtree exists - recurse on both subtrees
            ans.append("(");
            // Recur on left subtree
            printPreorder(node->left, ans);
            ans.append(")");
            ans.append("(");
            // Recur on right subtree
            printPreorder(node->right, ans);
            ans.append(")");
        }
    }

    string tree2str(TreeNode* root) {
        string ans = "";
        printPreorder(root, ans);
        return ans;
    }
};
