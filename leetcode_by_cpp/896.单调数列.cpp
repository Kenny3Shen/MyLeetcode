/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isMonotonic(vector<int> &A)
    {
        int sign = 0;
        int i = 0;
        for (i = 1; i < A.size(); i++)
        {
            if (A[i] - A[i - 1] == 0)
                continue;
            else
            {
                sign = (A[i] - A[i - 1]) >> 31;
                break;
            }
        }
        for (int j = i + 1; j < A.size(); j++)
        {
            if (A[j] - A[j - 1] == 0)
                continue;
            else
            {
                if ((A[j] - A[j - 1]) >> 31 != sign)
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
