/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 *
 * https://leetcode-cn.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (68.17%)
 * Likes:    452
 * Dislikes: 0
 * Total Accepted:    44.3K
 * Total Submissions: 64.9K
 * Testcase Example:  '[2,2,3,2]'
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
 * 
 * 说明：
 * 
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 * 
 * 示例 1:
 * 
 * 输入: [2,2,3,2]
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: [0,1,0,1,0,1,99]
 * 输出: 99
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < 32; ++i)
        {
            int cnt = 0;
            for (auto x : nums)
            {
                cnt += (x >> i) & 1; //统计第 i 位有多少位 1
            }
            res |= (cnt % 3) << i;  //模 3 后就是只出现一次的数在第 i 位的值（0 or 1）
        }
        return res;
    }
};
//统计一下有多少个数这一位上是 1 ，然后模 3 取余数，结果就是这个单独的数这一位上的值了。
// @lc code=end
