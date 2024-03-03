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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i;
        int length = 0;
        ListNode* curr = head;

        while(curr != nullptr) {
            length++;
            curr = curr->next;
        }
        curr = head;
        i = 1;
        if(length - n == 0) {
            head = head->next;
            delete curr;
            return head; 
        }
        while(i < length - n) {
            curr = curr->next;
            i++;            
        }
        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return head;
    }
};