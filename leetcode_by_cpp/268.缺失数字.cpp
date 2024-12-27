/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 *
 * https://leetcode-cn.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (55.72%)
 * Likes:    299
 * Dislikes: 0
 * Total Accepted:    78.6K
 * Total Submissions: 139K
 * Testcase Example:  '[3,0,1]'
 *
 * 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [3,0,1]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [9,6,4,2,3,5,7,0,1]
 * 输出: 8
 * 
 * 
 * 
 * 
 * 说明:
 * 你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        /* int ans=nums.size();
        for(int i=0;i<nums.size();i++)
            ans = ans^i^nums[i];    //a^b^b = a
        return ans; */

        int sum = (1 + nums.size()) * nums.size() / 2;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum -= nums.at(i);
        }
        return sum;
    }
};
// @lc code=end
