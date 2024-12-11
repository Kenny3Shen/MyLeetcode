#
# @lc app=leetcode.cn id=2931 lang=python3
# @lcpr version=30204
#
# [2931] 购买物品的最大开销
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
from typing import List
from heapq import heapify, heappop, heappush

class Solution:
    def maxSpending(self, values: List[List[int]]) -> int:
        # 初始化堆，堆中存储每个子列表的最后一个元素及其索引
        h = [(a[-1], i) for i, a in enumerate(values)]
        heapify(h)  # 将列表 h 转换为堆
        ans = 0  # 初始化答案
        
        # 遍历从 1 到 values 中所有元素的总数
        for d in range(1, len(values) * len(values[0]) + 1):
            v, i = heappop(h)  # 弹出堆中最小的元素
            ans += v * d  # 将该元素乘以 d 并加到答案中
            values[i].pop()  # 从对应的子列表中移除该元素
            if values[i]:  # 如果子列表不为空
                heappush(h, (values[i][-1], i))  # 将子列表的新的最后一个元素及其索引压入堆中
        
        return ans  # 返回最终答案 
# @lc code=end



#
# @lcpr case=start
# [[8,5,2],[6,4,1],[9,7,3]]\n
# @lcpr case=end

# @lcpr case=start
# [[10,8,6,4,2],[9,7,5,3,2]]\n
# @lcpr case=end

#

