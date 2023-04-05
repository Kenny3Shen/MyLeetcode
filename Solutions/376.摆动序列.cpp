/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int curDiff = 0; //默认第一个峰值差为0
        int preDiff = 0;
        int res = 1; //默认最右端有一个峰值
        for (int i = 1; i < nums.size(); i++)
        {
            curDiff = nums[i] - nums[i - 1];
            if ((curDiff > 0 && preDiff <= 0) || (curDiff < 0 && preDiff >= 0))
            {
                preDiff = curDiff;
                res++;
            }
        }
        return res;
    }
};
//可以针对序列[2,5]，可以假设为[2,2,5]，这样它就有坡度了即 preDiff = 0
// @lc code=end
