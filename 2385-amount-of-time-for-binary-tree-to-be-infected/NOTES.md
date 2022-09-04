/*
Time To Burn Tree - HARD - https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqa2FuMXhxYklTamFLcjF4clRUaFhEWTZlX192Z3xBQ3Jtc0ttbHBHTkxfcHVDYXJ1dTh4WHl6UGZTa2JMdG9aZk5xYm5UU3dwTWNEUHZpVFREZUZWaEJEX3FKdnI4LTgxUGVDbWQwZmRkQWtOeW1UUXM4WWdGVXZNYmRQOTN6elZhc3cySkE3bEhtbExmMG90Z2Uxcw&q=https%3A%2F%2Fbit.ly%2F3z3YEJY&v=2r5wLmQfD6g

You are given a binary tree with 'N' unique nodes and a Start node from where the tree will start to burn. Given that the start node
will always exist in the tree, your task is to print the time (in minutes) that it will take to burn the whole tree.
It is given that it takes 1 minutes for the fire to travel from the burning node to its adjacent node and burn down the adjacent node.

Reference: https://www.youtube.com/watch?v=2r5wLmQfD6g&t=1s (Striver)
*/
// Time complexity: O(n) But we are doing two BFS traversals over here. One for markling the parent and second for finding the time taken to burn the tree.
// Space complexity: O(n)
```
/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
int burnTime(map <BinaryTreeNode<int>*,BinaryTreeNode<int>*>&omp,BinaryTreeNode<int>* start){
    queue<BinaryTreeNode<int>*> q;
    map <BinaryTreeNode<int>*, int>vis;
    int timer=0;
    q.push(start);
    vis[start]=1;
    BinaryTreeNode<int>* curr_node;
    bool flg;
    while(q.empty()==false){
        int count = q.size();
        flg=false;
        for(int i=0;i<count;i++){
            curr_node=q.front();
            q.pop();
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
        // We update the timer only when a node gets burnt.
        if(flg==true){
            timer++;
        }
    }
    return timer;
}

BinaryTreeNode<int>* MarkParentbyBFS(BinaryTreeNode<int>* root, int start,map <BinaryTreeNode<int>*,BinaryTreeNode<int>*>&omp){
    queue<BinaryTreeNode<int>*> q;
    BinaryTreeNode<int>* res;
    q.push(root);
    BinaryTreeNode<int>* curr_node;
    while(q.empty()==false){
        curr_node=q.front();
        q.pop();
        if(curr_node->data==start){
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

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    map <BinaryTreeNode<int>*,BinaryTreeNode<int>*> omp;
    BinaryTreeNode<int>* start_node=MarkParentbyBFS(root,start,omp);
    return burnTime(omp,start_node);
}
```
