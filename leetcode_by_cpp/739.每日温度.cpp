/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode-cn.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (64.35%)
 * Likes:    468
 * Dislikes: 0
 * Total Accepted:    95.2K
 * Total Submissions: 147.9K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0
 * 来代替。
 * 
 * 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4,
 * 2, 1, 1, 0, 0]。
 * 
 * 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
 * 
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        //单调递减栈
        stack<int> stack;
        for (int i = 0; i < T.size(); i++)
        {
            if (!stack.empty() && T[i] > T[stack.top()])
            {
                while (!stack.empty() && T[i] > T[stack.top()])
                {
                    T[stack.top()] = i - stack.top();
                    stack.pop();
                }
            }
            stack.push(i); //push index
        }
        while (!stack.empty())  
        {
            T[stack.top()] = 0;
            stack.pop();
        }
        return T;
    }
};
// @lc code=end
