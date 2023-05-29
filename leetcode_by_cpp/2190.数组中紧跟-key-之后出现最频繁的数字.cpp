/*
 * @lc app=leetcode.cn id=2190 lang=cpp
 *
 * [2190] 数组中紧跟 key 之后出现最频繁的数字
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int mostFrequent(vector<int> &nums, int key)
    {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == key && i != nums.size() - 1)
                um[nums[i + 1]]++;
        }
        int mx = 0;
        for (auto u : um)
            mx = max(mx, u.second);
        int res = 0;
        for(auto u : um)
            if(u.second == mx)
                res = u.first;
        return res;
    }
};
// @lc code=end
