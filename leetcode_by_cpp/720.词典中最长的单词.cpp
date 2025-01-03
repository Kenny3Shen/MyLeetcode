/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 *
 * https://leetcode-cn.com/problems/longest-word-in-dictionary/description/
 *
 * algorithms
 * Easy (48.01%)
 * Likes:    125
 * Dislikes: 0
 * Total Accepted:    13.9K
 * Total Submissions: 29K
 * Testcase Example:  '["w","wo","wor","worl","world"]'
 *
 * 
 * 给出一个字符串数组words组成的一本英语词典。从中找出最长的一个单词，该单词是由words词典中其他单词逐步添加一个字母组成。若其中有多个可行的答案，则返回答案中字典序最小的单词。
 * 
 * 若无答案，则返回空字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * words = ["w","wo","wor","worl", "world"]
 * 输出："world"
 * 解释： 
 * 单词"world"可由"w", "wo", "wor", 和 "worl"添加一个字母组成。
 * 
 * 
 * 示例 2：
 * 
 * 输入：
 * words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
 * 输出："apple"
 * 解释：
 * "apply"和"apple"都能由词典中的单词组成。但是"apple"的字典序小于"apply"。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 所有输入的字符串都只包含小写字母。
 * words数组长度范围为[1,1000]。
 * words[i]的长度范围为[1,30]。
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    unordered_set<string> uset;
    bool canFind(string s)
    {
        if (s.empty())
            return true;
        if (uset.count(s))
            return canFind(s.substr(0, s.size() - 1));
        else
            return false;
    }
    string longestWord(vector<string> &words)
    {
        string res = "";
        sort(words.begin(), words.end());
        for (string &s : words)
        {
            if (s.size() == 1 || uset.count(s.substr(0, s.size() - 1)))
            {
                res = s.length() > res.length() ? s : res;
                uset.insert(s);
            }
        }
        return res;
        /* for (auto &w : words)
            uset.insert(w);
        sort(words.begin(), words.end(), [&words](string &a, string &b) {
            return a.size() > b.size();
        });
        vector<string> t;
        for (const string &s : words)
        {
            if (!t.empty() && s.size() < t.back().size())
                break;
            if (canFind(s.substr(0,s.size() - 1)))
                t.push_back(s);
        }
        sort(t.begin(), t.end());
        return t.empty() ? "" : t[0]; */
    }
};
// @lc code=end
