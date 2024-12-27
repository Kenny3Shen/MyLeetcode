/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
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
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;
        int ans = 0;
        vector<int> line(matrix[0].size() + 2, 0); //设置头尾哨兵
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                matrix[i][j] == '0' ? line[j + 1] = 0 : line[j + 1]++; //求此行的柱形图
            }
            ans = max(ans, largestRectangleArea(line));
        }
        return ans;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        int res = 0;
        vector<int> st;
        //heights.insert(heights.begin(), 0); //头哨兵第一个单调栈的左边界
        //heights.push_back(0);               //尾哨兵做最后一个单调栈的右边界
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
};

/* 1、如果只有一行，把每个格子中的数据看成是高度，那么就是 [84. 柱状图中最大的矩形]
2、如果只有两行，我想得到第二行中所有数据的高度
第二行中数据是 1 ，如果上面第一行也是 1 ，高度就是 2 ，否则是 1
第二行中数据是 0 ，那么不管第一行是什么，高度都是 0
3、因此，遍历每一行时，都能够得到以这一行为底的带高度的数组
4、将其代入 【柱状图中最大的矩形】单调栈入门，使用单调栈快速寻找边界 的代码中进行计算，手动狗头
5、记录最大值得到答案
 */

// @lc code=end
