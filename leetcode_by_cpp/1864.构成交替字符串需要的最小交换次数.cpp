/*
 * @lc app=leetcode.cn id=1864 lang=cpp
 *
 * [1864] 构成交替字符串需要的最小交换次数
 *
 * https://leetcode.cn/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/description/
 *
 * algorithms
 * Medium (40.77%)
 * Likes:    31
 * Dislikes: 0
 * Total Accepted:    7K
 * Total Submissions: 17.1K
 * Testcase Example:  '"111000"'
 *
 * 给你一个二进制字符串 s ，现需要将其转化为一个 交替字符串 。请你计算并返回转化所需的 最小 字符交换次数，如果无法完成转化，返回 -1 。
 *
 * 交替字符串 是指：相邻字符之间不存在相等情况的字符串。例如，字符串 "010" 和 "1010" 属于交替字符串，但 "0100" 不是。
 *
 * 任意两个字符都可以进行交换，不必相邻 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "111000"
 * 输出：1
 * 解释：交换位置 1 和 4："111000" -> "101010" ，字符串变为交替字符串。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "010"
 * 输出：0
 * 解释：字符串已经是交替字符串了，不需要交换。
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "1110"
 * 输出：-1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s[i] 的值为 '0' 或 '1'
 *
 *
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int minSwaps(string s)
    {
        int res = -1;
        int n = s.size();
        int num0{}, num1{}, odd0{}, odd1{};
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            if (c == '0')
            {
                num0++;
                odd0 += i & 1;
            }
            else
            {
                num1++;
                odd1 += i & 1;
            }
        }
        if (abs(num1 - num0) > 1)
            return res;
        // n 为奇数时
        // 0 比 1 多(010)，则 0 需要在偶数位，1 需要在奇数位，则交换次数为odd0
        // 1 比 0 多(101)，则 1 需要在偶数位，0 需要在奇数位，则交换次数为odd1
        // n 为偶数时
        // 1 开头(1010)，那么奇数位置都应该为 0 ，那么奇数位置为 1 的次数(odd1) 就是要交换的次数
        // 0 开头(0101)，那么奇数位置都应该为 1 ，那么奇数位置为 0 的次数(odd0) 就是要交换的次数
        if (n & 1)
        {
            res = num0 > num1 ? odd0 : odd1;
        }
        else
        {
            res = min(odd1, odd0);
        }
        return res;
    }
};
// @lc code=end
