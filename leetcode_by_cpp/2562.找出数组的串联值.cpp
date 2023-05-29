/*
 * @lc app=leetcode.cn id=2562 lang=cpp
 *
 * [2562] 找出数组的串联值
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    long long findTheArrayConcVal(vector<int> &nums)
    {
        long long res = 0;
        int i = 0, j = nums.size() - 1;
        while(i < j)
            res += stoll(to_string(nums[i++]) + to_string(nums[j--]));
        return i == j ? res + (long long)nums[i] : res;
    }
};
// @lc code=end
