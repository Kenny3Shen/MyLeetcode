#
# @lc app=leetcode.cn id=2786 lang=python3
# @lcpr version=30204
#
# [2786] 访问数组中的位置使分数最大
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def maxScore(self, nums: List[int], x: int) -> int:
        # 初始化：第一个元素的得分
        first = nums[0]
        
        # 初始状态: 根据第一个元素的奇偶性设置初始值
        if first % 2 == 0:  # 第一个元素是偶数
            even_max = first
            odd_max = -x + first  # 如果第一个转为奇数，需要损失x分
        else:  # 第一个元素是奇数
            odd_max = first
            even_max = -x + first  # 如果第一个转为偶数，需要损失x分
        
        # 动态规划过程
        for i in range(1, len(nums)):
            if nums[i] % 2 == 0:  # 当前元素是偶数
                # 更新偶数状态：从前一个偶数状态或奇数状态转移
                even_max = max(even_max + nums[i], odd_max + nums[i] - x)
                # 奇数状态保持不变，因为当前元素是偶数
            else:  # 当前元素是奇数
                # 更新奇数状态：从前一个奇数状态或偶数状态转移
                odd_max = max(odd_max + nums[i], even_max + nums[i] - x)
                # 偶数状态保持不变，因为当前元素是奇数
        
        # 返回奇数和偶数状态中的较大值作为最大得分
        return max(odd_max, even_max)
        
# @lc code=end



#
# @lcpr case=start
# [2,3,6,1,9,2]\n5\n
# @lcpr case=end

# @lcpr case=start
# [2,4,6,8]\n3\n
# @lcpr case=end

#

