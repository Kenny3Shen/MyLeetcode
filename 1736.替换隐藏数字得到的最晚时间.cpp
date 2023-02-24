/*
 * @lc app=leetcode.cn id=1736 lang=cpp
 *
 * [1736] 替换隐藏数字得到的最晚时间
 *
 * https://leetcode-cn.com/problems/latest-time-by-replacing-hidden-digits/description/
 *
 * algorithms
 * Easy (40.51%)
 * Likes:    44
 * Dislikes: 0
 * Total Accepted:    21.6K
 * Total Submissions: 48.8K
 * Testcase Example:  '"2?:?0"'
 *
 * 给你一个字符串 time ，格式为  hh:mm（小时：分钟），其中某几位数字被隐藏（用 ? 表示）。
 * 
 * 有效的时间为 00:00 到 23:59 之间的所有时间，包括 00:00 和 23:59 。
 * 
 * 替换 time 中隐藏的数字，返回你可以得到的最晚有效时间。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：time = "2?:?0"
 * 输出："23:50"
 * 解释：以数字 '2' 开头的最晚一小时是 23 ，以 '0' 结尾的最晚一分钟是 50 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：time = "0?:3?"
 * 输出："09:39"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：time = "1?:22"
 * 输出："19:22"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * time 的格式为 hh:mm
 * 题目数据保证你可以由输入的字符串生成有效的时间
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    string maximumTime(string time)
    {
        string res = time;
        if (time[0] == '?')
        {
            if (time[1] == '?')
                res[0] = '2';
            else if(time[1] >= '0' && time[1] <= '3')
                res[0] = '2';
            else   
                res[0] = '1';
        }
        if (time[1] == '?')
        {
            if (time[0] == '?' || time[0] == '2')
                res[1] = '3';
            else if (time[0] == '0' || time[0] == '1')
                res[1] = '9';
        }
        if (time[3] == '?')
            res[3] = '5';
        if (time[4] == '?')
            res[4] = '9';
        return res;
    }
};
// @lc code=end
