#
# @lc app=leetcode.cn id=3046 lang=python3
# @lcpr version=30204
#
# [3046] 分割数组
#


# @lcpr-template-start
from typing import List
# @lcpr-template-end
# @lc code=start

class Solution:
    def isPossibleToSplit(self, nums: List[int]) -> bool:
        count = {}
        for num in nums:
            count[num] = count.get(num, 0) + 1
            if count[num] > 2:
                return False
        return True

# @lc code=end



#
# @lcpr case=start
# [1,1,2,2,3,4]\n
# @lcpr case=end

# @lcpr case=start
# [1,1,1,1]\n
# @lcpr case=end

#

