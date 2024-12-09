#
# @lc app=leetcode.cn id=935 lang=python3
# @lcpr version=30204
#
# [935] 骑士拨号器
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
MOD = 1_000_000_007
NEXT = (4, 6), (6, 8), (7, 9), (4, 8), (0, 3, 9), (), (0, 1, 7), (2, 6), (1, 3), (2, 4)

@cache  # 缓存装饰器，避免重复计算 dfs 的结果（记忆化）
def dfs(i: int, j: int) -> int:
    if i == 0:
        return 1
    return sum(dfs(i - 1, k) for k in NEXT[j]) % MOD

class Solution:
    def knightDialer(self, n: int) -> int:
        if n == 1:
            return 10
        return (sum(dfs(n - 1, j) for j in range(10))) % MOD   
# @lc code=end



#
# @lcpr case=start
# 1\n
# @lcpr case=end

# @lcpr case=start
# 2\n
# @lcpr case=end

# @lcpr case=start
# 3131\n
# @lcpr case=end

#

