/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 *
 * https://leetcode-cn.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (46.28%)
 * Likes:    254
 * Dislikes: 0
 * Total Accepted:    94.5K
 * Total Submissions: 203.2K
 * Testcase Example:  '"leetcode"'
 *
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 * 
 * 
 * 
 * 示例：
 * 
 * s = "leetcode"
 * 返回 0
 * 
 * s = "loveleetcode"
 * 返回 2
 * 
 * 
 * 
 * 
 * 提示：你可以假定该字符串只包含小写字母。
 * 
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int firstUniqChar(string s)
    {
        if (s.empty())
            return -1;
        /* unordered_map<char, int> map;
        for (auto c : s)
            map[c]++;
        for (int i = 0; i < s.size(); i++)
            if (map[s[i]] == 1)
                return i; */

        for (auto c : s)
            if (s.find(c) == s.rfind(c))
                return s.find(c);
        return -1;
    }
};
// @lc code=end
