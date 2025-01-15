#
# @lc app=leetcode.cn id=3066 lang=python3
# @lcpr version=30204
#
# [3066] 超过阈值的最少操作数 II
#


# @lcpr-template-start
import heapq    
from typing import List
# @lcpr-template-end
# @lc code=start
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        heapq.heapify(nums)  # 直接对nums进行最小堆化
        res = 0
        while len(nums) >= 2:  # 确保堆中至少有2个元素
            if nums[0] >= k:
                break
            x, y = heapq.heappop(nums), heapq.heappop(nums)
            heapq.heappush(nums, x * 2 + y)
            # 上两条语句等价于下面这条语句，下面这条语句性能更好
            # heapq.heapreplace(nums, x * 2 + nums[0])
            res += 1
        return res
            
# @lc code=end



#
# @lcpr case=start
# [2,11,10,1,3]\n10\n
# @lcpr case=end

# @lcpr case=start
# [1,1,2,4,9]\n20\n
# @lcpr case=end

#

