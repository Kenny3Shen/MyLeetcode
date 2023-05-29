/*
 * @lc app=leetcode.cn id=1507 lang=cpp
 *
 * [1507] 转变日期格式
 *
 * https://leetcode-cn.com/problems/reformat-date/description/
 *
 * algorithms
 * Easy (59.33%)
 * Likes:    2
 * Dislikes: 0
 * Total Accepted:    3.8K
 * Total Submissions: 6.4K
 * Testcase Example:  '"20th Oct 2052"'
 *
 * 给你一个字符串 date ，它的格式为 Day Month Year ，其中：
 * 
 * 
 * Day 是集合 {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"} 中的一个元素。
 * Month 是集合 {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep",
 * "Oct", "Nov", "Dec"} 中的一个元素。
 * Year 的范围在 ​[1900, 2100] 之间。
 * 
 * 
 * 请你将字符串转变为 YYYY-MM-DD 的格式，其中：
 * 
 * 
 * YYYY 表示 4 位的年份。
 * MM 表示 2 位的月份。
 * DD 表示 2 位的天数。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：date = "20th Oct 2052"
 * 输出："2052-10-20"
 * 
 * 
 * 示例 2：
 * 
 * 输入：date = "6th Jun 1933"
 * 输出："1933-06-06"
 * 
 * 
 * 示例 3：
 * 
 * 输入：date = "26th May 1960"
 * 输出："1960-05-26"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定日期保证是合法的，所以不需要处理异常输入。
 * 
 * 
 */
#include <string>
#include <sstream>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reformatDate(string date)
    {
        stringstream s(date);
        string year, month, day;
        s >> day >> month >> year;
        day = isdigit(day[1]) ? day.substr(0, 2) : '0' + day.substr(0, 1);
        vector<string> dict{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        for (int i = 0; i < 12; i++)
            if (month == dict[i])
            {
                month = (i < 9) ? '0' + to_string(i + 1) : to_string(i + 1);
                break;
            }
        return year + '-' + month + '-' + day;
    }
};
// @lc code=end
