/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 *
 * https://leetcode-cn.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (38.20%)
 * Likes:    629
 * Dislikes: 0
 * Total Accepted:    82.4K
 * Total Submissions: 207K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
 * 
 * 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [10,2]
 * 输出："210"
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,30,34,5,9]
 * 输出："9534330"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1]
 * 输出："1"
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums = [10]
 * 输出："10"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> strNums(nums.size());
        transform(nums.begin(), nums.end(),strNums.begin(),[&](int x){
            return to_string(x);
        });
        sort(strNums.begin(), strNums.end(), [&](const string &a, const string &b) {
            return a + b > b + a;
        });
        string res = accumulate(strNums.begin(), strNums.end(), string());
        return res[0] == '0' ? "0" : res;
    }
};
// @lc code=end
