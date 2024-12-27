/*
 * @lc app=leetcode.cn id=2540 lang=cpp
 *
 * [2540] 最小公共值
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> s(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (auto i : nums2)
            if (s.count(i))
                return i;
        return -1;
    }
};
// @lc code=end
