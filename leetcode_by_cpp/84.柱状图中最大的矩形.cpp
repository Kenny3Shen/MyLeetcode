/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
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
    int largestRectangleArea(vector<int> &heights)
    {
        //暴力O(n^2) --> TLE
        /* {
            if (heights.empty())
                return 0;
            int res = 0;
            for (int i = 0; i < heights.size(); i++)
            {
                int width = 1;
                int curHeight = heights[i];
                int left = i - 1, right = i + 1;

                //以当前高度为宽度(heights[i] >= curHeight)，向左寻找最长长度
                while (left >= 0 && heights[left--] >= curHeight)
                    width++;
                //以当前高度为宽度(heights[i] >= curHeight)，向右寻找最长长度
                while (right < heights.size() && heights[right++] >= curHeight)
                    width++;

                res = max(res, width * curHeight);
            }
            return res;
        } */
        //单调栈 + 哨兵
        {
            if (heights.empty())
                return 0;
            int res = 0;
            vector<int> st;
            heights.insert(heights.begin(), 0); //头哨兵第一个单调栈的左边界
            heights.push_back(0);               //尾哨兵做最后一个单调栈的右边界
            for (int i = 0; i < heights.size(); i++)
            {
                while (!st.empty() && heights[st.back()] > heights[i]) //右边界 i找到
                {
                    int right = i - 1;                  //右边界为 i - 1, 左闭右闭
                    int curHeight = heights[st.back()]; //右边界向左边界递减
                    st.pop_back();
                    int left = st.back() + 1; // 左边界为堆栈中cur的上个数加1，因为栈的下标不一定连续
                    res = max(res, (right - left + 1) * curHeight);
                }
                st.push_back(i);
            }
            return res;
        }
    }
};
// @lc code=end
