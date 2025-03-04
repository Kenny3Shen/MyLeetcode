#
# @lc app=leetcode.cn id=128 lang=python3
# @lcpr version=30204
#
# [128] 最长连续序列
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        ans = 0
        s = set(nums)
        for x in s:
            if x - 1 in s:
                continue
            y = x + 1
            while y in s:
                y += 1
            ans = max(ans, y - x)
        return ans
# @lc code=end



#
# @lcpr case=start
# [100,4,200,1,3,2]\n
# @lcpr case=end

# @lcpr case=start
# [0,3,7,2,5,8,4,6,0,1]\n
# @lcpr case=end

# @lcpr case=start
# [1,0,1,2]\n
# @lcpr case=end

#

