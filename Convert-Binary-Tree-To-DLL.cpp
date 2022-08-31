/*
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be 
used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be the same as in Inorder 
for the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL. 
*/
// Reference: https://www.geeksforgeeks.org/convert-given-binary-tree-doubly-linked-list-set-3/
// Time Complexity: O(n)
// Space complexity: O(H) ~ O(log N). The extra space is used in recursion call stack which can grow upto a maximum size of logN as it is a binary tree.
// To convert a Binary tree to Circular Doubly linked List (Reference: https://www.geeksforgeeks.org/convert-a-binary-tree-to-a-circular-doubly-link-list/)
// you can first convert it to a DLL and then to a circular doubly linked list.

#include <iostream>
using namespace std;

// To represents a node of a Binary Tree
struct Node {
	struct Node *left, *right;
	int data;
};

// A function that converts a Binary Tree to Doubly Linked List.
Node* BTToDLL(Node* root){
    static Node* prev=NULL;
    if(root==NULL)
        return root;
    Node* head= BTToDLL(root->left);
    if(prev==NULL)head=root;
    else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    BTToDLL(root->right);
    return head;
}

// Display Doubly Link List
void displayDLL(Node* head)
{
    if(head==NULL)return;
	cout << "Doubly Linked List is :\n";
	Node* itr = head;
	do {
		cout << itr->data << " ";
		itr = itr->right;
	} while (itr != NULL);
	cout << "\n";
}

// Create a new Node and return its address
Node* newNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver Program to test above function
int main()
{
	Node* root = newNode(10);
	root->left = newNode(5);
	root->right = newNode(20);
	root->right->left = newNode(30);
	root->right->right = newNode(35);

	Node* head = BTToDLL(root);
	displayDLL(head);

	return 0;
}


