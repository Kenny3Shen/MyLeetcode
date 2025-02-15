/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 *
 * https://leetcode-cn.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (55.21%)
 * Likes:    246
 * Dislikes: 0
 * Total Accepted:    63.7K
 * Total Submissions: 115.3K
 * Testcase Example:  '"abccccdd"'
 *
 * 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
 * 
 * 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
 * 
 * 注意:
 * 假设字符串的长度不会超过 1010。
 * 
 * 示例 1: 
 * 
 * 
 * 输入:
 * "abccccdd"
 * 
 * 输出:
 * 7
 * 
 * 解释:
 * 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 * 
 * 
 */
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> map;
        for (auto const &c : s)
            map[c]++;

        int res = 0;
        for (auto const &m : map)
        {
            if ((res & 1) && (m.second & 1))
                res += m.second - 1; //res & 1表示选过一次奇数,则不能继续选择奇数次，因为奇数的一定在正中间
            else
                res += m.second;
        }
        return res;
    }
};
// @lc code=end
