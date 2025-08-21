#
# @lc app=leetcode.cn id=1669 lang=python3
# @lcpr version=30204
#
# [1669] 合并两个链表
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
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        cur = dummy = ListNode(0, list1)
        for _ in range(a):
            cur = cur.next
        start = cur
        for _ in range(b - a + 1):
            cur.next = cur.next.next
        end = cur.next
        t = list2
        while t.next:
            t = t.next
        t.next = end
        start.next = list2
        return dummy.next
# @lc code=end



#
# @lcpr case=start
# [10,1,13,6,9,5]\n3\n4\n[1000000,1000001,1000002]\n
# @lcpr case=end

# @lcpr case=start
# [0,1,2,3,4,5,6]\n2\n5\n[1000000,1000001,1000002,1000003,1000004]\n
# @lcpr case=end

#

