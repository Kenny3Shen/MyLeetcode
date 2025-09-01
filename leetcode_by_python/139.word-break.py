#
# @lc app=leetcode.cn id=139 lang=python3
# @lcpr version=30204
#
# [139] 单词拆分
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordDict = set(wordDict)
        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True
        for i in range(n):
            for j in range(i + 1):
                if dp[j] and s[j : i + 1] in wordDict:
                    dp[i + 1] = True
        return dp[-1]
# @lc code=end



#
# @lcpr case=start
# "leetcode"\n["leet", "code"]\n
# @lcpr case=end

# @lcpr case=start
# "applepenapple"\n["apple", "pen"]\n
# @lcpr case=end

# @lcpr case=start
# "catsandog"\n["cats", "dog", "sand", "and", "cat"]\n
# @lcpr case=end

#

