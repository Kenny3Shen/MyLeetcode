#
# @lc app=leetcode.cn id=2487 lang=python3
# @lcpr version=30204
#
# [2487] 从链表中移除节点
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
        pre = None
        cur = head
        while cur:
            nxt = cur.next
            cur.next = pre
            pre = cur
            cur = nxt
        return pre
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # st = []
        # cur = head
        # while cur:
        #     while st and st[-1].val < cur.val:
        #         st.pop()
        #     st.append(cur)
        #     cur = cur.next
        # cur = dummy = ListNode(0, None)
        # for node in st:
        #     cur.next = node
        #     cur = cur.next
        # cur.next = None
        # return dummy.next
        cur = head = self.reverse(head)
        while cur.next:
            if cur.val > cur.next.val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return self.reverse(head)
# @lc code=end



#
# @lcpr case=start
# [5,2,13,3,8]\n
# @lcpr case=end

# @lcpr case=start
# [1,1,1,1]\n
# @lcpr case=end

#

