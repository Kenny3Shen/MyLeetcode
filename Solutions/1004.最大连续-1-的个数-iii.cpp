/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 *
 * https://leetcode-cn.com/problems/max-consecutive-ones-iii/description/
 *
 * algorithms
 * Medium (56.23%)
 * Likes:    153
 * Dislikes: 0
 * Total Accepted:    21.6K
 * Total Submissions: 38.2K
 * Testcase Example:  '[1,1,1,0,0,0,1,1,1,1,0]\n2'
 *
 * 给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。
 * 
 * 返回仅包含 1 的最长（连续）子数组的长度。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
 * 输出：6
 * 解释： 
 * [1,1,1,0,0,1,1,1,1,1,1]
 * 粗体数字从 0 翻转到 1，最长的子数组长度为 6。
 * 
 * 示例 2：
 * 
 * 输入：A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
 * 输出：10
 * 解释：
 * [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
 * 粗体数字从 0 翻转到 1，最长的子数组长度为 10。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 20000
 * 0 <= K <= A.length
 * A[i] 为 0 或 1 
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestOnes(vector<int> &A, int K)
    {
        int curZero = 0;
        int res = 0;
        int i = 0, j = 0;
        while (j < A.size())
        {
            if (A[j] == 1)
                j++;
            else
            {
                if (curZero != K)
                {
                    j++;
                    curZero++;
                }
                else
                {
                    res = max(res, j - i);
                    while (A[i] == 1) //找到当前窗口的第一个 0
                        i++;
                    i++; //左边界收缩到第一个 0 的下一个,此时当前A[j]可置 1
                    j++; //A[j]置为 1 后窗口可右移
                }
            }
        }
        res = max(res, j - i);
        return res;
    }
};
// @lc code=end
