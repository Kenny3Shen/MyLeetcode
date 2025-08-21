#
# @lc app=leetcode.cn id=1658 lang=python3
# @lcpr version=30204
#
# [1658] 将 x 减到 0 的最小操作数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        # 找到一个最长的子数组，使得子数组的和等于 sum(nums) - x
        n = len(nums)
        target = sum(nums) - x
        if target == 0:
            return n
        if target < 0:
            return -1
        ans = -1
        i = 0
        s = 0
        for j in range(n):
            s += nums[j]
            while s > target:
                s -= nums[i]
                i += 1
            if s == target:
                ans = max(ans, j - i + 1)
        return n - ans if ans != -1 else -1
# @lc code=end



#
# @lcpr case=start
# [1,1,4,2,3]\n5\n
# @lcpr case=end

# @lcpr case=start
# [5,6,7,8,9]\n4\n
# @lcpr case=end

# @lcpr case=start
# [3,2,20,1,1,3]\n10\n
# @lcpr case=end

#

