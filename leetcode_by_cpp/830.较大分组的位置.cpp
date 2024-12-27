/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
        vector<vector<int>> res;
        if (s.size() < 3)
            return res;
        int start = 0;
        while (start < s.size())
        {
            int end = start + 1;
            while (end < s.size() && s[end] == s[start])
                end++;
            if (end - start >= 3)
                res.push_back({start, end - 1});
            start = end;
        }
        return res;
    }
};
// @lc code=end
