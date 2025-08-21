#
# @lc app=leetcode.cn id=2962 lang=python3
# @lcpr version=30204
#
# [2962] 统计最大元素出现至少 K 次的子数组
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        mx = max(nums)
        n = len(nums)
        i = 0
        ans = 0
        cnt = 0
        for j in range(n):
            if nums[j] == mx:
                cnt += 1
            while cnt >= k:
                # 从 [i, j] 到 [i, n-1] 的子数组都满足条件
                # 有 n - 1 + j + 1 个子数组
                ans += n - j
                if nums[i] == mx:
                    cnt -= 1
                i += 1

        return ans
# @lc code=end



#
# @lcpr case=start
# [1,3,2,3,3]\n2\n
# @lcpr case=end

# @lcpr case=start
# [1,4,2,1]\n3\n
# @lcpr case=end

#

