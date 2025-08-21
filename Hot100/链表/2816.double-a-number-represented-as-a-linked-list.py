#
# @lc app=leetcode.cn id=2816 lang=python3
# @lcpr version=30204
#
# [2816] 翻倍以链表形式表示的数字
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
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        head = self.reverse(head)
        carry = 0
        dummy = ListNode()
        while head or carry:
            if head:
                carry += head.val * 2
                head = head.next
            carry, val = carry // 10, carry % 10
            # 头插法
            node = ListNode(val, dummy.next)
            dummy.next = node
        return dummy.next
# @lc code=end



#
# @lcpr case=start
# [1,8,9]\n
# @lcpr case=end

# @lcpr case=start
# [9,9,9]\n
# @lcpr case=end

#

