#
# @lc app=leetcode.cn id= 面试题 02.08 lang=python3
# @lcpr version=30204
#
# [ 面试题 02.08] 环路检测
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        slow = head
        fast = head

        # 此处如果用 while (fast != slow)，则在一开始时就违背了条件
        # 也可用 do while, 但以下代码更符合 repeat until ( 重复直到 ) 的思考习惯
        while True:
            # 指向空节点，说明无环。
            if not fast or not fast.next:
                return None

            # fast 和 slow 异速前进
            fast = fast.next.next
            slow = slow.next

            if fast == slow:
                break  # fast 和 slow 相遇

        # ptr 和 slow 同速前进，直至相遇在入口
        ptr = head
        while ptr != slow:
            ptr = ptr.next
            slow = slow.next

        return ptr # 返回入口节点

# @lc code=end



#
# @lcpr case=start
# [3,2,0,-4]\n1\n
# @lcpr case=end

# @lcpr case=start
# [1,2]\n0\n
# @lcpr case=end

# @lcpr case=start
# [1]\n-1\n
# @lcpr case=end

#

