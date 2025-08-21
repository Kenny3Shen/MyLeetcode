#
# @lc app=leetcode.cn id=17 lang=python3
# @lcpr version=30204
#
# [17] 电话号码的字母组合
#


# @lcpr-template-start
from lc import *

# @lcpr-template-end
# @lc code=start
mapping = {
    "2": "abc",
    "3": "def",
    "4": "ghi",
    "5": "jkl",
    "6": "mno",
    "7": "pqrs",
    "8": "tuv",
    "9": "wxyz",
}


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        n = len(digits)
        if n == 0:
            return []
        ans = []
        path = []

        def dfs(i):
            if i == n:
                ans.append("".join(path))
                return 
            for c in mapping[digits[i]]:
                path.append(c)
                dfs(i + 1)
                path.pop()

        dfs(0)
        return ans


# @lc code=end


#
# @lcpr case=start
# "23"\n
# @lcpr case=end

# @lcpr case=start
# ""\n
# @lcpr case=end

# @lcpr case=start
# "2"\n
# @lcpr case=end

#
