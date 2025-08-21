#
# @lc app=leetcode.cn id=1302 lang=python3
# @lcpr version=30204
#
# [1302] 层数最深叶子节点的和
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
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        ans = 0
        q = deque([root])
        while q:
            ans = sum(node.val for node in q)
            n = len(q)
            for _ in range(n):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        return ans
# @lc code=end



#
# @lcpr case=start
# [1,2,3,4,5,null,6,7,null,null,null,null,8]\n
# @lcpr case=end

# @lcpr case=start
# [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]\n
# @lcpr case=end

#

