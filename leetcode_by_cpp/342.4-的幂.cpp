/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 *
 * https://leetcode-cn.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (48.89%)
 * Likes:    115
 * Dislikes: 0
 * Total Accepted:    25.9K
 * Total Submissions: 52.9K
 * Testcase Example:  '16'
 *
 * 给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 16
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: false
 * 
 * 进阶：
 * 你能不使用循环或者递归来完成本题吗？
 * 
 */

// @lc code=start
#include <math.h>
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <=0)
            return false;
        // log(4^n) = n*log(4)
        int n = log(num) / log(4);
        return log(num) == n* log(4);
    }
};
// @lc code=end

