/*
 * @lc app=leetcode.cn id=521 lang=cpp
 *
 * [521] 最长特殊序列 Ⅰ
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        if (a == b)
            return -1;
        return a.length() > b.length() ? a.length() : b.length();
    }
};
// @lc code=end
