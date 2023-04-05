/*
 * @lc app=leetcode.cn id=1952 lang=cpp
 *
 * [1952] 三除数
 *
 * https://leetcode-cn.com/problems/three-divisors/description/
 *
 * algorithms
 * Easy (54.45%)
 * Likes:    18
 * Dislikes: 0
 * Total Accepted:    10.5K
 * Total Submissions: 19.2K
 * Testcase Example:  '2'
 *
 * 给你一个整数 n 。如果 n 恰好有三个正除数 ，返回 true ；否则，返回 false 。
 * 
 * 如果存在整数 k ，满足 n = k * m ，那么整数 m 就是 n 的一个 除数 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 2
 * 输出：false
 * 解释：2 只有两个除数：1 和 2 。
 * 
 * 示例 2：
 * 
 * 输入：n = 4
 * 输出：true
 * 解释：4 有三个除数：1、2 和 4 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^4
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    bool isThree(int n) 
    {
        if (n <= 3)
            return false;
        int res = 2;
        for(int i = 2; i < n; i++)
        {
            if(n % i == 0)
                res++;
            if(res > 3)
                break;
        }
        return res == 3 ? true : false;
    }
};
// @lc code=end

