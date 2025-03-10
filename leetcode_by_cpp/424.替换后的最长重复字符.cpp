/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 *
 * https://leetcode-cn.com/problems/longest-repeating-character-replacement/description/
 *
 * algorithms
 * Medium (49.46%)
 * Likes:    285
 * Dislikes: 0
 * Total Accepted:    23.8K
 * Total Submissions: 46.5K
 * Testcase Example:  '"ABAB"\n2'
 *
 * 给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k
 * 次。在执行上述操作后，找到包含重复字母的最长子串的长度。
 * 
 * 注意：字符串长度 和 k 不会超过 10^4。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ABAB", k = 2
 * 输出：4
 * 解释：用两个'A'替换为两个'B',反之亦然。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "AABABBA", k = 1
 * 输出：4
 * 解释：
 * 将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
 * 子串 "BBBB" 有最长重复字母, 答案为 4。
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int left = 0;
        int right = 0;
        int hash[26] = {0}; // this char appearance times in current window
        int curWindowMaxChar = 0;
        while (right < s.size())
        {
            hash[s[right] - 'A']++;
            curWindowMaxChar = max(curWindowMaxChar, hash[s[right] - 'A']);
            //find current window max char, then we need to replace the less char
            if (right - left + 1 > curWindowMaxChar + k) //slide window
            {
                hash[s[left] - 'A']--;
                left++;
                right++;
            }
            else //expand window
                right++;
        }
        return s.length() - left;
    }
};
// @lc code=end
