/*
 * @lc app=leetcode.cn id=2287 lang=cpp
 *
 * [2287] 重排字符形成目标字符串
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int rearrangeCharacters(string s, string target)
    {
        unordered_map<char, int> sCounts, targetCounts;
        int n = s.size(), m = target.size();
        for (char c : target)
            targetCounts[c]++;
        for (int i = 0; i < n; i++)
            if (targetCounts.count(s[i])) 
                sCounts[s[i]]++;
        int res = INT_MAX;
        for (auto &m : targetCounts)
        {
            res = min(res, sCounts[m.first] / m.second);
            if (res == 0)
                return 0;
        }
        return res;
    }
};
// @lc code=end
