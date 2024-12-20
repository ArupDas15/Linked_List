# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        current = head
        
        while current is not None:
            next_node = current.next  # Store next node
            current.next = prev       # Reverse the current node's pointer
            prev = current            # Move prev and current one step forward
            current = next_node
        
        return prev  # prev will be the new head of the reversed list