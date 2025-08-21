#
# @lc app=leetcode.cn id=875 lang=python3
# @lcpr version=30204
#
# [875] 爱吃香蕉的珂珂
#


# @lcpr-template-start
from lc import *
# 对于每堆香蕉，以速度 k 吃完需要的时间是 ⌈pile / k⌉ = (pile - 1 ) // k + 1 = (pile + k - 1) // k （向上取整）
# @lcpr-template-end
# @lc code=start
class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        n = len(piles)
        # 最小速度 1，最大速度 max(piles)
        # 尝试找到第一个可以在 h 小时内吃完的速度 ( time(k) <= h )
        left, right = 1, max(piles)
        while left < right:
            mid = (left + right) // 2
            if sum((p - 1) // mid + 1 for p in piles) <= h:
                right = mid
            else:
                left = mid + 1
        return left

# @lc code=end



#
# @lcpr case=start
# [3,6,7,11]\n8\n
# @lcpr case=end

# @lcpr case=start
# [30,11,23,4,20]\n5\n
# @lcpr case=end

# @lcpr case=start
# [30,11,23,4,20]\n6\n
# @lcpr case=end

#

