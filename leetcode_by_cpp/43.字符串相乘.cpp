/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (43.60%)
 * Likes:    441
 * Dislikes: 0
 * Total Accepted:    92.4K
 * Total Submissions: 210.1K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 示例 1:
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 说明：
 * 
 * 
 * num1 和 num2 的长度小于110。
 * num1 和 num2 只包含数字 0-9。
 * num1 和 num2 均不以零开头，除非是数字 0 本身。
 * 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string multiply(string a, string b)
    {
        if (a == "0" || b == "0")
            return "0";
        if (a == "1" || b == "1")
            return a == "1" ? b : a;

        string res;
        vector<int> noCarry(a.size() + b.size(), 0); //相乘后先不进位，保存相乘结果，m * n 最少有 m + n - 1位，最多有 m+n 位
        for (int i = a.size() - 1; i >= 0; i--)
        {
            for (int j = b.size() - 1; j >= 0; j--)
            {
                noCarry[i + j + 1] += (a[i] - '0') * (b[j] - '0'); //第 a[i] 位与第 b[j] 位相乘在第 i+j+1 位
            }
        }
        for (int i = noCarry.size() - 1; i > 0; i--)
        {
            noCarry[i - 1] += noCarry[i] / 10; //向高位进位
            res += noCarry[i] % 10 + '0';
        }
        if (noCarry[0])
            res += noCarry[0] + '0'; //判断最高位是否需要加入
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
