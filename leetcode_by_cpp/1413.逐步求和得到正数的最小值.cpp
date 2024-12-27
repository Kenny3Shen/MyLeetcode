/*
 * @lc app=leetcode.cn id=1413 lang=cpp
 *
 * [1413] 逐步求和得到正数的最小值
 *
 * https://leetcode-cn.com/problems/minimum-value-to-get-positive-step-by-step-sum/description/
 *
 * algorithms
 * Easy (67.66%)
 * Likes:    13
 * Dislikes: 0
 * Total Accepted:    5.4K
 * Total Submissions: 8K
 * Testcase Example:  '[-3,2,-3,4,2]'
 *
 * 给你一个整数数组 nums 。你可以选定任意的 正数 startValue 作为初始值。
 * 
 * 你需要从左到右遍历 nums 数组，并将 startValue 依次累加上 nums 数组中的值。
 * 
 * 请你在确保累加和始终大于等于 1 的前提下，选出一个最小的 正数 作为 startValue 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-3,2,-3,4,2]
 * 输出：5
 * 解释：如果你选择 startValue = 4，在第三次累加时，和小于 1 。
 * ⁠               累加求和
 * startValue = 4 | startValue = 5 | nums
 * (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
 * (1 +2 ) = 3  | (2 +2 ) = 4    |   2
 * (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
 * (0 +4 ) = 4  | (1 +4 ) = 5    |   4
 * (4 +2 ) = 6  | (5 +2 ) = 7    |   2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2]
 * 输出：1
 * 解释：最小的 startValue 需要是正数。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,-2,-3]
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * -100 <= nums[i] <= 100
 * 
 * 
 */
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minStartValue(vector<int> &nums)
    {
        //找最小前缀和
        //vector<int> pSum(nums.size());
        //partial_sum(nums.begin(), nums.end(), pSum.begin()); //求部分和函数
        partial_sum(nums.begin(), nums.end(), nums.begin());
        int res = *min_element(nums.begin(), nums.end());
        return res > 0 ? 1 : 1 - res;

        /* int min_sum = 0;
        for (int i = 0, sum = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            min_sum = min(min_sum, sum);
        }
        return min_sum > 0 ? 1 : 1 - min_sum; */
    }
};
// @lc code=end
