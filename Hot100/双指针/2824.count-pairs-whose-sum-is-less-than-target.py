#
# @lc app=leetcode.cn id=2824 lang=python3
# @lcpr version=30204
#
# [2824] 统计和小于目标的下标对数目
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        ans = 0
        l, r = 0, n - 1
        while l < r:
            x = nums[l] + nums[r]
            if x < target:
                ans += r - l
                l += 1
            else:
                r -= 1
        return ans
# @lc code=end



#
# @lcpr case=start
# [-1,1,2,3,1]\n2\n
# @lcpr case=end

# @lcpr case=start
# [-6,2,5,-2,-7,-1,3]\n-2\n
# @lcpr case=end

#

