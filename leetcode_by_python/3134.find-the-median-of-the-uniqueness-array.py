#
# @lc app=leetcode.cn id=3134 lang=python3
# @lcpr version=30204
#
# [3134] 找出唯一性数组的中位数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
from bisect import bisect_left
from collections import defaultdict


class Solution:
    def medianOfUniquenessArray(self, nums: List[int]) -> int:
        n = len(nums)
        k = (n * (n + 1) // 2 + 1) // 2

        def check(upper: int) -> bool:
            cnt = l = 0
            freq = defaultdict(int)
            for r, in_ in enumerate(nums):
                freq[in_] += 1  # 移入右端点
                while len(freq) > upper:  # 窗口内元素过多
                    out = nums[l]
                    freq[out] -= 1  # 移出左端点
                    if freq[out] == 0:
                        del freq[out]
                    l += 1
                cnt += r - l + 1  # 右端点固定为 r 时，有 r-l+1 个合法左端点
                if cnt >= k:
                    return True
            return False

        return bisect_left(range(len(set(nums))), True, 1, key=check)

# @lc code=end



#
# @lcpr case=start
# [1,2,3]\n
# @lcpr case=end

# @lcpr case=start
# [3,4,3,4,5]\n
# @lcpr case=end

# @lcpr case=start
# [4,3,5,4]\n
# @lcpr case=end

#

