/*
Next Pointer Binary Tree - EASY - https://www.interviewbit.com/problems/next-pointer-binary-tree/

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
Example :

Given the following perfect binary tree,

         1
       /  \
      2    5
     / \  / \
    3  4  6  7
After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 5 -> NULL
     / \  / \
    3->4->6->7 -> NULL
Note that using recursion has memory overhead and does not qualify for constant space.
*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    if(A == NULL)return;
    
    queue<pair<int, TreeLinkNode*> > q;
    
    q.push({0, A});

    while(!q.empty()){
        pair<int, TreeLinkNode*> temp = q.front();

        int level = temp.first;
        q.pop();

//      Keep putting the nodes until we are on the same level.
        while(!q.empty() and q.front().first == level){
            if(temp.second->left)
                q.push({level+1, temp.second->left});
            if(temp.second->right)
                q.push({level+1, temp.second->right});

            temp.second->next = q.front().second;
            temp = q.front();

            q.pop();
        }
//      
        temp.second->next = NULL;
        
//      if the control doesn't enter the above while loop, accomodate
//      the left out nodes. (Consider a three node tree!)
        if(temp.second->left)
            q.push({level+1, temp.second->left});
        if(temp.second->right)
            q.push({level+1, temp.second->right});
        
    }
}
