/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 *
 * https://leetcode-cn.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (38.03%)
 * Likes:    280
 * Dislikes: 0
 * Total Accepted:    45.4K
 * Total Submissions: 115.1K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * 给出一个无重叠的 ，按照区间起始端点排序的区间列表。
 * 
 * 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
 * 输出：[[1,5],[6,9]]
 * 
 * 
 * 示例 2：
 * 
 * 输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * 输出：[[1,2],[3,10],[12,16]]
 * 解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
 * 
 * 
 * 
 * 
 * 注意：输入类型已在 2019 年 4 月 15 日更改。请重置为默认代码定义以获取新的方法签名。
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> result;
        int index = 0;
        while (index < intervals.size() && intervals[index][1] < newInterval[0]) //找到第一个应插入的区间
            result.push_back(intervals[index++]); 

        while (index < intervals.size() && intervals[index][0] <= newInterval[1])//合并区间,等于  时也应该并入这个区间
        {
            newInterval[0] = min(intervals[index][0],newInterval[0]);
            newInterval[1] = max(intervals[index][1],newInterval[1]);
            index++;
        }
        result.push_back(newInterval);  //合并后区间加入最终答案

        while (index < intervals.size())    //剩余区间加入答案
            result.push_back(intervals[index++]); 
            
        return result;
    }
};
// @lc code=end
