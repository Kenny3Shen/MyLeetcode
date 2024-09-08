#
# @lc app=leetcode.cn id=977 lang=python3
# @lcpr version=30204
#
# [977] 有序数组的平方
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        i, j, pos = 0, n - 1, n - 1
        while i <= j:
            if abs(nums[i]) > abs(nums[j]):
                ans[pos] = nums[i] * nums[i]
                i += 1
            else:
                ans[pos] = nums[j] * nums[j]
                j -= 1
            pos -= 1
        return ans
# @lc code=end



#
# @lcpr case=start
# [-4,-1,0,3,10]\n
# @lcpr case=end

# @lcpr case=start
# [-7,-3,2,3,11]\n
# @lcpr case=end

#

