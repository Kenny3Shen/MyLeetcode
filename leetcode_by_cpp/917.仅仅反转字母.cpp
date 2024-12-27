/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseOnlyLetters(string S)
    {
        int begin = 0, end = S.length() - 1;
        while (begin < end)
        {
            if (!isalpha(S[begin]))
                begin++;
            if (!isalpha(S[end]))
                end--;
            if (isalpha(S[begin]) && isalpha(S[end]))
                swap(S[begin++], S[end--]);
        }
        return S;
    }
};
// @lc code=end
