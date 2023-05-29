/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (71.38%)
 * Likes:    215
 * Dislikes: 0
 * Total Accepted:    71.1K
 * Total Submissions: 99.5K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "Let's take LeetCode contest"
 * 输出: "s'teL ekat edoCteeL tsetnoc" 
 * 
 * 
 * 注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
 * 
 */

// @lc code=start
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        if (!s.size())
            return "";
        string res;
        istringstream ss(s);
        string word;
        while (ss >> word)
        {
            reverse(word.begin(), word.end());
            /* int left = 0, right = word.size() - 1;
            while(left < right)
                swap(word[left++],word[right--]); */
            res += word + ' ';
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end
