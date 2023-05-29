/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), [](auto const &a, auto const &b) {
            return a[1] < b[1];
        });
        int count = 1;             // 记录非交叉区间的个数
        int end = intervals[0][1]; // 记录区间分割点
        for (int i = 1; i < intervals.size(); i++)
        {
            if (end <= intervals[i][0])
            {
                end = intervals[i][1];
                count++;
            }
        }
        return intervals.size() - count;
    }
};
// @lc code=end
//按照右边界排序，从左向右记录非交叉区间的个数
//最后用区间总数减去非交叉区间的个数就是需要移除的区间个数了