/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 *
 * https://leetcode-cn.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (49.94%)
 * Likes:    238
 * Dislikes: 0
 * Total Accepted:    65K
 * Total Submissions: 126.1K
 * Testcase Example:  '"0"\n"0"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * num1 和num2 的长度都小于 5100
 * num1 和num2 都只包含数字 0-9
 * num1 和num2 都不包含任何前导零
 * 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式
 * 
 * 
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        /* int length = max(num1.size(), num2.size());
        if (num1.size() < num2.size())
            while (num1.size() != length)
                num1.insert(0,1,'0');
        else
            while (num2.size() != length)
                num2.insert(0,1,'0');
        reverse(num1.begin(), num1.end()),reverse(num2.begin(), num2.end());
        string ans;
        int carry = 0;
        for (int i = 0; i < length; i++)
        {
            int temp = (num1[i] - '0') + (num2[i] - '0') + carry;
            if (temp < 10)
            {
                ans += temp + '0';
                carry = 0;
            }
            else
            {
                ans += (temp % 10) + '0';
                carry = 1;
            }
        }
        if (carry)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans; */

        string res;
        int n = num1.size(), m = num2.size(), sum = 0;
        n < m ? num1.insert(0, m - n, '0') : num2.insert(0, n - m, '0'); //补0，如1314 + 520 补0后成 1314 + 0520
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            sum = (num1[i] - '0') + (num2[i] - '0') + sum / 10; //从高位开始遍历，相当于10进制相加
            res += (sum % 10) + '0';
        }
        if (sum / 10 == 1)
            res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
