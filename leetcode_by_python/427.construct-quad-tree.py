#
# @lc app=leetcode.cn id=427 lang=python3
# @lcpr version=30204
#
# [427] 建立四叉树
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        """
        生成给定区域[(ltr, ltc), (rtr, rtc)]的子树
         @param ltr: 范围矩阵左上角行标
         @param ltc: 范围矩阵左上角列标
         @param rtr: 范围矩阵右下角行标
         @param rtc: 范围矩阵右下角列标
        """
        def construct_from_area(ltr: int, ltc: int, rbr: int, rbc: int) -> 'Node':
            area_cnts = (rbr - ltr + 1) * (rbc - ltc + 1)       # 计算区域单元格个数
            if area_cnts == 1:
                # 如果只有1个单元格，无法再划分区域，肯定是叶子节点
                # 叶子节点的值即为单元格的值
                return Node(grid[ltr][ltc], True)      
            mr = ltr + (rbr - ltr + 1) // 2     # 中间行的行号
            mc = ltc + (rbc - ltc + 1) // 2     # 中间列的列号
            # 将当前区域划分成四个子区域，递归生成子树
            # 将当前区域划分成四个子区域，递归生成子树
            top_left = construct_from_area(ltr, ltc, mr - 1, mc - 1)
            top_right = construct_from_area(ltr, mc, mr - 1, rbc)
            bottom_left = construct_from_area(mr, ltc, rbr, mc - 1)
            bottom_right = construct_from_area(mr, mc, rbr, rbc)
            if top_left.isLeaf and top_right.isLeaf and bottom_left.isLeaf and bottom_right.isLeaf and top_left.val == top_right.val and top_right.val == bottom_left.val and bottom_left.val == bottom_right.val:
                # 如果四个区域都是叶子节点，说明四个区域的值内部都相同
                # 如果四个区域的值都相同，那么整个区域的值也相同，整个区域就是一个叶子节点
                return Node(top_left.val, True)
            # 否则该区域不是叶子节点
            return Node(False, False, top_left, top_right, bottom_left, bottom_right) 
        
        n = len(grid)   # 矩阵尺寸
        # 构造四叉树
        return construct_from_area(0 , 0, n-1, n-1)
        
# @lc code=end



#
# @lcpr case=start
# [[0,1],[1,0]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]\n
# @lcpr case=end

#

