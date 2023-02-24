/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (42.86%)
 * Likes:    179
 * Dislikes: 0
 * Total Accepted:    98.2K
 * Total Submissions: 226.4K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
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
    bool isPalindrome(string s)
    {
        if (s.empty())
            return true;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        //对字符串遍历，大写字母转小写字母，（toupper为小写转大写）
        int i = 0;
        int j = s.length() - 1;
        while (i < j)
        {
            if (!isalnum(s[i]))
                i++;
            else if (!isalnum(s[j]))
                j--;
            else if (s[i] != s[j])
                return false;
            else
                i++, j--;
        }
        return true;
    }
    //isalpha()用来判断一个字符是否为字母，如果是字符则返回非零，否则返回零。
    //isalnum()用来判断一个字符是否为数字或者字母，也就是说判断一个字符是否属于a~z||A~Z||0~9。
    //islower()用来判断一个字符是否为小写字母，也就是是否属于a~z。
    //isupper()和islower相反，用来判断一个字符是否为大写字母。
};
// @lc code=end
