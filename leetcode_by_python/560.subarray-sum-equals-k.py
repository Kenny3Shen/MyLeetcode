#
# @lc app=leetcode.cn id=560 lang=python3
# @lcpr version=30204
#
# [560] 和为 K 的子数组
#


# @lcpr-template-start
from collections import defaultdict
# @lcpr-template-end
# @lc code=start
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        # prefix sum
        s = [0] * (len(nums) + 1)
        for i, num in enumerate(nums):
            s[i + 1] = s[i] + num
        
        res = 0
        cnt = defaultdict(int)
        for sum in s:
            res += cnt[sum - k]
            cnt[sum] += 1
        return res

# @lc code=end



#
# @lcpr case=start
# [1,1,1]\n2\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3]\n3\n
# @lcpr case=end

#

