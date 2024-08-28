#
# @lc app=leetcode.cn id=3144 lang=python3
# @lcpr version=30204
#
# [3144] 分割字符频率相等的最少子字符串
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def minimumSubstringsInPartition(self, s: str) -> int:
        @cache  # 缓存装饰器，避免重复计算 dfs 的结果（记忆化）
        def dfs(i: int) -> int:
            if i < 0:
                return 0
            res = inf
            cnt = defaultdict(int)
            max_cnt = 0
            for j in range(i, -1, -1):
                cnt[s[j]] += 1
                max_cnt = max(max_cnt, cnt[s[j]])
                if i - j + 1 == len(cnt) * max_cnt:
                    res = min(res, dfs(j - 1) + 1)
            return res
        return dfs(len(s) - 1)
# @lc code=end



#
# @lcpr case=start
# "fabccddg"\n
# @lcpr case=end

# @lcpr case=start
# "abababaccddb"\n
# @lcpr case=end

#

