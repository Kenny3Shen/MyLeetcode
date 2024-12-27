/*
 * @lc app=leetcode.cn id=2549 lang=cpp
 *
 * [2549] 统计桌面上的不同数字
 */

// @lc code=start
class Solution
{
public:
    int distinctIntegers(int n)
    {
        //n-1 一定满足 n % n - 1 = 1, 足够长时间后[2, n-1]一定满足
        return n == 1 ? 1 : n - 1;
    }
};
// @lc code=end
