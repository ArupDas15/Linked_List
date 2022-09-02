// Construct Binary Tree from Inorder and Preorder
/*
#include <iostream>
using namespace std;

// To represents a node of a Binary Tree
struct Node {
	struct Node *left, *right;
	int data;
};

// Display Inorder Tree Traversal.
void printInorder(Node* root)
{
    if(root==NULL)return;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

// Create a new Node and return its address
Node* newNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// A recursive function that converts a Binary Tree to Doubly Linked List.
Node* cTree(int in[],int pre[], int is, int ie, int &preIndex){
    if(is>ie)return NULL;
    Node* root=newNode(pre[preIndex++]);
    int inIndex;
    for(int i=is;i<=ie;i++)
    { // At every node we are doing O(n) work. So time complexity is O(n^2). We can reduce the time taken at every node
	// using a hashmap O(1). So then the time complexity will become O(n). Space complexity: O(H) = O(log N) Due to recursive calls.
        if(in[i]==root->data){
            inIndex=i;
            break;
        }
    }
    root->left=cTree(in,pre,is,inIndex-1,preIndex);
    root->right=cTree(in,pre,inIndex+1,ie,preIndex);
    return root;
}
// Driver Program to test above function
int main()
{
    int in[]={20,10,40,30,50};
    int pre[]={10,20,30,40,50};
    int preIndex=0;
	Node* root = cTree(in,pre,0,4,preIndex);
	printInorder(root);

	return 0;
}
*/
// Efficient Solution using Hashing: Time Complexity: O(n), Space Complexity: O(n) as we are storing the inorder traversal in an unordered map.
#include <bits/stdc++.h>
using namespace std;

// To represents a node of a Binary Tree
struct Node {
	struct Node *left, *right;
	int data;
};

// Display Inorder Tree Traversal.
void printInorder(Node* root)
{
    if(root==NULL)return;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

// Create a new Node and return its address
Node* newNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// A recursive function that converts a Binary Tree to Doubly Linked List.
Node* cTree(unordered_map<int,int>&mp,int pre[], int is, int ie, int &preIndex){
    if(is>ie)return NULL;
    Node* root=newNode(pre[preIndex++]);
    int inIndex=mp[root->data];
    root->left=cTree(mp,pre,is,inIndex-1,preIndex);
    root->right=cTree(mp,pre,inIndex+1,ie,preIndex);
    return root;
}
Node* solve(int in[],int pre[], int n){
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[in[i]]=i;
    }
    int preIndex=0;
    return cTree(mp,pre,0,n-1,preIndex);
}
// Driver Program to test above function
int main()
{
    int in[]={20,10,40,30,50};
    int pre[]={10,20,30,40,50};
    int preIndex=0;
	Node* root = solve(in,pre,5);
	printInorder(root);

	return 0;
}
