/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 *
 * https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/description/
 *
 * algorithms
 * Medium (54.98%)
 * Likes:    390
 * Dislikes: 0
 * Total Accepted:    53K
 * Total Submissions: 96.3K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：
 * A: [1,2,3,2,1]
 * B: [3,2,1,4,7]
 * 输出：3
 * 解释：
 * 长度最长的公共子数组是 [3, 2, 1] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= len(A), len(B) <= 1000
 * 0 <= A[i], B[i] < 100
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int findLength(vector<int> &A, vector<int> &B)
    {
        int res = 0;
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1));
        for (int i = 1; i < A.size() + 1; i++)
        {
            for (int j = 1; j < B.size() + 1; j++)
            {
                if (A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end
