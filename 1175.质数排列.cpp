/*
 * @lc app=leetcode.cn id=1175 lang=cpp
 *
 * [1175] 质数排列
 *
 * https://leetcode-cn.com/problems/prime-arrangements/description/
 *
 * algorithms
 * Easy (47.50%)
 * Likes:    22
 * Dislikes: 0
 * Total Accepted:    4.9K
 * Total Submissions: 10.3K
 * Testcase Example:  '5'
 *
 * 请你帮忙给从 1 到 n 的数设计排列方案，使得所有的「质数」都应该被放在「质数索引」（索引从 1 开始）上；你需要返回可能的方案总数。
 * 
 * 让我们一起来回顾一下「质数」：质数一定是大于 1 的，并且不能用两个小于它的正整数的乘积来表示。
 * 
 * 由于答案可能会很大，所以请你返回答案 模 mod 10^9 + 7 之后的结果即可。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 5
 * 输出：12
 * 解释：举个例子，[1,2,5,4,3] 是一个有效的排列，但 [5,2,3,4,1] 不是，因为在第二种情况里质数 5 被错误地放在索引为 1
 * 的位置上。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 100
 * 输出：682289015
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 100
 * 
 * 
 */
#include <vector>
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long factorial(int n)
    {
        long long fact = 1;
        for (int i = 1; i <= n; i++)
        {
            fact *= i;
            fact %= (long long)(1e9 + 7);
        }
        return fact;
    }

    int numPrimeArrangements(int n)
    {
        vector<bool> isPrime(n + 1, true);
        for (int i = 2; i * i <= n; i++)
        {
            if (isPrime[i])
            {
                for (int j = i + i; j <= n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
        int numPrime = 0;
        for (int i = 2; i <= n; i++)
            if (isPrime[i])
                numPrime++;

        int notPrime = n - numPrime;
        //排列组合 质数的全排列 * 非质数的全排列 = Amm * A(n-m)(n-m)
        return (int)((factorial(numPrime) * factorial(notPrime) % (long long)(1e9 + 7)));
        //(a ∗ b) % c = ((a % c) ∗ (b % c)) % c
    }
};
// @lc code=end
