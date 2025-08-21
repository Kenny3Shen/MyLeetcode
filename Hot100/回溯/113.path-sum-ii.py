#
# @lc app=leetcode.cn id=113 lang=python3
# @lcpr version=30204
#
# [113] 路径总和 II
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
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        ans = []
        path = []
        def dfs(node, target):
            if not node:
                return
            path.append(node.val)
            if not node.left and not node.right and node.val == target:
                ans.append(path[:])
            dfs(node.left, target - node.val)
            dfs(node.right, target - node.val)
            path.pop()
        dfs(root, targetSum)
        return ans
# @lc code=end



#
# @lcpr case=start
# [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3]\n5\n
# @lcpr case=end

# @lcpr case=start
# [1,2]\n0\n
# @lcpr case=end

#

