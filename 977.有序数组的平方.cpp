/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 *
 * https://leetcode-cn.com/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (71.42%)
 * Likes:    114
 * Dislikes: 0
 * Total Accepted:    42.4K
 * Total Submissions: 59.4K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * 给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 * 
 * 
 * 示例 2：
 * 
 * 输入：[-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 10000
 * -10000 <= A[i] <= 10000
 * A 已按非递减顺序排序。
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        // 两端元素的平方必然是最大的
        int left = 0, right = A.size() - 1;
        vector<int> res(A.size(), 0);
        int pos = res.size() - 1;
        while (left <= right)
        {
            int L2 = A[left] * A[left];
            int R2 = A[right] * A[right];
            if (L2 < R2)
            {
                res[pos] = R2;
                right--;
            }
            else
            {
                res[pos] = L2;
                left++;
            }
            pos--;
        }
        return res;
    }
};
// @lc code=end
