#
# @lc app=leetcode.cn id=2212 lang=python3
# @lcpr version=30204
#
# [2212] 射箭比赛中的最大得分
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def maximumBobPoints(self, numArrows: int, aliceArrows: List[int]) -> List[int]:
        n = len(aliceArrows)
        ans = None
        max_score = 0
        def dfs(i, remain_arrows, cur_score, bob):
            nonlocal ans, max_score
            if remain_arrows < 0:
                return
            if i == n or remain_arrows == 0: # 剪枝
                if remain_arrows > 0:
                    bob[0] += remain_arrows
                
                if cur_score > max_score:
                    max_score = cur_score
                    ans = bob.copy()
                return
            # no
            dfs(i + 1, remain_arrows, cur_score, bob.copy())
            # yes
            t = aliceArrows[i] + 1
            bob[i] = t
            dfs(i + 1, remain_arrows - t, cur_score + i, bob.copy())
            bob[i] = 0
        dfs(0, numArrows, 0, [0]*n)
        return ans  
# @lc code=end



#
# @lcpr case=start
# 9\n[1,1,0,1,0,0,2,1,0,1,2,0]\n
# @lcpr case=end

# @lcpr case=start
# 3\n[0,0,1,0,0,0,0,0,0,0,0,2]\n
# @lcpr case=end

#

