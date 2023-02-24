/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 */
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    string smallestSubsequence(string s)
    {
        string res;
        int lastIndex[26] = {0};
        bool isUsed[26] = {false};
        for (int i = 0; i < s.length(); i++)
            lastIndex[s[i] - 'a'] = i;

        for (int i = 0; i < s.length(); i++)
        {
            if (isUsed[s[i] - 'a'] == false) //该字母未出现过
            {
                while (!res.empty() && res.back() > s[i] && lastIndex[res.back() - 'a'] > i)
                {
                    isUsed[res.back() - 'a'] = false;
                    res.pop_back();
                }
                res.push_back(s[i]);
                isUsed[s[i] - 'a'] = true;
            }
        }
        return res;
    }
};
// @lc code=end
