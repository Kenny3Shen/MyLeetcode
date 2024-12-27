#
# @lc app=leetcode.cn id= 面试题 02.01 lang=python3
# @lcpr version=30204
#
# [ 面试题 02.01] 移除重复节点
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeDuplicateNodes(self, head: ListNode) -> ListNode:
        if not head:
            return head
        hash_set = set()
        cur = head
        hash_set.add(cur.val)
        while cur.next:
            if cur.next.val in hash_set:
                cur.next = cur.next.next
            else:
                hash_set.add(cur.next.val)
                cur = cur.next
        return head
# @lc code=end



#
# @lcpr case=start
# [1, 2, 3, 3, 2, 1]\n
# @lcpr case=end

# @lcpr case=start
# [1, 1, 1, 1, 2]\n
# @lcpr case=end

#

