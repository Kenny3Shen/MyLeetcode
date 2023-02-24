/*
 * @lc app=leetcode.cn id=1556 lang=cpp
 *
 * [1556] 千位分隔数
 *
 * https://leetcode-cn.com/problems/thousand-separator/description/
 *
 * algorithms
 * Easy (61.79%)
 * Likes:    0
 * Dislikes: 0
 * Total Accepted:    3.7K
 * Total Submissions: 6.1K
 * Testcase Example:  '987'
 *
 * 给你一个整数 n，请你每隔三位添加点（即 "." 符号）作为千位分隔符，并将结果以字符串格式返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 987
 * 输出："987"
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 1234
 * 输出："1.234"
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 123456789
 * 输出："123.456.789"
 * 
 * 
 * 示例 4：
 * 
 * 输入：n = 0
 * 输出："0"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n < 2^31
 * 
 * 
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    string thousandSeparator(int n)
    {
        string s = to_string(n), ans;
        int count = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            ans += s[i];
            count++;
            if (!count % 3 && i)
            {
                ans += '.';
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
        //return solve(to_string(n));
    }

    string solve(string s)
    {
        int n = s.length();
        if (n <= 3)
        {
            return s;
        }
        return solve(s.substr(0, n - 3)) + "." + s.substr(n - 3, 3);
    }
};
// @lc code=end
