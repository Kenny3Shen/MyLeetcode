#
# @lc app=leetcode.cn id=530 lang=python3
# @lcpr version=30204
#
# [530] 二叉搜索树的最小绝对差
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
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        def dfs(node):
            if not node:
                return
            dfs(node.left)
            self.ans = min(self.ans, node.val - self.pre)
            self.pre = node.val
            dfs(node.right)

        self.pre = -inf
        self.ans = inf
        dfs(root)
        return self.ans

# @lc code=end



#
# @lcpr case=start
# [4,2,6,1,3]\n
# @lcpr case=end

# @lcpr case=start
# [1,0,48,null,null,12,49]\n
# @lcpr case=end

#

