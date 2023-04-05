/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 *
 * https://leetcode-cn.com/problems/maximum-average-subarray-i/description/
 *
 * algorithms
 * Easy (39.79%)
 * Likes:    148
 * Dislikes: 0
 * Total Accepted:    37.7K
 * Total Submissions: 85.1K
 * Testcase Example:  '[1,12,-5,-6,50,3]\n4'
 *
 * 给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：[1,12,-5,-6,50,3], k = 4
 * 输出：12.75
 * 解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 k n 
 * 所给数据范围 [-10,000，10,000]。
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        int res = sum;
        for(int i = k; i < nums.size(); i++)
        {
            sum = sum + nums[i] - nums[i - k];
            res = max(sum, res);
        }
        return double(res) / k;
    }
};
// @lc code=end

