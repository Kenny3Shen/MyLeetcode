/*
 * @lc app=leetcode.cn id=2248 lang=cpp
 *
 * [2248] 多个数组求交集
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<vector<int>> &nums)
    {
        int n = nums.size();
        vector<int> res;
        unordered_map<int, int> um;
        for(auto &num : nums)
            for(auto &n : num)
                um[n]++;
        for(auto &m : um)
            if(m.second == n)
                res.push_back(m.first);
        sort(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
