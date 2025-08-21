#
# @lc app=leetcode.cn id=1609 lang=python3
# @lcpr version=30204
#
# [1609] 奇偶树
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        a = []
        q = deque([root])
        even = True
        while q:
            n = len(q)
            pre = -inf if even else inf
            for _ in range(n):
                node = q.popleft()
                if even:
                    if node.val <= pre or node.val % 2 == 0:
                        return False
                else:
                    if node.val >= pre or node.val % 2 == 1:
                        return False
                pre = node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            even = not even
        return True
# @lc code=end



#
# @lcpr case=start
# [1,10,4,3,null,7,9,12,8,6,null,null,2]\n
# @lcpr case=end

# @lcpr case=start
# [5,4,2,3,3,7]\n
# @lcpr case=end

# @lcpr case=start
# [5,9,1,3,5,7]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

# @lcpr case=start
# [11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17]\n
# @lcpr case=end

#

