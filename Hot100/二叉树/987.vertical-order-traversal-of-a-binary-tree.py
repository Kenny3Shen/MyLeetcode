#
# @lc app=leetcode.cn id=987 lang=python3
# @lcpr version=30204
#
# [987] 二叉树的垂序遍历
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
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        groups = defaultdict(list)
        def dfs(node, row, col):
            if not node:
                return
            groups[col].append((row, node.val))
            dfs(node.left, row + 1, col - 1)
            dfs(node.right, row + 1, col + 1)
        dfs(root, 0, 0)

        res = []
        for col in sorted(groups.keys()):
            # 先按 row 排序，再按 val 排序
            res.append([val for _, val in sorted(groups[col])])
        return res
# @lc code=end



#
# @lcpr case=start
# [3,9,20,null,null,15,7]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,4,5,6,7]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,4,6,5,7]\n
# @lcpr case=end

#

