#
# @lc app=leetcode.cn id=2717 lang=python3
# @lcpr version=30204
#
# [2717] 半有序排列
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def semiOrderedPermutation(self, nums: List[int]) -> int:
        n = len(nums)
        one_index = nums.index(1)
        n_index = nums.index(n)
        ans = one_index + (n - n_index - 1) - (one_index > n_index)
        return ans
# @lc code=end



#
# @lcpr case=start
# [2,1,4,3]\n
# @lcpr case=end

# @lcpr case=start
# [2,4,1,3]\n
# @lcpr case=end

# @lcpr case=start
# [1,3,4,2,5]\n
# @lcpr case=end

#

