#
# @lc app=leetcode.cn id=377 lang=python3
# @lcpr version=30204
#
# [377] 组合总和 Ⅳ
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
def combinationSum4(self, nums: List[int], target: int) -> int:
    f = [0] * (target + 1)  # 创建DP数组
    f[0] = 1  # 初始化：空集合的组合数为1
    
    # 外层循环：遍历所有可能的目标和（从1到target）
    for i in range(1, target + 1):
        # 内层循环：尝试将每个数加入组合中
        for num in nums:
            # 只有当目标和大于等于当前数字时，才能使用该数字
            if i >= num:
                # 状态转移：加上使用num后，剩余部分的组合数
                f[i] += f[i - num]
                
    return f[target]  # 返回组成target的总排列数
# @lc code=end



#
# @lcpr case=start
# [1,2,3]\n4\n
# @lcpr case=end

# @lcpr case=start
# [9]\n3\n
# @lcpr case=end

#

