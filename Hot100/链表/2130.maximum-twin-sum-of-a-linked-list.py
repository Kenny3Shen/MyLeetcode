#
# @lc app=leetcode.cn id=2130 lang=python3
# @lcpr version=30204
#
# [2130] 链表最大孪生和
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
        prev = None
        cur = head
        while cur:
            nxt = cur.next
            cur.next = prev
            prev = cur
            cur = nxt
        return prev
    def find_mid(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow
    def pairSum(self, head: Optional[ListNode]) -> int:
        mid = self.find_mid(head)
        head2 = self.reverse(mid)
        head1 = head
        ans = 0
        while head2:
            ans = max(ans, head1.val + head2.val)
            head1 = head1.next
            head2 = head2.next
        return ans
# @lc code=end



#
# @lcpr case=start
# [5,4,2,1]\n
# @lcpr case=end

# @lcpr case=start
# [4,2,2,3]\n
# @lcpr case=end

# @lcpr case=start
# [1,100000]\n
# @lcpr case=end

#

