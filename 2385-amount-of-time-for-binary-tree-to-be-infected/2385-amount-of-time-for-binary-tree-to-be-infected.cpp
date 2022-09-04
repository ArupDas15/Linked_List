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
// Similar question: https://github.com/ArupDas15/Linked_List/tree/master/863-all-nodes-distance-k-in-binary-tree 
// See notes too for this question.
// Time complexity: O(n) But we are doing two BFS traversals over here. One for markling the parent and second for finding the time taken to burn the tree.
// Space complexity: O(n)

int burnTime(map <TreeNode*,TreeNode*> &omp,TreeNode* start){
    queue<TreeNode*> q;
    map <TreeNode*, int>vis;
    int timer=0;
    q.push(start);
    vis[start]=1;
    TreeNode* curr_node;
    bool flg;
    while(q.empty()==false){
        int count = q.size();
        flg=false;
        for(int i=0;i<count;i++){
            curr_node=q.front();
            q.pop();
            // Instead of !vis[curr_node->left] use vis.find(curr_node->left) == vis.end()
            if(curr_node->left!=NULL && !vis[curr_node->left]){
                q.push(curr_node->left);
                vis[curr_node->left]=1;
                flg=true;
            }
            if(curr_node->right!=NULL && !vis[curr_node->right]){
                q.push(curr_node->right);
                vis[curr_node->right]=1;
                flg=true;
            }
            if( omp[curr_node] && !vis[omp[curr_node]]){
                q.push(omp[curr_node]);
                vis[omp[curr_node]]=1;
                flg=true;
            }
        }
        if(flg==true){
            // We update the timer only when a node gets infected.
            timer++;
        }
    }
    return timer;
}

TreeNode* MarkParentbyBFS(TreeNode* root, int start,map <TreeNode*,TreeNode*>&omp){
    queue<TreeNode*> q;
    TreeNode* res;
    q.push(root);
    TreeNode* curr_node;
    while(q.empty()==false){
        curr_node=q.front();
        q.pop();
        if(curr_node->val==start){
            res=curr_node;
        }
        if(curr_node->left!=NULL){
                //Mark current node -> parent node
                omp[curr_node->left]=curr_node;
                q.push(curr_node->left);
            }
            if(curr_node->right!=NULL){
                omp[curr_node->right]=curr_node;
                q.push(curr_node->right);
            }
        }
        return res;   
}

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        map <TreeNode*,TreeNode*> omp;
        TreeNode*start_node=MarkParentbyBFS(root,start,omp);
        return burnTime(omp,start_node);
    }
};
