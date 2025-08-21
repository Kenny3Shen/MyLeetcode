#
# @lc app=leetcode.cn id=2698 lang=python3
# @lcpr version=30204
#
# [2698] 求一个整数的惩罚数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
# 预计算1到1000的惩罚数
# 预计算1到1000的惩罚数
pre = [0] * 1001

# 判断一个数是否为惩罚数
def is_punishment_number(i: int) -> bool:
    s = str(i * i)
    n = len(s)
    
    # 回溯函数：选择在每个位置后是否放置分隔符
    def dfs(idx: int, curr_sum: int, curr_num: int) -> bool:
        # 已处理完所有数字
        if idx == n:
            return (curr_sum + curr_num) == i
        
        # 当前数字
        digit = int(s[idx])
        
        # 选择1: 不放置分隔符，继续扩展当前数字
        # curr_num * 10 + digit 表示将当前位拼接到当前数字后
        if dfs(idx + 1, curr_sum, curr_num * 10 + digit):
            return True
        
        # 选择2: 放置分隔符，将当前数字加入总和，新开一个数字
        if dfs(idx + 1, curr_sum + curr_num, digit):
            return True
        
        return False
    
    # 从第一个数字开始，初始总和为0，当前数字为0
    return dfs(0, 0, 0)

# 预计算所有惩罚数的前缀和
for i in range(1, 1001):
    pre[i] = pre[i-1]
    if is_punishment_number(i):
        pre[i] += i * i

class Solution:
    def punishmentNumber(self, n: int) -> int:
        return pre[n]
        
# @lc code=end



#
# @lcpr case=start
# 10\n
# @lcpr case=end

# @lcpr case=start
# 37\n
# @lcpr case=end

#

