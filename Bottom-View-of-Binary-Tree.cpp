/*
Bottom View of Binary Tree - MEDIUM - https://www.codingninjas.com/codestudio/problems/bottom-view-of-binary-tree_893110?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0

Given a binary tree, print its bottom view from left to right. Assume, the left and the right child make a 45-degree angle with the parent,

A binary tree is a tree in which each parent node has at most two children.

A node will be in the bottom-view if it is the bottom-most node at its horizontal distance from the root.
*/

/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

/*
APPROACH: The logic for top view and bottom view is exactly same. In top view (https://github.com/ArupDas15/Linked_List/blob/master/Top-View-of-Binary-Tree.cpp)
we insert into the map only once because all other nodes on lower level are hidden by the nodes at the higher 
level. In bottom view we replace the existing nodes at a particular vertical level in the map because we got another node on lower node that hides the node at the upper 
level (horizontal level).
Reference: https://www.youtube.com/watch?v=0FtVY6I4pB8&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=24
*/

// Time Complexity: O(n), Space Complexity: O(n)

#include<bits/stdc++.h>
vector<int> bottomView(BinaryTreeNode<int> * root){

    vector<int> ans;
    if(root == NULL) return ans; 
    map<int,int> mp;
    queue<pair<BinaryTreeNode<int>*,int>>q;
    q.push({root,0});
    while(q.empty()==false){
        auto p = q.front();
        q.pop();
        BinaryTreeNode<int>*curr_node = p.first;
        int vertical = p.second;
        mp[vertical]=curr_node->data;
        
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
