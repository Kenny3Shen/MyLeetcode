/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 *
 * https://leetcode-cn.com/problems/count-binary-substrings/description/
 *
 * algorithms
 * Easy (52.02%)
 * Likes:    230
 * Dislikes: 0
 * Total Accepted:    29.2K
 * Total Submissions: 47.9K
 * Testcase Example:  '"00110"'
 *
 * 给定一个字符串 s，计算具有相同数量0和1的非空(连续)子字符串的数量，并且这些子字符串中的所有0和所有1都是组合在一起的。
 * 
 * 重复出现的子串要计算它们出现的次数。
 * 
 * 示例 1 :
 * 
 * 
 * 输入: "00110011"
 * 输出: 6
 * 解释: 有6个子串具有相同数量的连续1和0：“0011”，“01”，“1100”，“10”，“0011” 和 “01”。
 * 
 * 请注意，一些重复出现的子串要计算它们出现的次数。
 * 
 * 另外，“00110011”不是有效的子串，因为所有的0（和1）没有组合在一起。
 * 
 * 
 * 示例 2 :
 * 
 * 
 * 输入: "10101"
 * 输出: 4
 * 解释: 有4个子串：“10”，“01”，“10”，“01”，它们具有相同数量的连续1和0。
 * 
 * 
 * 注意：
 * 
 * 
 * s.length 在1到50,000之间。
 * s 只包含“0”或“1”字符。
 * 
 * 
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int i = 0;
        int pre = 0;
        int ans = 0;
        while (i < s.size())
        {
            char c = s[i];
            int count = 0;
            while (i < s.size() && s[i] == c)
            {
                i++;
                count++;
            }
            ans += min(count, pre);
            pre = count;
        }
        return ans;
    }
};

//字符串计数：不进行挨个比较了，直接计算出每段的连续数字长度，进行比较
//只需统计相同的字符个数，遇到不同的，选择二者计数的最小值即可
//按照官方题解的例子：
//存在 counts 数组中，例如 s = 00111011，可以得到这样的 counts 数组：counts={2,3,1,2}。
//只需得知上一段连续相同的字符数，与这一段连续相同字符数的最小值：即分别为 2，1，1，相加即可。
// @lc code=end
