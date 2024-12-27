/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 */
#include <string>
#include <deque>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool rotateString(string A, string B)
    {
        return A.size() == B.size() && (A + A).find(B) != string::npos; //循环字符串
    }
};
// @lc code=end
