/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode.cn/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (61.98%)
 * Likes:    3785
 * Dislikes: 0
 * Total Accepted:    569.1K
 * Total Submissions: 918.2K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
 *
 *
 * 示例 2：
 *
 *
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 *
 *
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        stack<int> st;
        int res = 0;
        for(int i = 0; i < height.size(); i++)
        {
            while(!st.empty() && height[st.top()] < height[i])
            {
                int cur = st.top();
                st.pop();
                if(st.empty())
                    break;
                int l = st.top();
                int r = i;
                int length = r - l - 1;
                int h = min(height[r], height[l]) - height[cur];
                res += length * h;
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end
