#
# @lc app=leetcode.cn id=513 lang=python3
# @lcpr version=30204
#
# [513] 找树左下角的值
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
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        # 优先进右节点
        # 最后一个被访问到的节点就是最左下角的节点
        q = deque([root])
        pre = None
        while q:
            node = q.popleft()
            pre = node
            if node.right:
                q.append(node.right)
            if node.left:
                q.append(node.left)
        return pre.val
# @lc code=end



#
# @lcpr case=start
# [2,1,3]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,4,null,5,6,null,null,7]\n
# @lcpr case=end

#

