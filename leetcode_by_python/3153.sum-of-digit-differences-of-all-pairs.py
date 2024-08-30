#
# @lc app=leetcode.cn id=3153 lang=python3
# @lcpr version=30204
#
# [3153] 所有数对中数位不同之和
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def sumDigitDifferences(self, nums: List[int]) -> int:
        ans = 0
        cnt = [[0] * 10 for _ in str(nums[0])]
        for k,x in enumerate(nums):
            i = 0
            while x:
                x, d = divmod(x, 10)
                ans += k - cnt[i][d]
                cnt[i][d] += 1
                i += 1
        return ans
# @lc code=end



#
# @lcpr case=start
# [13,23,12]\n
# @lcpr case=end

# @lcpr case=start
# [10,10,10,10]\n
# @lcpr case=end

#

