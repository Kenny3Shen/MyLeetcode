/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 *
 * https://leetcode-cn.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (66.13%)
 * Likes:    146
 * Dislikes: 0
 * Total Accepted:    13.3K
 * Total Submissions: 20.1K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * 给定一个字符串数组 words，找到 length(word[i]) * length(word[j])
 * 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。
 * 
 * 示例 1:
 * 
 * 输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
 * 输出: 16 
 * 解释: 这两个单词为 "abcw", "xtfn"。
 * 
 * 示例 2:
 * 
 * 输入: ["a","ab","abc","d","cd","bcd","abcd"]
 * 输出: 4 
 * 解释: 这两个单词为 "ab", "cd"。
 * 
 * 示例 3:
 * 
 * 输入: ["a","aa","aaa","aaaa"]
 * 输出: 0 
 * 解释: 不存在这样的两个单词。
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        vector<int> v(words.size());
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                int t = words[i][j] - 'a';
                v[i] |= 1 << t;
            }
        }
        size_t res = 0;
        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < words.size(); j++)
                if ((v[i] & v[j]) == 0)
                    res = max(res, words[i].length() * words[j].length());

        return res;
    }
};
// @lc code=end
