/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 *
 * https://leetcode-cn.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (35.27%)
 * Likes:    155
 * Dislikes: 0
 * Total Accepted:    32.6K
 * Total Submissions: 92.3K
 * Testcase Example:  '[3,2,1]'
 *
 * 给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [3, 2, 1]
 * 
 * 输出: 1
 * 
 * 解释: 第三大的数是 1.
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1, 2]
 * 
 * 输出: 2
 * 
 * 解释: 第三大的数不存在, 所以返回最大的数 2 .
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: [2, 2, 3, 1]
 * 
 * 输出: 1
 * 
 * 解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
 * 存在两个值为2的数，它们都排第二。
 * 
 * 
 */
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        long firstMax = LONG_MIN;
        long thirdMax = LONG_MIN;
        long secondMax = LONG_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > firstMax)
            {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = nums[i];
            }
            else if (nums[i] > secondMax && nums[i] < firstMax)
            {
                thirdMax = secondMax;
                secondMax = nums[i];
            }
            else if (nums[i] > thirdMax && nums[i] < secondMax)
                thirdMax = nums[i];
        }
        return thirdMax == LONG_MIN ? firstMax : thirdMax; 
        //当 third == INT_MAX时会返回错误答案，使用LONG_MAX
    }
};
// @lc code=end
