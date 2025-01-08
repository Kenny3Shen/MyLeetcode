#
# @lc app=leetcode.cn id=120 lang=python3
# @lcpr version=30204
#
# [120] 三角形最小路径和
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        for i in range(1, len(triangle)):
            for j in range(len(triangle[i])):
                if j == 0:
                    triangle[i][j] += triangle[i - 1][j]
                elif j == len(triangle[i]) - 1:
                    triangle[i][j] += triangle[i - 1][j - 1]
                else:
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j])
        return min(triangle[-1])

# @lc code=end


#
# @lcpr case=start
# [[2],[3,4],[6,5,7],[4,1,8,3]]\n
# @lcpr case=end

# @lcpr case=start
# [[-10]]\n
# @lcpr case=end

#
