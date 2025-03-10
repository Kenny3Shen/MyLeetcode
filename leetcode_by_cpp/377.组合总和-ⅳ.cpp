/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 *
 * https://leetcode-cn.com/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (43.45%)
 * Likes:    273
 * Dislikes: 0
 * Total Accepted:    22.1K
 * Total Submissions: 50.7K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * 给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。
 * 
 * 示例:
 * 
 * 
 * nums = [1, 2, 3]
 * target = 4
 * 
 * 所有可能的组合为：
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 
 * 请注意，顺序不同的序列被视作不同的组合。
 * 
 * 因此输出为 7。
 * 
 * 
 * 进阶：
 * 如果给定的数组中含有负数会怎么样？
 * 问题会产生什么变化？
 * 我们需要在题目中添加什么限制来允许负数的出现？
 * 
 * 致谢：
 * 特别感谢 @pbrother 添加此问题并创建所有测试用例。
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<unsigned int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
            for (int j = 0; j < nums.size() && i >= nums[j]; j++)
                //if (dp[i] < INT_MAX - dp[i - nums[j]])
                    dp[i] += dp[i - nums[j]];

        //先容量后背包 --> 求排列
        //先背包后容量 --> 求组合
        return dp[target];
    }
};
// @lc code=end
