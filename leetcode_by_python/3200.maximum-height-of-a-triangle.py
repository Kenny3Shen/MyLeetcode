#
# @lc app=leetcode.cn id=3200 lang=python3
# @lcpr version=30204
#
# [3200] 三角形的最大高度
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def maxHeightOfTriangle(self, red: int, blue: int) -> int:
        def get_max_height(x, y):
            start = 1
            while True:
                if start % 2 == 0:
                    x -= start
                else:
                    y -= start
                if x < 0 or y < 0:
                    break
                start += 1
            return start - 1
        return max(get_max_height(red, blue), get_max_height(blue, red))
# @lc code=end



#
# @lcpr case=start
# 2\n4\n
# @lcpr case=end

# @lcpr case=start
# 2\n1\n
# @lcpr case=end

# @lcpr case=start
# 1\n1\n
# @lcpr case=end

# @lcpr case=start
# 10\n1\n
# @lcpr case=end

#

