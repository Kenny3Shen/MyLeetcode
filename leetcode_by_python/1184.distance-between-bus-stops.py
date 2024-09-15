#
# @lc app=leetcode.cn id=1184 lang=python3
# @lcpr version=30204
#
# [1184] 公交站间的距离
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        if start > destination:
            start, destination = destination, start
        return min(sum(distance[start:destination]), sum(distance[destination:]) + sum(distance[:start]))

# @lc code=end



#
# @lcpr case=start
# [1,2,3,4]\n0\n1\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,4]\n0\n2\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,4]\n0\n3\n
# @lcpr case=end

#

