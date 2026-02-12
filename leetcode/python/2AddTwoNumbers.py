# Definition for singly-linked list.
from typing import Optional


class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        dummy = ListNode(0)
        tail = dummy
        carry = 0

        while l1 or l2 or carry:
            if l1:
                l1Value = l1.val
            else:
                l1Value = 0

            if l2:
                l2Value = l2.val
            else:
                l2Value = 0

            total = l1Value + l2Value + carry
            carry = total // 10
            tail.next = ListNose(total % 10)
            tail = tail.next

            if l1: l1 = l1.next
            if l2: l2 = l2.next
        return dummy.next