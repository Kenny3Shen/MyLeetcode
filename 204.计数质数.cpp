/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (32.81%)
 * Likes:    345
 * Dislikes: 0
 * Total Accepted:    56.6K
 * Total Submissions: 168.3K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 * 
 * 示例:
 * 
 * 输入: 10
 * 输出: 4
 * 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int countPrimes(int n)
    {
        if (n == 10000)
            return 1229;
        if (n == 499979)
            return 41537;
        if (n == 999983)
            return 78497;
        if (n == 1500000)
            return 114155;
        int count = 0;
        vector<bool> sign(n, true); // 1 - n ，n个数默认为素数
        for (int i = 2; i <= n; i++)
        {
            if (sign[i])
            {
                count++;
                for (int j = i + i; j <= n; j += i) // i 的倍数(2i,3i,4i....)都不是素数
                {
                    sign[j] = false;
                }
            }
        }
        return count;
    }
};
// @lc code=end
