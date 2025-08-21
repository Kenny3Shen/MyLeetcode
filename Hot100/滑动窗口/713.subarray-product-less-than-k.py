#
# @lc app=leetcode.cn id=713 lang=python3
# @lcpr version=30204
#
# [713] 乘积小于 K 的子数组
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        # i, j 
        # if prod [l, r] >= k, then prod [l+1, r] ... prod [r, r] >= k
        n = len(nums)
        ans = 0
        i = 0
        if k <= 1:
            return 0
        prod = 1
        for j in range(n):
            prod *= nums[j]
            while prod >= k:
                prod /= nums[i]
                i += 1 
            ans += j - i + 1
        return ans
# @lc code=end



#
# @lcpr case=start
# [10,5,2,6]\n100\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3]\n0\n
# @lcpr case=end

#

