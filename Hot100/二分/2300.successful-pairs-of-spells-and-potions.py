#
# @lc app=leetcode.cn id=2300 lang=python3
# @lcpr version=30204
#
# [2300] 咒语和药水的成功对数
#

from typing import List

# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def lower_bound(self, spell, potions, success):
        l, r = 0, len(potions)
        while l < r:
            mid = (l + r) // 2
            if spell * potions[mid] >= success:
                r = mid
            else:
                l = mid + 1
        return l

    def successfulPairs(
        self, spells: List[int], potions: List[int], success: int
    ) -> List[int]:
        potions.sort()

        for i, spell in enumerate(spells):
            # success 第一次应该出现的位置，即第一个大于等于 success
            spells[i] = len(potions) - self.lower_bound(spell, potions, success)
        return spells


# @lc code=end


#
# @lcpr case=start
# [5,1,3]\n[1,2,3,4,5]\n7\n
# @lcpr case=end

# @lcpr case=start
# [3,1,2]\n[8,5,8]\n16\n
# @lcpr case=end

#
