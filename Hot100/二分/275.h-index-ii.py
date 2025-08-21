#
# @lc app=leetcode.cn id=275 lang=python3
# @lcpr version=30204
#
# [275] H 指数 II
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    # hIndex = 有 h 篇论文，每篇论文至少被引用 h 次，而其余论文的引用次数不超过 h 次
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations) # 有 n 篇论文
        left, right = 0, n
        while left < right:
            mid = (left + right) // 2
            # 索引 mid 及其之后的每篇论文至少被引用了 n - mid 次
            # 有 n - mid 篇论文，每篇至少被引用了 n - mid 次
            # 尝试找到最小的 mid，使得 citations[mid] >= n - mid
            if citations[mid] >= n - mid:
                right = mid
            else:
                left = mid + 1
        return n - left
# @lc code=end



#
# @lcpr case=start
# [0,1,3,5,6]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,100]\n
# @lcpr case=end

#

