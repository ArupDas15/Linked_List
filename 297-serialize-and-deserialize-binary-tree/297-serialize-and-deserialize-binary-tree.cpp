/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto cur_node = q.front();
            q.pop();
            if(cur_node==NULL)s.append("#,");
            else s.append(to_string(cur_node->val)+",");
            if(cur_node!=NULL){
                q.push(cur_node->left);
                q.push(cur_node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        // Used for parsing the string input. It associates a string object with a stream allowing you to read from the string as if it were a stream (like cin).
        stringstream s(data);
        string str;
        // The getline() function extracts characters from the input stream and appends it to the string object until the delimiting character is encountered.
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto cur_node = q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                cur_node->left=NULL;
            }
            else{
                TreeNode* leftnode=new TreeNode(stoi(str));
                cur_node->left=leftnode;
                q.push(leftnode);
            }
            getline(s,str,',');
            if(str=="#"){
                cur_node->right=NULL;
            }
            else{
                TreeNode* rightnode=new TreeNode(stoi(str));
                cur_node->right=rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));