/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 *
 * https://leetcode-cn.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (39.85%)
 * Likes:    267
 * Dislikes: 0
 * Total Accepted:    35.1K
 * Total Submissions: 87.4K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，返回 n! 结果尾数中零的数量。
 * 
 * 示例 1:
 * 
 * 输入: 3
 * 输出: 0
 * 解释: 3! = 6, 尾数中没有零。
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: 1
 * 解释: 5! = 120, 尾数中有 1 个零.
 * 
 * 说明: 你算法的时间复杂度应为 O(log n) 。
 * 
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        //即求有 1~n 中每个数的因子中 2 和 5 的个数
        //2的个数是远多于5的，求5的个数即可
        int countZero = 0;
        while(n)
        {
            countZero += n / 5;
            n /= 5;
        }
        return countZero;
        // 对 100! ，1~100中有 20 个被 5 整除的数
        // 这 20 个数中，每隔 5 个，既有 4 个可以被 25 整除
        //  
    }
};
// @lc code=end

