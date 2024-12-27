/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        /* sort(nums.begin(), nums.end());
        int size = nums.size();
        int preTwoTimesLast = nums[0] * nums[1] * nums[size - 1];
        int lastThree = nums[size - 1] * nums[size - 2] * nums[size - 3];
        return preTwoTimesLast > lastThree ? preTwoTimesLast : lastThree; */

        int min1st = __INT_MAX__, min2nd = __INT_MAX__;
        int max1st = INT_MIN, max2nd = INT_MIN, max3rd = INT_MIN;
        for (auto const &n : nums)
        {
            if (n >= max1st)
            {
                max3rd = max2nd;
                max2nd = max1st;
                max1st = n;
            }
            else if (max1st > n && n >= max2nd)
            {
                max3rd = max2nd;
                max2nd = n;
            }
            else if (max2nd > n && n >= max3rd)
                max3rd = n;
            if (n <= min1st)
            {
                min2nd = min1st;
                min1st = n;
            }
            else if (min1st < n && n <= min2nd)
                min2nd = n;
        }
        int maxThree = max1st * max2nd * max3rd;
        int minTwoTimesMax1st = max1st * min1st * min2nd;
        return max(maxThree, minTwoTimesMax1st);
    }
};
// @lc code=end
