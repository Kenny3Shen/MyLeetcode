#
# @lc app=leetcode.cn id=22 lang=python3
# @lcpr version=30204
#
# [22] 括号生成
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def backtrack(s, left, right, n, res):
            if len(s) == 2 * n:
                res.append(s)
                return
            if left < n:
                backtrack(s + '(', left + 1, right, n, res)
            if right < left:
                backtrack(s + ')', left, right + 1, n, res)
        backtrack('', 0, 0, n, res)
        return res
# @lc code=end



#
# @lcpr case=start
# 3\n
# @lcpr case=end

# @lcpr case=start
# 1\n
# @lcpr case=end

#

