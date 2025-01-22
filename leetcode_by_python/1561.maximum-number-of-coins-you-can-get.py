#
# @lc app=leetcode.cn id=1561 lang=python3
# @lcpr version=30204
#
# [1561] 你可以获得的最大硬币数目
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        piles.sort()
        n = len(piles)
        res = 0
        i = 0
        j = n - 2
        while i < j:
            res += piles[j]
            i += 1
            j -= 2
        return res
# @lc code=end



#
# @lcpr case=start
# [2,4,1,2,7,8]\n
# @lcpr case=end

# @lcpr case=start
# [2,4,5]\n
# @lcpr case=end

# @lcpr case=start
# [9,8,7,6,5,1,2,3,4]\n
# @lcpr case=end

#

