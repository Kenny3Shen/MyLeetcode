#
# @lc app=leetcode.cn id=25 lang=python3
# @lcpr version=30204
#
# [25] K 个一组翻转链表
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
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        n = 0
        p = head
        while p:
            n += 1
            p = p.next

        dummy = ListNode(next=head)
        p0 = dummy

        pre = None
        cur = p0.next
        while n >= k:
            n -= k
            for _ in range(k):
                nxt = cur.next
                cur.next = pre
                pre = cur
                cur = nxt
                
            p0_next = p0.next
            p0.next.next = cur
            p0.next = pre
            p0 = p0_next
        return dummy.next


# @lc code=end


#
# @lcpr case=start
# [1,2,3,4,5]\n2\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,4,5]\n3\n
# @lcpr case=end

#
