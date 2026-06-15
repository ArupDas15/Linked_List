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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head->next;
        ListNode* curr = head;
        int n = 0;
        while(curr != nullptr) {
            curr=curr->next;
            n++;
        }
        curr=head;
        for(int i=0;i<n/2;i++){
            if(i==(n/2)-1) {
                ListNode* temp=curr->next;
                curr->next=curr->next->next;
                delete temp;
                break;
            }
            curr=curr->next;
        }
        return head;
    }
};