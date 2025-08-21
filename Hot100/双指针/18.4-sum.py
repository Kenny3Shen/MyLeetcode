#
# @lc app=leetcode.cn id=18 lang=python3
# @lcpr version=30204
#
# [18] 四数之和
#


# @lcpr-template-start
from typing import List
# @lcpr-template-end
# @lc code=start
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        ans = []
        for i in range(n - 3):
            a = nums[i]
            if i > 0 and nums[i - 1] == a:
                continue
            if a + nums[i + 1] + nums[i + 2] + nums[i + 3] > target:
                break
            if a + nums[-3] + nums[-2] + nums[-1] < target:
                continue
            for j in range(i + 1, n - 2):
                b = nums[j]
                if j > i + 1 and nums[j - 1] == b:
                    continue
                if a + b + nums[j + 1] + nums[j + 2] > target:
                    break
                if a + b + nums[-2] + nums[-1] < target:
                    continue    
                k, l = j + 1, n - 1
                while k < l:
                    c, d = nums[k], nums[l]
                    s = a + b + c + d
                    if s == target:
                        ans.append([a, b, c, d])
                        k += 1
                        while k < l and nums[k] == c:
                            k += 1
                        l -= 1
                        while k < l and nums[l] == d:
                            l -= 1
                    elif s < target:
                        k += 1
                    else:
                        l -= 1
        return ans
# @lc code=end



#
# @lcpr case=start
# [1,0,-1,0,-2,2]\n0\n
# @lcpr case=end

# @lcpr case=start
# [2,2,2,2,2]\n8\n
# @lcpr case=end

#

