/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有K个重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (46.02%)
 * Likes:    349
 * Dislikes: 0
 * Total Accepted:    26K
 * Total Submissions: 53.4K
 * Testcase Example:  '"aaabb"\n3'
 *
 * 给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aaabb", k = 3
 * 输出：3
 * 解释：最长子串为 "aaa" ，其中 'a' 重复了 3 次。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "ababbc", k = 2
 * 输出：5
 * 解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由小写英文字母组成
 * 1 
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        if (s.size() < k)
            return 0;
        unordered_set<char> chars(s.begin(), s.end());
        unordered_map<char, int> counter;
        for (char c : s)
            counter[c]++;
        for (char c : chars)
        {
            vector<string> t;
            if (counter[c] < k)
            {
                split(s, t, c);
                int res = 0;
                for (string tn : t)
                {
                    res = max(res, longestSubstring(tn, k));
                }
                return res;
            }
        }
        return s.size();
    }
    void split(const string &s, vector<string> &sv, const char flag = ' ')
    {
        sv.clear();
        istringstream iss(s);
        string temp;

        while (getline(iss, temp, flag))
        {
            sv.push_back(temp);
        }
    }
};
// @lc code=end
