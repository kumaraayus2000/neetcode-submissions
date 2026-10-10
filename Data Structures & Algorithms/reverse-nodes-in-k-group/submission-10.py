# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        #check first if nodes are more than k

        count = 0

        tmp = head
        while tmp and count<k:
            tmp=tmp.next
            count+=1

        if count<k:
            return head

        curr = head
        prev = None
        tmp1 = head
        count1=0
        while curr and count1<k:
            tmp1 = curr.next
            curr.next = prev
            prev= curr
            curr = tmp1
            count1+=1

        head.next = self.reverseKGroup(curr,k)

        return prev

