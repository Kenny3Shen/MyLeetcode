#
# @lc app=leetcode.cn id=2583 lang=python3
# @lcpr version=30204
#
# [2583] 二叉树中的第 K 大层和
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
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        ans = []
        q = deque([root])
        depth = 0
        while q:
            s = 0
            n = len(q)
            for _ in range(n):
                node = q.popleft()
                s += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            ans.append(s)
            depth += 1
        ans.sort(reverse=True)

        return ans[k - 1] if k <= depth else -1
# @lc code=end



#
# @lcpr case=start
# [5,8,9,2,1,3,7,4,6]\n2\n
# @lcpr case=end

# @lcpr case=start
# [1,2,null,3]\n1\n
# @lcpr case=end

#

