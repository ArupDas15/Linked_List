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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        else if (head->next==nullptr){
            return head;
        }
        else{
            ListNode* dummy=nullptr, *next;
            next = head->next;
            while(next!=nullptr){
              head->next = dummy;
              dummy = head;
              head= next;  
              next = head->next;  
            }
            if(next==nullptr&&head!=nullptr){
                head->next=dummy;
                dummy=head;
            }
            return dummy;
        }
    }
};