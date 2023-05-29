/*
 * @lc app=leetcode.cn id=970 lang=cpp
 *
 * [970] 强整数
 */
#include <vector>
#include <unordered_set>
#include <math.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    void TotalPowerInterger(int x, int y, int i, int j, int x_val, int y_val,
                            const int bound, unordered_set<int> &res)
    {
        if (x_val + y_val > bound)
        {
            return;
        }
        res.insert(x_val + y_val);
        if (x != 1)
            TotalPowerInterger(x, y, i + 1, j, x_val * x, y_val, bound, res);
        if (y != 1)
            TotalPowerInterger(x, y, i, j + 1, x_val, y_val * y, bound, res);
    }
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        if (bound == 0)
            return vector<int>();

        unordered_set<int> st;
        TotalPowerInterger(x, y, 0, 0, 1, 1, bound, st);
        return vector<int>(st.begin(), st.end());
    }
};
// @lc code=end
