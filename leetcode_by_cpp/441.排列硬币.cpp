/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 *
 * https://leetcode-cn.com/problems/arranging-coins/description/
 *
 * algorithms
 * Easy (41.30%)
 * Likes:    73
 * Dislikes: 0
 * Total Accepted:    27.9K
 * Total Submissions: 67.5K
 * Testcase Example:  '5'
 *
 * 你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。
 * 
 * 给定一个数字 n，找出可形成完整阶梯行的总行数。
 * 
 * n 是一个非负整数，并且在32位有符号整型的范围内。
 * 
 * 示例 1:
 * 
 * 
 * n = 5
 * 
 * 硬币可排列成以下几行:
 * ¤
 * ¤ ¤
 * ¤ ¤
 * 
 * 因为第三行不完整，所以返回2.
 * 
 * 
 * 示例 2:
 * 
 * 
 * n = 8
 * 
 * 硬币可排列成以下几行:
 * ¤
 * ¤ ¤
 * ¤ ¤ ¤
 * ¤ ¤
 * 
 * 因为第四行不完整，所以返回3.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int arrangeCoins(int n)
    {
        /* int low = 1;
        int high = n;
        while (low <= high)
        {
            long mid = low + (high - low) / 2;
            long sum = mid * (mid + 1) / 2;
            if (sum == n)
                return mid;
            else if (sum > n)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low - 1; */

        int i;
        for (i = 1; i <= n; i++)
            n -= i;
        return i - 1;
    }
};
// @lc code=end
