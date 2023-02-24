/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (36.54%)
 * Likes:    911
 * Dislikes: 0
 * Total Accepted:    205.8K
 * Total Submissions: 563.1K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

// @lc code=start
#include <vector>
#include <list>
#include <string>
#include <map>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (!strs.size()) //返回向量大小
            return "";
        int min_length = strs[0].size();
        string str = "";
        for (int i = 1; i < strs.size(); i++)
        //求最短的字符串，既求最大比较次数
        {
            if (min_length > strs[i].size())
                min_length = strs[i].size();
        }
        for (int i = 0; i < min_length; i++) //从第一个string的第一个字符开始比较
        {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) //第一个string与其余的string第i个字符逐次比较
            {
                if (c != strs[j][i])
                    return str;
            }
            str += c;
        }
        return str;
    }
};
// @lc code=end
//https://blog.csdn.net/msdnwolaile/article/details/52708144?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task
