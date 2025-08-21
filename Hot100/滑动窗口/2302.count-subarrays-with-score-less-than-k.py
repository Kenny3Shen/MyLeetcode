#
# @lc app=leetcode.cn id=2302 lang=python3
# @lcpr version=30204
#
# [2302] 统计得分小于 K 的子数组数目
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        ans = 0
        n = len(nums)
        i = 0
        s = 0
        for j in range(n):
            s += nums[j]
            while s * (j - i + 1) >= k:
                s -= nums[i]
                i += 1
            # 如果 [i, j] 的 得分 < k
            # 则 [i, j], [i+1, j] ... [j, j] 的得分也一定 < k
            ans += j - i + 1
        return ans


# @lc code=end


#
# @lcpr case=start
# [2,1,4,3,5]\n10\n
# @lcpr case=end

# @lcpr case=start
# [1,1,1]\n5\n
# @lcpr case=end

#
