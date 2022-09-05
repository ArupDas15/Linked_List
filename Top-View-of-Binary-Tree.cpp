/*
Top View of Binary Tree - MEDIUM - https://www.codingninjas.com/codestudio/problems/top-view-of-the-tree_799401?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos

You are given a Binary Tree of Integers. You are supposed to return the top view of the given binary tree. The Top view of the binary tree is the set of nodes that are visible when 
we see the tree from the top.

For each test case, return the vector/list of all the elements of the top view of the given tree.

Reference: https://www.youtube.com/watch?v=Et9OCDNvJ78
This question is a variation of vertical order tree traversal.
*/
/*
APPROACH: We will perform level order traversal of the tree and enqueue elements into the queue with their vertical level information. We will maintain a map
to keep track of all the nodes at different vertical levels that we have encountered while popping a node from this queue. If a node belonging to a particular 
level is not present in the map then we enqueue it into the map. Finally we push the value of every key(i.e. vertical level) into the ans vector and return the 
ans vector. 
*/
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
// Time Complexity: O(n), Space Complexity: O(n) 
vector<int> getTopView(TreeNode<int> *root) {
    vector<int>ans;
    if(root == NULL) return ans; 
    map<int,int> mp;
    queue<pair<TreeNode<int>*,int>>q;
    q.push({root,0});
    while(q.empty()==false){
        auto p = q.front();
        q.pop();
        TreeNode<int>*curr_node = p.first;
        int vertical = p.second;
        if(mp.find(vertical)==mp.end()){
            mp[vertical]=curr_node->val;
        }
        if(curr_node->left!=NULL){
            q.push({curr_node->left,vertical-1});
        }
        if(curr_node->right!=NULL){
            q.push({curr_node->right,vertical+1});
        }
    }
    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;
}
