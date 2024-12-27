/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 *
 * https://leetcode-cn.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (42.65%)
 * Likes:    152
 * Dislikes: 0
 * Total Accepted:    24.1K
 * Total Submissions: 56.5K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
 * 
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
 * 
 * 示例1:
 * 
 * 输入: pattern = "abba", str = "dog cat cat dog"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:pattern = "abba", str = "dog cat cat fish"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: pattern = "aaaa", str = "dog cat cat dog"
 * 输出: false
 * 
 * 示例 4:
 * 
 * 输入: pattern = "abba", str = "dog dog dog dog"
 * 输出: false
 * 
 * 说明:
 * 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
 * 
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;
class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        unordered_map<char, string> map;
        unordered_map<string, char> remap;
        stringstream ss(str);
        string s;
        for (char c : pattern)
        {
            if (!(ss >> s) || (map.count(c) == 1 && map[c] != s) || (remap.count(s) == 1 && remap[s] != c))
            //存在pattern没有映射    pattern->str存在 但 映射不正确   str->pattern存在 但 映射不正确
                return false;
            map[c] = s;
            remap[s] = c;
        }
        return (ss >> s) ? false : true; //存在str没有映射
    }
};
// @lc code=end
