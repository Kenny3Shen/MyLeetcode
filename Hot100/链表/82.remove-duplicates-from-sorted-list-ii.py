#
# @lc app=leetcode.cn id=82 lang=python3
# @lcpr version=30204
#
# [82] 删除排序链表中的重复元素 II
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
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = cur = ListNode(next=head)
        while cur.next and cur.next.next:
            # 如果 cur.next 和 cur.next.next 的值相等
            # 那么就删除这些节点
            if cur.next.val == cur.next.next.val:
                x = cur.next.val
                # 删除所有值为 x 的节点
                # cur.next 是值为 x 的第一个节点
                while cur.next and cur.next.val == x:
                    cur.next = cur.next.next
            else:
                cur = cur.next
        return dummy.next
# @lc code=end



#
# @lcpr case=start
# [1,2,3,3,4,4,5]\n
# @lcpr case=end

# @lcpr case=start
# [1,1,1,2,3]\n
# @lcpr case=end

#

