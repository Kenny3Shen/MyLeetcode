/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 *
 * https://leetcode-cn.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (36.13%)
 * Likes:    56
 * Dislikes: 0
 * Total Accepted:    21.4K
 * Total Submissions: 59.3K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
 * 
 * 请注意，你可以假定字符串里不包括任何不可打印的字符。
 * 
 * 示例:
 * 
 * 输入: "Hello, my name is John"
 * 输出: 5
 * 解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。
 * 
 * 
 */
#include <sstream>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        int res = 0;
        while(ss >> s)
        {
            res++;
        }
        return res;
    }
};
// @lc code=end

