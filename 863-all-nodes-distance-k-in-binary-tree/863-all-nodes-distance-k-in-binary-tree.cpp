/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> burnTime(map <TreeNode*,TreeNode*> &omp,TreeNode* start, int K){
    vector<int>ans;
    queue<TreeNode*> q;
    map <TreeNode*, int>vis;
    int timer=0;
    q.push(start);
    vis[start]=0;
    TreeNode* curr_node;
    bool flg;
    while(q.empty()==false){
        int count = q.size();
        flg=false;
        for(int i=0;i<count;i++){
            curr_node=q.front();
            q.pop();
            if(curr_node->left!=NULL && vis.find(curr_node->left) == vis.end()){
                q.push(curr_node->left);
                if(flg==false)vis[curr_node->left]=++timer;
                else vis[curr_node->left]=timer;
                cout<<"Curr node: "<<curr_node->val<<", left: "<<curr_node->left->val<<", Time: "<<vis[curr_node->left]<<endl;
                flg=true;
            }
            if(curr_node->right!=NULL && vis.find(curr_node->right) == vis.end()){
                q.push(curr_node->right);
                if(flg==false)vis[curr_node->right]=++timer;
                else vis[curr_node->right]=timer;
                flg=true;
                cout<<"Curr node: "<<curr_node->val<<", right: "<<curr_node->right->val<<", Time: "<<vis[curr_node->right]<<endl;
            }
            if( omp[curr_node] && vis.find(omp[curr_node]) == vis.end()){
                q.push(omp[curr_node]);
                if(flg==false)vis[omp[curr_node]]=++timer;
                else vis[omp[curr_node]]=timer;
                flg=true;
                cout<<"Curr node: "<<curr_node->val<<", Parent: "<<omp[curr_node]->val<<", Time: "<<vis[omp[curr_node]]<<endl;
            }
        }
    }
    for(auto itr:vis){
        cout<<itr.first->val<<"->"<<itr.second<<endl;
        if(itr.second==K)
            ans.push_back(itr.first->val);
    }
    return ans;
}

void MarkParentbyBFS(TreeNode* root,map <TreeNode*,TreeNode*>&omp){
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* curr_node;
    while(q.empty()==false){
        curr_node=q.front();
        q.pop();
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
}
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map <TreeNode*,TreeNode*> omp;
        MarkParentbyBFS(root,omp);
        return burnTime(omp,target,k);
    }
};