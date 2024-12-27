/*
 * @lc app=leetcode.cn id=1624 lang=cpp
 *
 * [1624] 两个相同字符之间的最长子字符串
 *
 * https://leetcode-cn.com/problems/largest-substring-between-two-equal-characters/description/
 *
 * algorithms
 * Easy (63.58%)
 * Likes:    1
 * Dislikes: 0
 * Total Accepted:    5K
 * Total Submissions: 7.8K
 * Testcase Example:  '"aa"'
 *
 * 给你一个字符串 s，请你返回 两个相同字符之间的最长子字符串的长度 ，计算长度时不含这两个字符。如果不存在这样的子字符串，返回 -1 。
 * 
 * 子字符串 是字符串中的一个连续字符序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "aa"
 * 输出：0
 * 解释：最优的子字符串是两个 'a' 之间的空子字符串。
 * 
 * 示例 2：
 * 
 * 输入：s = "abca"
 * 输出：2
 * 解释：最优的子字符串是 "bc" 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "cbzxy"
 * 输出：-1
 * 解释：s 中不存在出现出现两次的字符，所以返回 -1 。
 * 
 * 
 * 示例 4：
 * 
 * 输入：s = "cabbac"
 * 输出：4
 * 解释：最优的子字符串是 "abba" ，其他的非最优解包括 "bb" 和 "" 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 300
 * s 只含小写英文字母
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        int latestPlace[26] = {0};
        for(int i = 0; i < s.size(); i++)
        {
            latestPlace[s[i] - 'a'] = i; //记录最后出现位置
        }
        int maxLengthSubString = 0;
        bool haveSameChar = false;
        for(int i = 0; i < s.size(); i++)
        {
            if(latestPlace[s[i] - 'a'] > i) //存在相同的字符
            {
                maxLengthSubString = max(maxLengthSubString, latestPlace[s[i] - 'a'] - i - 1);
                haveSameChar = true;
            }
        }
        return haveSameChar ? maxLengthSubString : -1;
    }
};
// @lc code=end
