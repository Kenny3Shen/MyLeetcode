/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (50.46%)
 * Likes:    112
 * Dislikes: 0
 * Total Accepted:    45.2K
 * Total Submissions: 89.3K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："hello"
 * 输出："holle"
 * 
 * 
 * 示例 2：
 * 
 * 输入："leetcode"
 * 输出："leotcede"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 元音字母不包含字母 "y" 。
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseVowels(string s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            if ((s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u' || 
            s[left] == 'A' || s[left] == 'E' || s[left] == 'I' || s[left] == 'O' || s[left] == 'U') 
            && (s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u' 
            || s[right] == 'A' || s[right] == 'E' || s[right] == 'I' || s[right] == 'O' || s[right] == 'U'))
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            else if ((s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u' 
            || s[left] == 'A' || s[left] == 'E' || s[left] == 'I' || s[left] == 'O' || s[left] == 'U') 
            && (s[right] != 'a' || s[right] != 'e' || s[right] != 'i' || s[right] != 'o' || s[right] != 'u' 
            || s[right] != 'A' || s[right] != 'E' || s[right] != 'I' || s[right] != 'O' || s[right] != 'U'))
                right--;
            else if ((s[left] != 'a' || s[left] != 'e' || s[left] != 'i' || s[left] != 'o' || s[left] != 'u' || 
            s[left] != 'A' || s[left] != 'E' || s[left] != 'I' || s[left] != 'O' || s[left] != 'U') 
            && (s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u' 
            || s[right] == 'A' || s[right] == 'E' || s[right] == 'I' || s[right] == 'O' || s[right] == 'U'))
                left++;
            else
            {
                left++;
                right--;
            }
        }
        return s;
    }
};
// @lc code=end
