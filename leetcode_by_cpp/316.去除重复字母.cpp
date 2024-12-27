/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        string res = "";
        int lastIndex[26] = {0};
        bool resUsed[26] = {false};
        for (int i = 0; i < s.size(); i++)
            lastIndex[s[i] - 'a'] = i; //记录s[i]的最后出现位置

        for (int i = 0; i < s.size(); i++)
        {
            if (resUsed[s[i] - 'a'] == true) //重复出现
                continue;
            else
            {
                while (!res.empty() && res.back() > s[i] && lastIndex[res.back() - 'a'] > i)
                {
                    //栈顶元素在 i后还会出现，修改栈顶元素的使用状态为 false并出栈
                    resUsed[res.back() - 'a'] = false;
                    res.pop_back();
                }
                res.push_back(s[i]);
                resUsed[s[i] - 'a'] = true;
            }
        }
        return res;
    }
};
// @lc code=end
