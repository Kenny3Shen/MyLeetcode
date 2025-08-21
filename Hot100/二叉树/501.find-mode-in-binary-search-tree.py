#
# @lc app=leetcode.cn id=501 lang=python3
# @lcpr version=30204
#
# [501] 二叉搜索树中的众数
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
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        pre = None
        cnt = 0
        max_cnt = 0
        def inorder(node):
            nonlocal pre, cnt, max_cnt
            if not node:
                return
            inorder(node.left)
            if pre == node.val:
                cnt += 1
            else:
                cnt = 1
                pre = node.val
            if cnt == max_cnt:
                ans.append(node.val)
            elif cnt > max_cnt:
                ans.clear()
                ans.append(node.val)
                max_cnt = cnt
            inorder(node.right)
        inorder(root)
        return ans
        # cnt = Counter()
        # def dfs(node):
        #     if not node:
        #         return
        #     cnt[node.val] += 1
        #     dfs(node.left)
        #     dfs(node.right)
        # dfs(root)
        # max_cnt = max(cnt.values(), default=0)
        # return [k for k, v in cnt.items() if v == max_cnt]
# @lc code=end



#
# @lcpr case=start
# [1,null,2,2]\n
# @lcpr case=end

# @lcpr case=start
# [0]\n
# @lcpr case=end

#

