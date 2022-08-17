/*
SUBTRACT - EASY - https://www.interviewbit.com/problems/subtract/

Given a singly linked list, modify the value of first half nodes such that :

1st node’s new value = the last node’s value - first node’s current value
2nd node’s new value = the second last node’s value - 2nd node’s current value,
and so on …

NOTE :

If the length L of linked list is odd, then the first half implies at first floor(L/2) nodes. So, if L = 5, the first half refers to first 2 nodes.
If the length L of linked list is even, then the first half implies at first L/2 nodes. So, if L = 4, the first half refers to first 2 nodes.
Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5,

You should return 4 -> 2 -> 3 -> 4 -> 5

as

for first node, 5 - 1 = 4
for second node, 4 - 2 = 2
Try to solve the problem using constant extra space.

Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a question? Checkout Sample Codes for more details.

Reference: https://www.geeksforgeeks.org/modify-contents-linked-list/
*/
// Not optimised solution: Time complexity: O(n^2). You will get TLE error. This is brute force approach.
/*
//
// Definition for singly-linked list.
// -----------------------------------------------
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
// -----------------------------------------------
//
ListNode* Solution::subtract(ListNode* A) {
    ListNode* cur=A;
    int n = 0;
    while(cur!=NULL){
        n++;
        cur=cur->next;
    }
    
    cur=A;int cnt=0;
    for(int i=0;i<n/2;i++){
        cnt = i;
        ListNode* ithnode = cur;
        while(cnt!=n-i-1){
            ithnode = ithnode->next;
            cnt++; 
        }
        cur->val = ithnode->val-cur->val;
        cur=cur->next;
    }
    return A;
}
*/
//----------------------------------------------------------------------------------------------------------------------
//-----------------------------OPTIMISED CODE(ACCEPTED IN INTERVIEWBIT)-------------------------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverseList(ListNode*head_ref)
{
    /*
        APPROACH: Use three pointers current, previous, next. Intialize current=head, prev=NULL
        1. Iterate until current!=NULL.
        2. At every iteration:
            i. Make next point to current->next
            ii. Make current->next point to previous.
            iii. Update previous and make it point to current.
            iv. Update current and make it point to next.
    */
    ListNode *current, *prev, *next;
    current = head_ref;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }   
    head_ref = prev;
    return head_ref;
}
int find_SLL_length(ListNode* A){
    ListNode* cur=A;
    int n=0;
    while(cur!=NULL){
        n++;
        cur=cur->next;
    }
    return n;
}

ListNode* getmidNode(ListNode*A, int n){
    int mid;
    ListNode*right=A;
    if(n%2!=0)
        mid = (n+1)/2;
    else mid = n/2;
    for(int i=0;i<mid;i++)
        right=right->next;
    return right;
}
/*
Solution Approach: Split the SLL in the middle. IF the SLL length is odd then the extra node in the middle goes to the first half.
Reverse the right half and run two pointers left and right until right!=NULL. Perform left->val=right-<val - left->val and make prev=left
We need prev when the SLL is even because then left will move to the first node of right half by the time right=NULL.
*/
// Time complexity: O(n), space complexity: O(1)
// Reference: https://www.geeksforgeeks.org/modify-contents-linked-list/
ListNode* Solution::subtract(ListNode* A) {
    int n = find_SLL_length(A), mid;
    if(n==1) return A;
    
    ListNode* left = A;
    ListNode* right=getmidNode(A,n);
    right=reverseList(right);
    
    ListNode * cur=right;
    ListNode* prev = NULL;
    while(right!=NULL){
        left->val = right->val - left->val;
        prev=left;        
        left=left->next;
        right=right->next; 
        
        
    }
    right = reverseList(cur);
    if(n%2!=0)
        left->next=right;
    else
        prev->next=right;
    return A;
}

