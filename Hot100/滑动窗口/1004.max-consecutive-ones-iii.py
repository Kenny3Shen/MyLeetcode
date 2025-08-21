#
# @lc app=leetcode.cn id=1004 lang=python3
# @lcpr version=30204
#
# [1004] 最大连续1的个数 III
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        ans = 0
        i = 0
        n = len(nums)
        for j in range(n):
            if nums[j] == 0:
                k -= 1
            while k < 0:
                if nums[i] == 0:
                    k += 1
                i += 1
            ans = max(ans, j - i + 1)
        return ans
# @lc code=end



#
# @lcpr case=start
# [1,1,1,0,0,0,1,1,1,1,0]\n2\n
# @lcpr case=end

# @lcpr case=start
# [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]\n3\n
# @lcpr case=end

#

