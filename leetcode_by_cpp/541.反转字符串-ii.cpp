/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 *
 * https://leetcode-cn.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (55.63%)
 * Likes:    96
 * Dislikes: 0
 * Total Accepted:    22.4K
 * Total Submissions: 40.2K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。
 * 
 * 
 * 如果剩余字符少于 k 个，则将剩余字符全部反转。
 * 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 * 
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: s = "abcdefg", k = 2
 * 输出: "bacdfeg"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 该字符串只包含小写英文字母。
 * 给定字符串的长度和 k 在 [1, 10000] 范围内。
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
    string reverseStr(string s, int k)
    {
        //以2k作为递进单位
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            //交换前k个字符
            if (i + k < s.size())
                reverse(s.begin() + i, s.begin() + i + k); //i+k不越界
            else
                reverse(s.begin() + i, s.end()); //i+k越界
        }
        return s;
    }
};
// @lc code=end
