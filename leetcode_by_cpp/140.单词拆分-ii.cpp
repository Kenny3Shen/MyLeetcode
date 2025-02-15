/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 *
 * https://leetcode-cn.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (38.68%)
 * Likes:    320
 * Dislikes: 0
 * Total Accepted:    29.5K
 * Total Submissions: 71K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典
 * wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。
 * 
 * 说明：
 * 
 * 
 * 分隔时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 
 * 
 * 示例 1：
 * 
 * 输入:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * 输出:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * 示例 2：
 * 
 * 输入:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * 输出:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * 解释: 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出:
 * []
 * 
 * 
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, vector<string>> m;
        return helper(m, wordDict, s);
    }
    vector<string> helper(unordered_map<string, vector<string>> &m, vector<string> &wordDict, string s)
    {
        if (m.count(s))
            return m[s];
        if (s.empty())
            return {""};
        vector<string> res;
        for (auto word : wordDict)
        {
            if (s.substr(0, word.size()) != word)
                continue;
            vector<string> tmp = helper(m, wordDict, s.substr(word.size()));
            for (auto itm : tmp)
            {
                res.push_back(word + (itm.empty() ? "" : " " + itm));
            }
        }
        m[s] = res;
        return res;
    }
};
// @lc code=end
