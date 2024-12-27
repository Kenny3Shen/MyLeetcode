/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (52.22%)
 * Likes:    323
 * Dislikes: 0
 * Total Accepted:    68.9K
 * Total Submissions: 131.9K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */

// @lc code=start
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string addBinary(string a, string b)
    {
        while (a.size() < b.size())
        {
            a = '0' + a;
        }
        while (a.size() > b.size())
        {
            b = '0' + b;
        }
        //倒序是为了保证两个字符串能够按照正确顺序将对应位相加
        for (int i = a.size() - 1; i > 0; -- i)
        {
            a[i] = a[i] - '0' + b[i]; //注意到'0' - '0' = 0;'1'+ 1 ='2'
            if (a[i] >= '2') //注意是与字符比较，不是于ASCII码比较
            {
                a[i] = (a[i] - '0') % 2 + '0'; //注意到只可能等于2或等于3
                a[i - 1] = a[i - 1] + 1;       //进位后若等于2并没有及时处理
            }
        }
        //单独处理最高位，既第0位，若产生进位则需要在前面补'1'
        a[0] = a[0] - '0' + b[0];
        if (a[0] >= '2')
        {
            a[0] = (a[0] - '0') % 2 + '0';
            a = '1' + a;
        }
        return a;
    }
};
// @lc code=end

/* class Solution {
public:
    string addBinary(string a, string b) {
        string s;
		s.reserve(a.size() + b.size());
		int c = 0, i = a.size() - 1, j = b.size() - 1;
		while(i >= 0 || j >= 0 || c == 1)
		{
			c += i >= 0 ? a[i--] - '0' : 0;
			c += j >= 0 ? b[j--] - '0' : 0;
			s.push_back((c & 1) + '0');
			c >>= 1;
		}
		reverse(s.begin(), s.end());
		return s;
    }
}; */