#
# @lc app=leetcode.cn id=16 lang=python3
# @lcpr version=30204
#
# [16] 最接近的三数之和
#


# @lcpr-template-start

from math import inf
# @lcpr-template-end
# @lc code=start
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        min_diff = inf
        ans = inf
        for i in range(n - 2):
            x = nums[i]
            
            s = x + nums[i + 1] + nums[i + 2]
            if s > target:
                if s - target < min_diff:
                    min_diff = s - target
                    ans = s
                break
            
            s = x + nums[-1] + nums[-2]
            if s < target:
                if target - s < min_diff:
                    min_diff = target - s
                    ans = s
                continue

            j, k = i + 1, n - 1
            while j < k:
                s = x + nums[j] + nums[k]
                if s == target:
                    return s
                elif s < target:
                    if target - s < min_diff:
                        min_diff = target - s
                        ans = s
                    j += 1
                else:
                    if s - target < min_diff:
                        min_diff = s - target
                        ans = s
                    k -= 1
        return ans
# @lc code=end



#
# @lcpr case=start
# [-1,2,1,-4]\n1\n
# @lcpr case=end

# @lcpr case=start
# [0,0,0]\n1\n
# @lcpr case=end

#

