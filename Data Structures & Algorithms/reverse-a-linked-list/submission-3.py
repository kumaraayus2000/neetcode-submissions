# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        tmp = head

        current = head

        prev = None

        while tmp is not None:
            tmp=tmp.next
            current.next = prev
            prev=current
            current = tmp

        return prev

        