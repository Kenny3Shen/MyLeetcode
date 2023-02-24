/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (32.34%)
 * Likes:    2916
 * Dislikes: 0
 * Total Accepted:    420.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isPalindrome(const string &s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
            if (s[i++] != s[j++])
                return false;
        return true;
    }
    string longestPalindrome(string s)
    {
        vector<string> dp(s.size());
        dp[0] = s[0];
        for (int i = 1; i < s.size(); i++)
        {
            dp[i] = dp[i - 1];
            for (int j = 0; j < i; j++)
            {
                int length = i - j + 1;
                if (length <= dp[i].size())
                    break;
                string sub = s.substr(j);
                if (isPalindrome(sub))
                {
                    dp[i] = sub;
                    break;
                }
            }
        }
        for(auto i : dp)
            cout << i.second << ' ';
        return dp.back().second;
    }
};
// @lc code=end
