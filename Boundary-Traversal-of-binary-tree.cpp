/*
Boundary Traversal of binary tree - Medium - https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3

Example 2:

Input:
            1
           /
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: 1 2 4 6 5 7 8

Your Task:
This is a function problem. You don't have to take input. Just complete the function boundary() that takes the root node as input and returns an array containing the boundary values in anti-clockwise.

Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes ≤ 10^5
1 ≤ Data of a node ≤ 10^5

/* Approach: Push the root node and start the following three traversals.
    1. First do left boundary traversal of binary tree excluding the leaf nodes.
    2. Then do inorder/preorder/postorder traversal just to print the left nodes. I have used inorder traversal.
    3. Finally, do right boundary traversal in reverse order. To do reverse right boundary traversal we will use a stack.
    NOTE: While doing the traversals it is very very important to check if the root node is null or not.

  Reference: 
	Striver: https://www.youtube.com/watch?v=0ca1nvR0be4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=21
	 GFG: https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
*/

//Time Complexity: O(n) , Space Complexity: O(H) where H is the height of the tree and recursive calls. If we implement 
// inorder traversal in iterative manner then space complexity for inorder traversal is O(1).

// A binary tree Node:
/* 
struct Node{
	int data;
	Node* left, *right;
};
*/

class Solution {
public:
    bool isLeaf(Node* node){
        if(node->left==NULL && node->right==NULL)
            return true;
        return false;
    }
    void leftBoundaryTraversal(Node * root, vector < int > & res) {
        //It is very very important to check if the root node is null or not. Your test cases will fail if you don't check this. As a thumb rule you can wrtie like this logic 
        // for every generic function concerning trees.
        if(root == NULL)
            return;
        if (isLeaf(root)) 
            return;
        // since it is a non-leaf node we can add its key value to the res vector.
        res.push_back(root->data);
        // Check if the left subtree of the non-leaf node exists.
        if(root->left!=NULL)
            leftBoundaryTraversal(root->left,res);
        // Only if the left subtree of the non-leaf node does not exist go to the right subtree.
        else 
            leftBoundaryTraversal(root->right,res);
    }

    void rightBoundaryTraversal(Node * root, vector < int > & res){
        //It is very very important to check if the root node is null or not. Your test cases will fail if you don't check this. As a thumb rule you can wrtie like this logic 
        // for every generic function concerning trees.
        if(root == NULL) 
            return;
        Node* curr_node = root;
        stack<int>  stk;
        while(isLeaf(curr_node) == false){
            // since it is a non-leaf node we can add its key value to the res vector.
            stk.push(curr_node->data);
            // Check if the right subtree of the non-leaf node exists.
            if(curr_node->right!=NULL)
                curr_node=curr_node->right;
            // Only if the right subtree of the non-leaf node does not exist go to the left subtree.
            else 
                curr_node=curr_node->left;
        }
        while(stk.empty()==false){
            res.push_back(stk.top());
            stk.pop();
        }
    }
    // We are doing inorder leaf traversal.
    void leafTraversal(Node*root,vector<int>&res){
        if (root == NULL)
            return;
        leafTraversal(root->left,res);
        if(isLeaf(root))
            res.push_back(root->data);
        leafTraversal(root->right,res);
    }
    vector <int> boundary(Node *root)
    {
        vector<int>res;
        if(root == NULL)
            return res;
        // Push the root node (only if it is not a leaf node) and start the following three traversals.
        if(isLeaf(root) == false)
            res.push_back(root->data);
        leftBoundaryTraversal(root->left,res);
        leafTraversal(root,res);
        rightBoundaryTraversal(root->right,res);
        return res;
    }
};
