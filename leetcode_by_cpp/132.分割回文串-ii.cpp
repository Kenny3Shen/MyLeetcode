/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (44.95%)
 * Likes:    331
 * Dislikes: 0
 * Total Accepted:    31.3K
 * Total Submissions: 66.4K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。
 * 
 * 返回符合要求的 最少分割次数 。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aab"
 * 输出：1
 * 解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a"
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "ab"
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由小写英文字母组成
 * 
 * 
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int minCut(string s)
    {
        vector<vector<bool>> isPalindromic(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] == s[j] && (j - i <= 1 || isPalindromic[i + 1][j - 1]))
                {
                    isPalindromic[i][j] = true;
                }
            }
        }
        // 初始化
        vector<int> dp(s.size() + 1, 0);
        for (int i = 0; i < s.size(); i++)
            dp[i] = i;

        for (int i = 1; i < s.size(); i++)
        {
            if (isPalindromic[0][i])
            {
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j++)
            {
                if (isPalindromic[j + 1][i])
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[s.size() - 1];
    }
};
// @lc code=end
