/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.68%)
 * Likes:    180
 * Dislikes: 0
 * Total Accepted:    74.8K
 * Total Submissions: 228.8K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
 * 
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: "Hello World"
 * 输出: 5
 * 
 * 
 */

// @lc code=start
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = 0;
        if (s == " ") //字符串只有一个' '字符we
            return 0;
        while (s[s.size() - 1] == ' ') //清除末尾的' '字符
            s.erase(s.size() - 1);  //trim函数可以清除字符串首尾的空格既制表符
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
                count++;
            else //重置
                count = 0;
        }
        return count;
    }
};
// @lc code=end
