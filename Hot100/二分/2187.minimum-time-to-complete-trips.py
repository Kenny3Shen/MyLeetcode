#
# @lc app=leetcode.cn id=2187 lang=python3
# @lcpr version=30204
#
# [2187] 完成旅途的最少时间
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        left = 1 
        # 即使只有最快的车 (t最小)在运行，也能保证完成所有旅途
        right = min(time) * totalTrips

        while left < right:
            mid = (left + right) // 2
            if sum(mid // t for t in time) >= totalTrips:
                right = mid
            else:
                left = mid + 1
        return left
# @lc code=end



#
# @lcpr case=start
# [1,2,3]\n5\n
# @lcpr case=end

# @lcpr case=start
# [2]\n1\n
# @lcpr case=end

#

