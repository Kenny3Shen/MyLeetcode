/*
 * @lc app=leetcode.cn id=1678 lang=cpp
 *
 * [1678] 设计 Goal 解析器
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string interpret(string command)
    {
        string res;
        for (int i = 0; i < command.length(); i++)
        {
            if (command[i] == 'G')
                res += 'G';
            else
            {
                if (command[i + 1] == ')')
                {
                    i++;
                    res += 'o';
                }
                else
                {
                    i += 3;
                    res += "al";
                }
            }
        }
        return res;
    }
};
// @lc code=end
