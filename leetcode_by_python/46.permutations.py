#
# @lc app=leetcode.cn id=46 lang=python3
# @lcpr version=30204
#
# [46] 全排列
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def backtrack(first=0):
            if first == n:
                res.append(nums[:])
            for i in range(first, n):
                nums[first], nums[i] = nums[i], nums[first]
                backtrack(first + 1)
                nums[first], nums[i] = nums[i], nums[first]
        n = len(nums)
        res = []
        backtrack()
        return res
# @lc code=end



#
# @lcpr case=start
# [1,2,3]\n
# @lcpr case=end

# @lcpr case=start
# [0,1]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

#

