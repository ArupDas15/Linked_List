/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;

        ListNode *hare = head;
        ListNode *tortise = head;

        while(hare != NULL and hare->next != NULL) {
            hare = hare->next->next;
            tortise = tortise->next;
            if(hare == tortise) return true;
        }
        return false;
    }
};