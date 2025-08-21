#
# @lc app=leetcode.cn id=1239 lang=python3
# @lcpr version=30204
#
# [1239] 串联字符串的最大长度
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        cnt = Counter()
        ans = 0
        n = len(arr)
        def dfs(i, s):
            nonlocal ans, cnt
            for k, v in cnt.items():
                if v > 1:
                    return
            if i == n:
                ans = max(ans, len(s))
                return
            dfs(i + 1, s)

            # choose arr[i]
            for c in arr[i]:
                cnt[c] += 1
            dfs(i + 1, s + arr[i])
            for c in arr[i]:
                cnt[c] -= 1

        dfs(0, "")
        return ans
# @lc code=end



#
# @lcpr case=start
# ["un","iq","ue"]\n
# @lcpr case=end

# @lcpr case=start
# ["cha","r","act","ers"]\n
# @lcpr case=end

# @lcpr case=start
# ["abcdefghijklmnopqrstuvwxyz"]\n
# @lcpr case=end

#

