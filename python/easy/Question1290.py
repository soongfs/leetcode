# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def getDecimalValue(self, head: Optional[ListNode]) -> int:
        ans = 0
        while head != None:
            ans <<= 1
            ans += head.val
            head = head.next
        return ans


if __name__ == "__main__":
    node0 = ListNode(1, None)
    node1 = ListNode(1, None)
    node2 = ListNode(1, None)
    node0.next = node1
    node1.next = node2
    print(Solution().getDecimalValue(node0))
