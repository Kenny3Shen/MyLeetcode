#
# @lc app=leetcode.cn id=117 lang=python3
# @lcpr version=30204
#
# [117] 填充每个节点的下一个右侧节点指针 II
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
        q = deque([root])
        while q:
            n = len(q)
            pre = None
            for _ in range(n):
                node = q.popleft()
                node.next = pre
                pre = node
                if node.right:
                    q.append(node.right)
                if node.left:
                    q.append(node.left)
        return root
# @lc code=end



#
# @lcpr case=start
# [1,2,3,4,5,null,7]\n
# @lcpr case=end

# @lcpr case=start
# []\n
# @lcpr case=end

#

