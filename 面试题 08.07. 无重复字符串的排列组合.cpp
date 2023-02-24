/* 无重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合，字符串每个字符均不相同。

示例1:

 输入：S = "qwe"
 输出：["qwe", "qew", "wqe", "weq", "ewq", "eqw"]
示例2:

 输入：S = "ab"
 输出：["ab", "ba"]
提示:

字符都是英文字母。
字符串长度在[1, 9]之间。 */

//全排列问题-----交换法
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<string> res;
    void backtrack(int begin, string &s)
    {
        if (begin == s.size())
        {
            res.push_back(s);
        }
        else
        {
            for (int i = begin; i < s.size(); i++)
            {
                swap(s[begin], s[i]);
                backtrack(begin + 1, s);
                swap(s[begin], s[i]);
            }
        }
    }
    vector<string> permutation(string S)
    {
        if (!S.size())
            return res;
        backtrack(0, S);
        return res;
    }
};
