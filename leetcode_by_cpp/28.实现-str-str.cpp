/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (39.61%)
 * Likes:    391
 * Dislikes: 0
 * Total Accepted:    145.1K
 * Total Submissions: 365.9K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    void getNext(int *next, const string &s)
    {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++)
        {
            while (j > 0 && s[i] != s[j]) // j要保证大于0，因为下面有取j-1作为数组下表的操作
                j = next[j - 1];          //从j-1对应的回退值开始回退

            if (s[i] == s[j])
                j++;

            next[i] = j;
        }
    }
    int strStr(string haystack, string needle)
    {
        //---------KMP_Algorithm
        if (needle.size() == 0)
            return 0;

        int next[needle.size()];
        getNext(next, needle);
        int i = 0, j = 0;
        for (i = 0; i < haystack.size(); i++)
        {
            while (j > 0 && haystack[i] != needle[j])
                j = next[j - 1]; //不匹配，要找j前一位的对应的回退位置了

            if (haystack[i] == needle[j])
                j++;

            if (j == needle.size()) //模式串匹配完成
                break;
        }
        return j == needle.size() ? (i - needle.size() + 1) : -1; // +1是因为 最后一次循环的i++没有执行就跳出了
        
        /* if (needle.empty())
            return 0;
        //----------STL_string函数调用
        // return haystack.find(needle);
        //---------BF_Algorithm
        int i = 0, j = 0;
        while (haystack[i] && needle[j])
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                i = i - j + 1; //回到开始比较时的下一位
                j = 0;
            }
        }
        if (!needle[j]) //needle比较到'\0'，存在子串
            return i - j;
        else
            return -1; //没有比较的'\0',不存在子串 */
    }
};
// @lc code=end

/* 当 needle 是空字符串时，我们应当返回什么值？
这是一个在面试中很好的问题。
对于本题而言，当 needle 是空字符串时我们应当返回 0 。
这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。 */