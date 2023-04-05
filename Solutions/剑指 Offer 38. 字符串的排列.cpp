/* 输入一个字符串，打印出该字符串中字符的所有排列。

 

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

 

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"] */
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> res;
    bool isOccured(string &s, int start, int end)
    {
        for (int i = start; i < end; i++)
        {
            if (s[i] == s[end])
                return true;
        }
        return false;
    }
    void backtrack(string &s, int start)
    {
        if (start == s.size())
            res.push_back(s);
        else
        {
            for (int i = start; i < s.size(); i++)
            {
                if (isOccured(s, start, i)) //s[i] 在 s[start] ~ s[i - 1]出现过
                    continue;               //跳过重复项
                swap(s[i], s[start]);       //全排列问题  交换法
                backtrack(s, start + 1);
                swap(s[i], s[start]);
            }
        }
    }
    vector<string> permutation(string s)
    {
        backtrack(s, 0);
        return res;
    }
};