#
# @lc app=leetcode.cn id=31 lang=python3
# @lcpr version=30204
#
# [31] 下一个排列
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        i = n - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
        if i >= 0:
            j = n - 1
            while j >=0 and nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]
        # reverse the suffix
        # nums[i + 1:] = nums[i + 1:][::-1]
        left, right = i + 1, n - 1
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1
        return nums
# @lc code=end



#
# @lcpr case=start
# [1,2,3]\n
# @lcpr case=end

# @lcpr case=start
# [3,2,1]\n
# @lcpr case=end

# @lcpr case=start
# [1,1,5]\n
# @lcpr case=end

#

