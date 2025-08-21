#
# @lc app=leetcode.cn id=306 lang=python3
# @lcpr version=30204
#
# [306] 累加数
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
# 站在输入选择与不选择的角度
class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        n = len(num)
        path = []
        ans = False

        def dfs(i, start):
            if i == n:
                nonlocal ans
                if len(path) >= 3:
                    ans = True
                return
            if i < n - 1:
                dfs(i + 1, start)
            s = num[start : i + 1]
            if str(int(s)) != s:  # 如果出现01开头的，那么后续肯定还是0开头的直接返回
                return
            if len(path) >= 2:
                if path[-1] + path[-2] != int(s):
                    return  # 站在输入的角度1,2,3,如果4不等于2+3，说明以1,2,3,开头的后续方案肯定不满足累加数直接返回
            path.append(int(s))
            dfs(i + 1, i + 1)
            path.pop()

        dfs(0, 0)
        return ans


# @lc code=end


#
# @lcpr case=start
# "112358"\n
# @lcpr case=end

# @lcpr case=start
# "199100199"\n
# @lcpr case=end

#
