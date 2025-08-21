#
# @lc app=leetcode.cn id=301 lang=python3
# @lcpr version=30204
#
# [301] 删除无效的括号
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        ans = set()
        path = []
        left, right = 0, 0
        for c in s:
            if c == '(':
                left += 1
            elif c == ')':
                if left > 0:
                    left -= 1
                else:
                    right += 1
                
        def dfs(i, l, r, need_right):
            if i == len(s):
                if need_right == 0:
                    ans.add("".join(path))
                return
            if s[i] == '(':
                # l > 0表明后面有多余的左括号，可以不选
                if l > 0:
                    dfs(i + 1, l - 1, r, need_right)
                # 保留这个多余的左括号
                path.append('(')
                dfs(i + 1, l, r, need_right + 1)
                path.pop()
            elif s[i] == ')':
                # r > 0表明后面有多余的右括号，可以不选
                if r > 0:
                    dfs(i + 1, l, r - 1, need_right)
                # 保留这个多余的右括号, 在左侧有多余的左括号时
                if need_right > 0:
                    path.append(')')
                    dfs(i + 1, l, r, need_right - 1)
                    path.pop()
            else:
                path.append(s[i])
                dfs(i + 1, l, r, need_right)
                path.pop()
        dfs(0, left, right, 0)
        return list(ans)
            

# @lc code=end



#
# @lcpr case=start
# "()())()"\n
# @lcpr case=end

# @lcpr case=start
# "(a)())()"\n
# @lcpr case=end

# @lcpr case=start
# ")("\n
# @lcpr case=end

#

