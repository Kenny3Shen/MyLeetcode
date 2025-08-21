#
# @lc app=leetcode.cn id=2476 lang=python3
# @lcpr version=30204
#
# [2476] 二叉搜索树最近节点查询
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
    def closestNodes(self, root: Optional[TreeNode], queries: List[int]) -> List[List[int]]:
        a = []
        def dfs(node):
            if not node:
                return
            dfs(node.left)
            a.append(node.val)
            dfs(node.right)
        dfs(root)
        ans = []
        for i, q in enumerate(queries):
            # 第一个大于等于q的数
            j = bisect_left(a, q)
            mx = a[j] if j < len(a) else -1
            # j - 1是最后一个小于q的数
            if j == len(a) or a[j] != q:
                j -= 1
            mi = a[j] if j >= 0 else -1
            ans.append([mi, mx])
        return ans
            
# @lc code=end



#
# @lcpr case=start
# [6,2,13,1,4,9,15,null,null,null,null,null,null,14]\n[2,5,16]\n
# @lcpr case=end

# @lcpr case=start
# [4,null,9]\n[3]\n
# @lcpr case=end

#

