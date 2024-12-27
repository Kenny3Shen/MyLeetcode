#
# @lc app=leetcode.cn id=3159 lang=python3
# @lcpr version=30204
#
# [3159] 查询数组中元素的出现位置
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def occurrencesOfElement(
        self, nums: List[int], queries: List[int], x: int
    ) -> List[int]:
        pos = [i for i, num in enumerate(nums) if num == x]
        return [-1 if q > len(pos) else pos[q - 1] for q in queries]


# @lc code=end


#
# @lcpr case=start
# [1,3,1,7]\n[1,3,2,4]\n1\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3]\n[10]\n5\n
# @lcpr case=end

#
