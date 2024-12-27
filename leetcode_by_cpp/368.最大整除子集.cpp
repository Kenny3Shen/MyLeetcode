/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 *
 * https://leetcode-cn.com/problems/largest-divisible-subset/description/
 *
 * algorithms
 * Medium (40.27%)
 * Likes:    303
 * Dislikes: 0
 * Total Accepted:    28.5K
 * Total Submissions: 65.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer ，子集中每一元素对 (answer[i],
 * answer[j]) 都应当满足：
 * 
 * answer[i] % answer[j] == 0 ，或
 * answer[j] % answer[i] == 0
 * 
 * 
 * 如果存在多个有效解子集，返回其中任何一个均可。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[1,2]
 * 解释：[1,3] 也会被视为正确答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,4,8]
 * 输出：[1,2,4,8]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * nums 中的所有整数 互不相同
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 0);
        vector<int> temp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            int len = 1, pre = i;
            for(int j = 0; j < i; j++)
            {
                if(nums[i] % nums[j] == 0)
                {
                    if(dp[j] + 1 > len)
                    {
                        len = dp[j] + 1;
                        pre = j;
                    }
                }
            }
            // 记录「最终长度」&「从何转移而来」
            dp[i] = len;
            temp[i] = pre;
        }
        int max = 0, maxIndex = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(dp[i] > max)
            {
                maxIndex = i;
                max = dp[i];
            }
        }
        vector<int> res;
        while(res.size() != max)
        {
            res.push_back(nums[maxIndex]);
            maxIndex = temp[maxIndex];
        }
        return res;
    }
};
// @lc code=end
