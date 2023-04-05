/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (70.43%)
 * Likes:    513
 * Dislikes: 0
 * Total Accepted:    66.5K
 * Total Submissions: 94.2K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 * 
 * 返回 s 所有可能的分割方案。
 * 
 * 示例:
 * 
 * 输入: "aab"
 * 输出:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
private:
    vector<vector<string>> result;
    vector<string> path; // 放已经回文的子串
    void backtracking(const string &s, int startIndex)
    {
        // 如果起始位置已经大于s的大小，说明已经找到了一组分割方案了
        if (startIndex >= s.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            if (isPalindrome(s, startIndex, i))
            { // 是回文子串
                // 获取[startIndex,i]在s中的子串
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }
            else
            { // 不是回文，跳过
                continue;
            }
            backtracking(s, i + 1); // 寻找i+1为起始位置的子串
            path.pop_back();        // 回溯过程，弹出本次已经填在的子串
        }
    }
    bool isPalindrome(const string &s, int start, int end)
    {
        while (start < end)
            if (s[start++] != s[end--])
                return false;

        return true;
    }

public:
    vector<vector<string>> partition(string s)
    {
        backtracking(s, 0);
        return result;
    }
};

// @lc code=end
