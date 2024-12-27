/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (75.43%)
 * Likes:    1219
 * Dislikes: 0
 * Total Accepted:    160.1K
 * Total Submissions: 210.8K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：n = 3
 * 输出：[
 * ⁠      "((()))",
 * ⁠      "(()())",
 *      "(()()",
 * ⁠      ")(())",
 * ⁠      "()()()"
 * ⁠    ]
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    void dfs(vector<string> &ans,string str,int left,int right)
    {
        if(!left && !right)
            ans.push_back(str);
        if(left > 0 )
            dfs(ans,str + "(" , left - 1, right);
        if(right > left)
            dfs(ans, str + ")", left, right - 1);
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        dfs(ans, "" , n, n);
        return ans;
    }
};
// @lc code=end
           
