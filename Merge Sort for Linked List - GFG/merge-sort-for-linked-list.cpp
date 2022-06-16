// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

Node* getmidnode(Node* head){
    if(head==NULL){
        return NULL;
    }
    //if there exists only two nodes in the SLL.
    else if(head->next->next==NULL){
        return head;
    }
    Node* slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        
    }
    return slow;
}
Node* sortedMerge(Node*a, Node*b){
    Node* dummy=new Node(0);
    Node* tail=dummy;
    while(1){
        if(a==NULL){
            tail->next=b;
            break;
        }
        else if(b==NULL){
            tail->next=a;
            break;
        }
        else if(a->data<=b->data){
            tail->next=a;
            a=a->next;
        }
        else{
            tail->next=b;
            b=b->next;
        }
        tail=tail->next;
    }
    return dummy->next;
}
class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // If no node or only one node exists in the SLL.
        if(head==NULL||head->next==NULL){
            return head;
        }
        // If at least two nodes exists in the SLL.
        else{
            Node *mid = getmidnode(head);
            Node *r_head = mid->next;
            mid->next=NULL;
            Node* left = mergeSort(head);
            Node* right = mergeSort(r_head);
            return sortedMerge(left,right);
        }
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends