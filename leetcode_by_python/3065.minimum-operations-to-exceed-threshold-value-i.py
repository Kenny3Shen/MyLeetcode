#
# @lc app=leetcode.cn id=3065 lang=python3
# @lcpr version=30204
#
# [3065] 超过阈值的最少操作数 I
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        count = 0
        for num in nums:
            count += 1 if num < k else 0
        return count
        
# @lc code=end



#
# @lcpr case=start
# [2,11,10,1,3]\n10\n
# @lcpr case=end

# @lcpr case=start
# [1,1,2,4,9]\n1\n
# @lcpr case=end

# @lcpr case=start
# [1,1,2,4,9]\n9\n
# @lcpr case=end

#

