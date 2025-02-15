/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (44.52%)
 * Likes:    493
 * Dislikes: 0
 * Total Accepted:    97.8K
 * Total Submissions: 219.5K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续
 * 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：s = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 如果你已经完成了 O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        //sliding window
        int sum = 0;
        int minLength = __INT32_MAX__;
        int start = 0;
        int subLength = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            while (sum >= s) //找到符合条件的子序列时需要不断缩减长度
            {
                subLength = (i - start + 1);   
                minLength = min(minLength, subLength);
                sum -= nums[start]; //变更sliding window的起始位置
                start++;
            }
        }
        return minLength == __INT32_MAX__? 0 : minLength;
    }
};
// @lc code=end
