// @before-stub-for-debug-begin
#include <vector>
#include <string>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 *
 * https://leetcode-cn.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (47.58%)
 * Likes:    254
 * Dislikes: 0
 * Total Accepted:    22.8K
 * Total Submissions: 47.6K
 * Testcase Example:  '"abab"'
 *
 * 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "abab"
 * 
 * 输出: True
 * 
 * 解释: 可由子字符串 "ab" 重复两次构成。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "aba"
 * 
 * 输出: False
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: "abcabcabcabc"
 * 
 * 输出: True
 * 
 * 解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
 * 
 * 
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void getNext(vector<int> &next, const string &s)
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
    bool repeatedSubstringPattern(string s)
    {
        if (s.empty())
            return false;

        vector<int> next(s.size(), 0);
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != 0 && len % (len - (next[len - 1])) == 0)
            return true;
        //如果 next[len - 1] != 0，则说明字符串有最长相同的前后缀（就是字符串里的前缀子串和后缀子串相同的最长长度）。
        //说明 (数组长度-最长相等前后缀的长度) 正好可以被 数组的长度整除，说明有该字符串有重复的子字符串。
        return false;
        //return (s + s).find(s, 1) != s.size();
        // ==s.size()说明不存在子字符串，因为下标到结尾即为 s

        /* string str = s + s;
        str = str.substr(1, str.size() - 2);
        if (str.find(s) == -1)
            return false;
        return true; */
    }
};

/* 假设给定字符串s可由一个子串x重复n次构成，即s=nx。
现构造新字符串t=2s，即两个s相加，由于s=nx，则t=2nx。
去掉t的开头与结尾两位，则这两处的子串被破坏掉，此时t中包含2n-2个子串。
由于t中包含2n-2个子串，s中包含n个子串，若t中包含s，则有2n-2>=n，可得n>=2，
由此我们可知字符串s可由一个子串x重复至少2次构成，判定为true；
反之，若t中不包含s，则有2n-2<n，可得n<2，n只能为1，
由此我们可知字符串s=x，假定的子串就为s本身，判定为false。 */
// @lc code=end
