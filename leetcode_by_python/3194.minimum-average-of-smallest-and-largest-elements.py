#
# @lc app=leetcode.cn id=3194 lang=python3
# @lcpr version=30204
#
# [3194] 最小元素和最大元素的最小平均值
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def minimumAverage(self, nums: List[int]) -> float:
        nums = sorted(nums)
        i = 0
        j = len(nums) - 1
        res = 1e9
        while i < j:
            res = min(res, (nums[i] + nums[j]) / 2)
            i += 1
            j -= 1
        return res
# @lc code=end



#
# @lcpr case=start
# [7,8,3,4,15,13,4,1]\n
# @lcpr case=end

# @lcpr case=start
# [1,9,8,3,10,5]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,7,8,9]\n
# @lcpr case=end

#

