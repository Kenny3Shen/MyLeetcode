#
# @lc app=leetcode.cn id=15 lang=python3
# @lcpr version=30204
#
# [15] 三数之和
#


# @lcpr-template-start
from typing import List
# @lcpr-template-end
# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        n = len(nums)
        for i in range(n - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            x = nums[i]
            j, k = i + 1, n - 1
            if x + nums[i + 1] + nums[i + 1] > 0:
                break
            if x + nums[-1] + nums[-2] < 0:
                continue
            while j < k:    
                s = nums[j] + nums[k]
                if s + x == 0:
                    ans.append([x,nums[j],nums[k]])
                    j += 1
                    while j < k and nums[j] == nums[j - 1]:
                        j += 1
                    k -= 1
                    while j < k and nums[k] == nums[k + 1]:
                        k -=1
                elif s + x < 0:
                    j += 1
                else:
                    k -= 1
            
        return ans         
# @lc code=end



#
# @lcpr case=start
# [-1,0,1,2,-1,-4]\n
# @lcpr case=end

# @lcpr case=start
# [0,1,1]\n
# @lcpr case=end

# @lcpr case=start
# [0,0,0]\n
# @lcpr case=end

#

