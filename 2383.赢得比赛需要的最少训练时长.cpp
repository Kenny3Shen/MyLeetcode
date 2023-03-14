/*
 * @lc app=leetcode.cn id=2383 lang=cpp
 *
 * [2383] 赢得比赛需要的最少训练时长
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
    {
        int allEnergy = accumulate(energy.begin(), energy.end(), 0);
        int res = initialEnergy > allEnergy ? 0 : allEnergy + 1 - initialEnergy;
        for (int exp : experience)
        {
            if (initialExperience <= exp)
            {
                res += exp - initialExperience + 1;
                initialExperience = exp + 1;
            }
            initialExperience += exp;
        }
        return res;
    }
};
// @lc code=end
