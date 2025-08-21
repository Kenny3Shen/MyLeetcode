#
# @lc app=leetcode.cn id=239 lang=python3
# @lcpr version=30204
#
# [239] 滑动窗口最大值
#


# @lcpr-template-start
from typing import List
from collections import deque
# @lcpr-template-end
# @lc code=start
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        dq = deque()
        res = []
        for i in range(len(nums)):
            while dq and dq[0] <= i - k:
                dq.popleft()

            while dq and nums[dq[-1]] <= nums[i]:
                dq.pop()
            dq.append(i)

            if i >= k - 1:
                res.append(nums[dq[0]])
        return res
# @lc code=end



#
# @lcpr case=start
# [1,3,-1,-3,5,3,6,7]\n3\n
# @lcpr case=end

# @lcpr case=start
# [1]\n1\n
# @lcpr case=end

#

