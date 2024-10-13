/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Time complexity: The number of passes needed to reduce k lists to one list can be expressed in logarithmic terms: log⁡2(\U0001d458).
    // The process involves comparing the nodes of both lists and linking them in order. This takes linear time, specifically O(N), where N is the total number of nodes in the two lists being merged.
    // So time complexity is O(Nlogk).
    // Space complexity: O(N) for the recursive call stack in the worst case, if all nodes are stored in the call stack during the merging process.
    // When you merge two linked lists recursively, each recursive call processes one node from one of the lists at a time.
    ListNode* merge(ListNode *L, ListNode *R) {
        if(L == NULL) return R;  // If L is empty, return R
        if(R == NULL) return L;  // If R is empty, return L
        ListNode *res = NULL;  // This will point to the head of the merged list
        if(L->val < R->val) {  // Compare values of L and R
            res = L;           // If L's value is smaller, set res to L
            res->next = merge(L->next, R);  // Recursively merge the rest of L with R
        } else {
            res = R;           // If R's value is smaller or equal, set res to R
            res->next = merge(L, R->next);  // Recursively merge L with the rest of R
        }
        return res;           // Return the head of the merged list       
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = NULL;  // Initialize the answer list
        for(int i = 0; i < lists.size(); i++) {
            ans = merge(ans, lists[i]);  // Merge each list into ans
        }
        return ans;  // Return the final merged list
    }
};