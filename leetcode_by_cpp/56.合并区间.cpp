/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
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
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;
        if (intervals.size() == 0)
            return result;
        // 排序的参数使用了lambda表达式
        sort(intervals.begin(), intervals.end(), [](auto const &a, auto const &b) {
            return a[0] < b[0];
        });
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (result.back()[1] >= intervals[i][0])
            { // 合并区间
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        return result;

        /* vector<vector<int>> result;
        if (intervals.size() == 0)
            return result;
        sort(intervals.begin(), intervals.end());
        bool flag = false; // 标记最后一个区间有没有合并
        int length = intervals.size();

        for (int i = 1; i < length; i++)
        {
            int start = intervals[i - 1][0]; // 初始为i-1区间的左边界
            int end = intervals[i - 1][1];   // 初始i-1区间的右边界
            while (i < length && intervals[i][0] <= end)
            {                                    // 合并区间
                end = max(end, intervals[i][1]); // 不断更新右区间
                if (i == length - 1)
                    flag = true; // 最后一个区间也合并了
                i++;             // 继续合并下一个区间
            }
            // start和end是表示intervals[i - 1]的左边界右边界，所以最优intervals[i]区间是否合并了要标记一下
            result.push_back({start, end});
        }
        // 如果最后一个区间没有合并，将其加入result
        if (flag == false)
        {
            result.push_back({intervals[length - 1][0], intervals[length - 1][1]});
        }
        return result; */
    }
};
// @lc code=end
