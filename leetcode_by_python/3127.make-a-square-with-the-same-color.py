#
# @lc app=leetcode.cn id=3127 lang=python3
# @lcpr version=30204
#
# [3127] 构造相同颜色的正方形
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def canMakeSquare(self, grid: List[List[str]]) -> bool:
        def check(i: int, j: int) -> bool:
            cnt = defaultdict(int)
            cnt[grid[i][j]] += 1
            cnt[grid[i][j + 1]] += 1
            cnt[grid[i + 1][j]] += 1
            cnt[grid[i + 1][j + 1]] += 1
            return cnt['B'] != 2
        return check(0, 0) or check(0, 1) or check(1, 0) or check(1, 1)

# @lc code=end



#
# @lcpr case=start
# [["B","W","B"],["B","W","W"],["B","W","B"]]\n
# @lcpr case=end

# @lcpr case=start
# [["B","W","B"],["W","B","W"],["B","W","B"]]\n
# @lcpr case=end

# @lcpr case=start
# [["B","W","B"],["B","W","W"],["B","W","W"]]\n
# @lcpr case=end

#

