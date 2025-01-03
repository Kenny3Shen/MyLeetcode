/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode.cn/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (44.81%)
 * Likes:    2157
 * Dislikes: 0
 * Total Accepted:    348.3K
 * Total Submissions: 777K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""
 * 。
 *
 *
 *
 * 注意：
 *
 *
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a", t = "a"
 * 输出："a"
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 和 t 由英文字母组成
 *
 *
 *
 * 进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> hs, ht;
        for (auto c : t)
            ht[c]++;
        string res;
        int cnt = 0;
        int i = 0, j = 0;
        while (j < s.size())
        {
            hs[s[j]]++; // j往右边扩张
            if (hs[s[j]] <= ht[s[j]])
                cnt++;
            while (hs[s[i]] > ht[s[i]])
            {
                hs[s[i]]--;
                i++;
            } // i往右边收缩
            if (cnt == t.size())
                if(res.empty() || (j - i + 1) < res.size())
                    res = s.substr(i, j - i + 1);
            j++;
        }
        return res;
    }
};
// @lc code=end
