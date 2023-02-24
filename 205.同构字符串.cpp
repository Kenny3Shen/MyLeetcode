/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 *
 * https://leetcode-cn.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (47.30%)
 * Likes:    227
 * Dislikes: 0
 * Total Accepted:    48.1K
 * Total Submissions: 101.7K
 * Testcase Example:  '"egg"\n"add"'
 *
 * 给定两个字符串 s 和 t，判断它们是否是同构的。
 * 
 * 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
 * 
 * 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
 * 
 * 示例 1:
 * 
 * 输入: s = "egg", t = "add"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "foo", t = "bar"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: s = "paper", t = "title"
 * 输出: true
 * 
 * 说明:
 * 你可以假设 s 和 t 具有相同的长度。
 * 
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        int len = s.length();
        for (int i = 0; i < len; ++i)
        {
            char x = s[i], y = t[i];
            if ((s2t.find(x) != s2t.end() && s2t[x] != y) || (t2s.find(y) != t2s.end() && t2s[y] != x))
            { //存在映射，但此次映射不匹配
                return false;
            }
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;

        /* for (int i = 0; i < s.size(); i++)
        { //返回字符第一次出现的位置，不对应则返回位置不同
            if (s.find(s[i]) != t.find(t[i]))
                return false;
        }
        return true; */
    }
};
// @lc code=end
