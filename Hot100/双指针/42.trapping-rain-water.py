#
# @lc app=leetcode.cn id=42 lang=python3
# @lcpr version=30204
#
# [42] 接雨水
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def trap(self, height: List[int]) -> int:
        # n = len(height)
        # pre = [0] * n
        # suf = [0] * n
        # pre[0] = height[0]
        # for i in range(1, n):
        #     pre[i] = max(height[i], pre[i - 1])

        # suf[-1] = height[-1]
        # for i in range(n - 2, -1, -1):
        #     suf[i] = max(height[i], suf[i + 1])

        # ans = 0
        # for i in range(n):
        #     ans += min(pre[i], suf[i]) - height[i]
        # return ans
        n = len(height)
        ans = 0
        l, r = 0, n - 1
        pre, suf = 0, 0
        while l < r:
            pre = max(pre, height[l])
            suf = max(suf, height[r])
            if pre < suf:
                ans += pre - height[l]
                l += 1
            else:
                ans += suf - height[r]
                r -= 1
        return ans
            
# @lc code=end



#
# @lcpr case=start
# [0,1,0,2,1,0,1,3,2,1,2,1]\n
# @lcpr case=end

# @lcpr case=start
# [4,2,0,3,2,5]\n
# @lcpr case=end

#

