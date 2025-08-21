#
# @lc app=leetcode.cn id=445 lang=python3
# @lcpr version=30204
#
# [445] 两数相加 II
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse(self, head: Optional[ListNode]) -> Optional[ListNode]:
        pre =None
        cur = head
        while cur:
            nxt = cur.next
            cur.next = pre
            pre = cur
            cur = nxt
        return pre
    
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        l1 = self.reverse(l1)
        l2 = self.reverse(l2)

        carry = 0
        dummy = ListNode()
        cur = dummy
        while l1 or l2 or carry:
            if l1:
                carry += l1.val
                l1 = l1.next
            if l2:
                carry += l2.val
                l2 = l2.next
            carry, val = carry // 10, carry % 10
            cur.next = ListNode(val)
            cur = cur.next
        
        return self.reverse(dummy.next)
# @lc code=end



#
# @lcpr case=start
# [7,2,4,3]\n[5,6,4]\n
# @lcpr case=end

# @lcpr case=start
# [2,4,3]\n[5,6,4]\n
# @lcpr case=end

# @lcpr case=start
# [0]\n[0]\n
# @lcpr case=end

#

