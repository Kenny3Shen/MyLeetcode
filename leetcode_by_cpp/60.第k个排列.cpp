/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 *
 * https://leetcode-cn.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (49.07%)
 * Likes:    314
 * Dislikes: 0
 * Total Accepted:    45.3K
 * Total Submissions: 92.3K
 * Testcase Example:  '3\n3'
 *
 * 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
 * 
 * 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * 给定 n 和 k，返回第 k 个排列。
 * 
 * 说明：
 * 
 * 
 * 给定 n 的范围是 [1, 9]。
 * 给定 k 的范围是[1,  n!]。
 * 
 * 
 * 示例 1:
 * 
 * 输入: n = 3, k = 3
 * 输出: "213"
 * 
 * 
 * 示例 2:
 * 
 * 输入: n = 4, k = 9
 * 输出: "2314"
 * 
 * 
 */
#include <string>
#include <vector>
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    int factorial(int n)
    {
        int re = 1;
        for (int i = 2; i <= n; i++)
            re *= i;
        return re;
    }
    string getPermutation(int n, int k)
    {
        string res;
        string s = string("123456789").substr(0, n);
        --k; //边界处理   
        while (n)
        {
            int fac = factorial(n - 1);
            int i = k / fac;
            res.push_back(s[i]);
            s.erase(s.begin() + i);
            k %= fac;
            --n;
        }
        return res;
    }
};
// @lc code=end
