#
# @lc app=leetcode.cn id=93 lang=python3
# @lcpr version=30204
#
# [93] 复原 IP 地址
#


# @lcpr-template-start
from lc import *


# @lcpr-template-end
# @lc code=start
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        # 选/不选
        ans = []
        path = []
        n = len(s)
        if n < 4 or n > 12:
            return []

        # i表示分隔符号.的位置
        # start 表示这段的开始位置
        def dfs(i, start):
            # 终止条件 1. 遍历结束 2. path长度为4
            if i == n:
                if len(path) == 4:
                    ans.append(".".join(path))
                return
            if len(path) == 4:
                return
            # 不选 （i=n-1 时一定要选）
            if i < n - 1:
                dfs(i + 1, start)
            # 选 判断选择条件
            t = s[start : i + 1]
            if (len(t) > 1 and t[0] == "0") or int(t) > 255:
                return
            path.append(t)
            dfs(i + 1, i + 1)  # 下一个子串从i+1开始
            path.pop()

        dfs(0, 0)
        return ans


# @lc code=end


#
# @lcpr case=start
# "25525511135"\n
# @lcpr case=end

# @lcpr case=start
# "0000"\n
# @lcpr case=end

# @lcpr case=start
# "101023"\n
# @lcpr case=end

#
